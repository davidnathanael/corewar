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

	if (!(instruction = (t_inst *)malloc(sizeof(t_inst))))
		return (NULL);
	instruction->label = ft_get_label(line);
	instruction->opcode = ft_get_opcode(line, instruction->label ? TRUE : FALSE);
	instruction->nb_args = ft_get_nb_args(instruction->opcode);
	instruction->args = ft_get_args(line, instruction->opcode,
									instruction->label ? TRUE : FALSE);
	instruction->size = 0;
	return (instruction);
}

t_list		*ft_get_instructions(int fd)
{
	t_list		*instructions;
	t_inst		*inst;
	char		*line;
	int			kind;

	instructions = NULL;
	inst = NULL;
	kind = 0;
	while (get_next_line(fd, &line) > 0)
	{
		kind = line_kind(line);
		if (kind == IS_CHAMP_NAME || kind == IS_CHAMP_COMMENT)
			continue ;
		if (line[0] != '\0' && (inst = ft_extract_instruction(line)) != NULL)
		{
			ft_lstappend(&instructions, ft_lstnew(inst, sizeof(inst))); //leak of inst
			ft_debug_instruction(inst);
			free(inst);
		}
		free(line);
	}
	return (instructions);
}
