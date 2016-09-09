/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassemble_body.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 16:17:07 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/09/09 05:23:43 by vbaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		ft_write_value(int src, int dest, int size,
													t_bool needs_separator)
{
	unsigned char	buf[size];
	int				rbyte;

	if ((rbyte = read(src, buf, size)) != size)
		ft_error(9);
	ft_putnbr_fd(ft_get_value(buf, size), dest);
	if (needs_separator)
	{
		ft_putchar_fd(SEPARATOR_CHAR, dest);
		ft_putchar_fd(' ', dest);
	}
}

static void		ft_write_op(char *name, int fd)
{
	if (fd == STDOUT)
		ft_printf("{green}%s{eoc}", name);
	else
		ft_putstr_fd(name, fd);
	ft_putchar_fd('\t', fd);
}

static void		ft_write_instruction(t_op *data, unsigned char encoding,
												int src, int dest)
{
	int				offset;

	offset = 6;
	ft_write_op(data->name, dest);
	while ((encoding >> offset) & 0b11)
	{
		if (((encoding >> offset) & 0b11) == REG_CODE)
		{
			ft_putchar_fd('r', dest);
			ft_write_value(src, dest, 1, (encoding >> (offset - 2)) & 0b11);
		}
		else if (((encoding >> offset) & 0b11) == DIR_CODE)
		{
			ft_putchar_fd(DIRECT_CHAR, dest);
			ft_write_value(src, dest, data->label_size,
							(encoding >> (offset - 2)) & 0b11);
		}
		else if (((encoding >> offset) & 0b11) == IND_CODE)
			ft_write_value(src, dest, 2, (encoding >> (offset - 2)) & 0b11);
		offset -= 2;
	}
	ft_putchar_fd('\n', dest);
}

void			ft_disassemble_body(int src, int dest)
{
	unsigned char	buf[CHAMP_MAX_SIZE];
	int				rbyte;
	t_op			*data;
	unsigned char	encoding;

	while ((rbyte = read(src, buf, 1)) > 0)
	{
		if (!(data = ft_get_op_by_number(ft_get_value(buf, 1))))
			ft_error(9);
		if (data->has_encoding && (rbyte = read(src, buf, 1)))
		{
			if (rbyte != 1)
				ft_error(9);
			encoding = ft_get_value(buf, 1);
			ft_write_instruction(data, encoding, src, dest);
		}
		else
		{
			ft_write_op(data->name, dest);
			ft_putchar_fd('%', dest);
			ft_write_value(src, dest, data->label_size, FALSE);
			ft_putchar_fd('\n', dest);
		}
	}
}
