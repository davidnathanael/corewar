/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 15:54:43 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/09/08 15:18:51 by jbateau          ###   ########.fr       */
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

void			ft_free_instructions(t_list *instructions)
{
	t_list	*tmp;
	t_list	*ptmp;
	t_inst	*inst;

	tmp = instructions;
	while (tmp)
	{
		ptmp = tmp->next;
		inst = tmp->content;
		ft_strdel(&(inst->label));
		ft_strdel(&(inst->opcode));
		if (inst->args)
			ft_free_str_tab(inst->args);
		free(inst);
		free(tmp);
		tmp = ptmp;
	}
}

void			ft_compile(char *file, t_bool option_a)
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
	fd = (option_a) ? STDOUT : open(new_file, O_WRONLY | O_CREAT, S_IRWXU);
	ft_write_header(fd, header);
	ft_write_instructions(fd, instructions);
	close(fd);
	free(new_file);
	free(header);
	ft_free_instructions(instructions);
}
