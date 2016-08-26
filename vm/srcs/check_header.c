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

static void		ft_check_magic(int size, unsigned char *buf, char *file)
{
	unsigned int	magic;

	magic = COREWAR_EXEC_MAGIC;
	if (size == 0)
		ft_exit_error("Empty file : ", file);
	if (size != 4)
		ft_exit_error("Incorrect header (magic)", NULL);
	if (buf[0] != ((magic >> 24) | 0xff))
		ft_exit_error("Incorrect header (magic)", NULL);
	if (buf[1] != ((magic >> 16) | 0xff))
		ft_exit_error("Incorrect header (magic)", NULL);
	if (buf[2] != ((magic >> 8) | 0xff))
		ft_exit_error("Incorrect header (magic)", NULL);
	if (buf[3] != (magic | 0xff))
		ft_exit_error("Incorrect header (magic)", NULL);
}

void			ft_check_header(int fd, char *file)
{
	unsigned char	*buf;
	int				size;

	buf = NULL;
	size = read(fd, buf, sizeof(unsigned int));
		// ft_exit_error("Could not read file.", NULL);
	if (size == 4)
		ft_check_magic(size, buf, file);

}
