/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 15:45:29 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/08/23 15:45:31 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		ft_write_unsigned_int(int fd, unsigned int nb)
{
	int		offset;
	int		value;

	offset = 32;
	value = 0;
	while (offset)
	{
		offset -= 8;
		value = (nb >> offset) & 0xff;
		write(fd, &value, 1);
	}
}

static void		ft_write_string(int fd, char *string, int size)
{
		write(fd, string, size);
		write(fd, &"\0\0\0", 3);
}

void	ft_write_header(int fd, t_header *header)
{
	if (fd == STDOUT)
	{
		ft_printf("SIZE    : {bold}{green}%d{eoc}\n", header->prog_size);
		ft_printf("NAME    : {bold}{green}%s{eoc}\n", header->prog_name);
		ft_printf("COMMENT : {bold}{green}%s{eoc}\n\n", header->comment);

	}
	else
	{
		ft_write_unsigned_int(fd, header->magic);
		ft_write_string(fd, header->prog_name, PROG_NAME_LENGTH + 1);
		ft_write_unsigned_int(fd, header->prog_size);
		ft_write_string(fd, header->comment, COMMENT_LENGTH + 1);
	}
}
