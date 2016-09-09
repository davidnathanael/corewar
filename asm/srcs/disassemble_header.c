/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassemble_header.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 15:03:15 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/09/08 15:03:16 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		ft_write_size(int fd, int size)
{
	if (fd == STDOUT)
		ft_printf("\n# INDICATED SIZE : {red}%d{eoc}\n\n", size);
	else
	{
		ft_putstr_fd("\n# INDICATED SIZE : ", fd);
		ft_putnbr_fd(size, fd);
		ft_putstr_fd("\n\n", fd);
	}
}

static void		ft_write_info(int fd, char *attribute, unsigned char *value)
{
	if (fd == STDOUT)
		ft_printf("%s{red}%s{eoc}\"\n", attribute, value);
	else
	{
		ft_putstr_fd(attribute, fd);
		ft_putstr_fd((char *)value, fd);
		ft_putendl_fd("\"", fd);
	}
}

void			ft_disassemble_header(int src, int dest)
{
	unsigned char	buf[HEADER_SIZE];
	int				rbyte;
	int				size;

	if ((rbyte = read(src, buf, 4)) != 4)
		ft_error(9);
	if ((rbyte = read(src, buf, PROG_NAME_LENGTH + 4)) != PROG_NAME_LENGTH + 4)
		ft_error(9);
	ft_write_info(dest, ".name \"", buf);
	if ((rbyte = read(src, buf, 4)) != 4)
		ft_error(9);
	size = ft_get_value(buf, 4);
	if ((rbyte = read(src, buf, COMMENT_LENGTH + 4)) != COMMENT_LENGTH + 4)
		ft_error(9);
	ft_write_info(dest, ".comment \"", buf);
	ft_write_size(dest, size);
}
