/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 18:50:24 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/08/18 18:50:26 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_inst		*ft_extract_instruction(char *line)
{
	t_inst		*instruction;

	if (!(instruction = (t_inst *)malloc(sizeof(t_inst))));
		return (NULL);

	return (NULL);
}

t_list		*ft_get_instructions(int fd)
{
	t_list		*instructions;
	t_inst		*inst;
	char		*line;

	instructions = NULL;
	inst = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (inst = ft_extract_instruction(line))
			ft_lstappend(&instructions, ft_lstnew(inst, sizeof(inst))); //leak of inst
		free(inst);
		free(line);
	}
	return (instructions);
}
