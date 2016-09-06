/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 22:56:51 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/08/26 22:56:53 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#include <errno.h>

static void		ft_check_magic(int size, unsigned char *buf, char *file)
{
	unsigned int	magic;

	magic = COREWAR_EXEC_MAGIC;
	if (size == 0)
		ft_exit_error("Empty file : ", file);
	if (size != 4)
		ft_exit_error("Incorrect header (magic) 1: ", file);
	if (buf[0] != ((magic >> 24) & 0xff))
		ft_exit_error("Incorrect header (magic) 2: ", file);
	if (buf[1] != ((magic >> 16) & 0xff))
		ft_exit_error("Incorrect header (magic) 3: ", file);
	if (buf[2] != ((magic >> 8) & 0xff))
		ft_exit_error("Incorrect header (magic) 4: ", file);
	if (buf[3] != (magic & 0xff))
		ft_exit_error("Incorrect header (magic) 5: ", file);
}

void			ft_check_header(int fd, char *file)
{
	unsigned char	buf[HEADER_SIZE];
	int				size;

	if ((size = read(fd, buf, 4)) == -1)
		ft_exit_error("Could not read file : ", file);
	ft_check_magic(size, buf, file);
	size = read(fd, buf, PROG_NAME_LENGTH + 4);
	if (size != PROG_NAME_LENGTH + 4)
		ft_exit_error("Incorrect header : Program name too short", NULL);
	size = read(fd, buf, 4);
	if (size != 4)
		ft_exit_error("Incorrect header : Program size corrupted", NULL);
	else if (size == 4)
	{
		if (ft_get_value(buf, 4) < 0)
			ft_exit_error("Incorrect header : indicates negative size", NULL);
		else if (ft_get_value(buf, 4) > CHAMP_MAX_SIZE)
			ft_exit_error("Incorrect header : indicated size is too big", NULL);
	}
	size = read(fd, buf, COMMENT_LENGTH + 4);
	if (size != COMMENT_LENGTH + 4)
		ft_exit_error("Incorrect header : Program comment too short", NULL);
}
