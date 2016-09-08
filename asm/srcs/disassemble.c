/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassemble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 14:44:13 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/09/08 14:44:13 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char		*ft_get_new_file(char *old)
{
	char	*pos;
	char	*base;
	char	*new;


	pos = ft_strrchr(old, '.');
	base = ft_strsub(old, 0, pos - old);
	new = ft_strjoin(base, ".s");
	free(base);
	ft_putendl(new);
	return (new);
}

void	ft_disassemble(char *file, t_bool option_a)
{
	char	*new_file;
	int		fd_src;
	int		fd_dest;

	new_file = ft_get_new_file(file);
	if ((fd_src = open(file, O_RDONLY)) == -1)
		ft_error(8);
	fd_dest = (option_a) ? STDOUT : open(new_file, O_WRONLY | O_CREAT, S_IRWXU);
	ft_disassemble_header(fd_src, fd_dest);
	ft_disassemble_body(fd_src, fd_dest);
	close(fd_src);
	close(fd_dest);
}
