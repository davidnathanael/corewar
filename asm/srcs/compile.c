/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 15:54:43 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/08/18 15:54:45 by ddela-cr         ###   ########.fr       */
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
	new = ft_strjoin(base, ".cor");
	free(base);
	return (new);
}

void			ft_compile(char *file)
{
	int			fd;
	t_header	*header;
	t_list		*instructions;
	char		*new_file;

	fd = open(file, O_RDONLY);
	header = ft_get_header(fd);
	instructions = ft_get_instructions(fd, header);
	new_file = ft_get_new_file(file);
	close(fd);
	fd = open(new_file, O_WRONLY | O_CREAT | O_APPEND, S_IRWXU);
	ft_write_header(fd, header);
	ft_write_instructions(fd, instructions);
	close(fd);
	free(new_file);
}
