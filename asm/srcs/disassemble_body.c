/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassemble_body.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 16:17:07 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/09/08 16:17:08 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	ft_write_value(int src, int dest, int size)
{
	unsigned char	buf[size];
	int				rbyte;

	if ((rbyte = read(src, buf, size)) != size)
		ft_error(9);
	ft_putnbr_fd(ft_get_value(buf, size), dest);
}

static void		ft_write_instruction(t_op *data, unsigned char encoding, int src,
																	int dest)
{
	int		offset;

	offset = 6;
	ft_putstr_fd(data->name, dest);
	ft_putchar_fd('\t', dest);
	while ((encoding >> offset) & 0b11)
	{
		if (((encoding >> offset) & 0b11) == REG_CODE)
			ft_write_value(src, dest, 1);
		else if (((encoding >> offset) & 0b11) == DIR_CODE)
		{
			ft_putchar_fd(DIRECT_CHAR, dest);
			ft_write_value(src, dest, 2);
		}
		else if (((encoding >> offset) & 0b11) == IND_CODE)
			ft_write_value(src, dest, data->label_size);
		if ((encoding >> (offset - 2)) & 0b11)
			ft_putstr_fd(", ", dest);
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
			ft_putstr_fd(data->name, dest);
			ft_putchar_fd('\t', dest);
			ft_write_value(src, dest, data->label_size);
			ft_putchar_fd('\n', dest);
		}
	}
}
