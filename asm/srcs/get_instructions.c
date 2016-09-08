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

static t_bool		ft_is_label_only(char *line)
{
	char	*label_char_pos;
	int		ret;

	label_char_pos = ft_strchr(line, LABEL_CHAR);
	ret = (label_char_pos) ? TRUE : FALSE;
	while(*(++label_char_pos) && ret)
	{
		if (*(label_char_pos) == COMMENT_CHAR || *(label_char_pos) == ';')
			return (TRUE);
		if (!ft_isspace(*label_char_pos))
			return (FALSE);
	}
	return (ret);
}

static t_inst		*ft_init_instruction()
{
	t_inst		*instruction;

	if (!(instruction = (t_inst *)malloc(sizeof(t_inst))))
		return (NULL);
	instruction->label = NULL;
	instruction->is_label_only = FALSE;
	instruction->opcode = NULL;
	instruction->nb_args = 0;
	instruction->args = NULL;
	instruction->size = 0;
	return (instruction);
}

static t_inst		*ft_extract_instruction(char *line)
{
	t_inst		*instruction;
	t_bool		has_label;

	instruction = ft_init_instruction();
	instruction->label = ft_get_label(line);
	has_label = (instruction->label) ? TRUE : FALSE;
	if (instruction->label && ft_is_label_only(line))
	{
		instruction->is_label_only = TRUE;
		return (instruction);
	}
	instruction->opcode = ft_get_opcode(line, has_label);
	instruction->nb_args = ft_get_op(instruction->opcode)->nb_args;
	instruction->args = ft_get_args(line, instruction->opcode, has_label);
	instruction->size = ft_get_size(instruction->args, instruction->opcode);
	return (instruction);
}

t_list		*ft_get_instructions(int fd, t_header *header)
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
		if (IS_EMPTY <= kind && kind <= IS_CHAMP_COMMENT)
			continue ;
		if (line[0] != '\0' && (inst = ft_extract_instruction(line)) != NULL)
		{
			ft_lstappend(&instructions, ft_lstnew(inst, sizeof(*inst)));
			header->prog_size += inst->size;
			// ft_debug_instruction(inst);
			free(inst);
		}
		free(line);
	}
	// ft_debug_header(header);
	return (instructions);
}
