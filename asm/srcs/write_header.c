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
#include "limits.h"

static void		ft_write_unsigned_int(int fd, unsigned int nb)
{
	int		oct_1;
	int		oct_2;
	int		oct_3;
	int		oct_4;

	oct_1 = (nb & 0xff000000) >> 24;
	oct_2 = (nb & 0xff0000) >> 16;
	oct_3 = (nb & 0xff00) >> 8;
	oct_4 = nb & 0xff;
	write(fd, &oct_1, 1);
	write(fd, &oct_2, 1);
	write(fd, &oct_3, 1);
	write(fd, &oct_4, 1);
}

static void		ft_write_string(int fd, char *string, int size)
{
	write(fd, string, size);
	write(fd, &"\0\0\0", 3);

}

void	ft_write_header(int fd, t_header *header)
{
	ft_write_unsigned_int(fd, header->magic);
	ft_write_string(fd, header->prog_name, PROG_NAME_LENGTH + 1);
	ft_write_unsigned_int(fd, header->prog_size);
	ft_write_string(fd, header->comment, COMMENT_LENGTH + 1);
}
