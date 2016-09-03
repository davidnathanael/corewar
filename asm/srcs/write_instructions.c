/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 14:34:59 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/08/24 14:35:00 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		ft_write_prefix(int fd, int nb_args, char **args)
{
	int		prefix;

	prefix = ft_get_prefix(nb_args, args);
	write(fd, &prefix, 1);
}

static void		ft_write_value(int fd, int value, int size)
{
	int		print;

	print = 0;
	while (size)
	{
		print = (value >> (size * 8 - 8)) & 0xff;
		write(fd, &print, 1);
		size--;
	}
}

static void		ft_write_args(int fd, t_inst *inst, t_op *infos, t_list *instructions)
{
	int		i;
	int		arg_type;

	i = 0;
	arg_type = 0;
	if (infos->has_encoding)
		ft_write_prefix(fd, infos->nb_args, inst->args);
	while (i < infos->nb_args)
	{
		arg_type = ft_get_arg_type(inst->args[i]);
		if (arg_type == IS_REG)
			ft_write_value(fd, ft_atoi(&(inst->args[i][1])), 1);
		else if (arg_type == IS_DIR_VALUE)
			ft_write_value(fd, ft_atoi(&(inst->args[i][1])), infos->label_size);
		else if (arg_type == IS_DIR_LABEL)
			ft_write_value(fd, ft_get_label_value(instructions, inst, &(inst->args[i][2])),
							infos->label_size);
		else if (arg_type == IS_IND_VALUE)
			ft_write_value(fd, ft_atoi(&(inst->args[i][0])), 2);
		else if (arg_type == IS_IND_LABEL)
			ft_write_value(fd, ft_get_label_value(instructions, inst, &(inst->args[i][1])),
							infos->label_size);
		i++;
	}
}

void	ft_write_instructions(int fd, t_list *instructions)
{
	t_list	*head;
	t_inst	*instruction;
	t_op	*infos;
	int		total_size;

	head = instructions;
	instruction = NULL;
	infos = NULL;
	total_size = 0;
	while(instructions)
	{
		instruction = instructions->content;
		if (!instruction->is_label_only)
		{
			infos = ft_get_op(instruction->opcode);
			if (fd == STDOUT)
				ft_print_instruction(instruction, infos, total_size, head);
			else
			{
				write(fd, &(infos->code), 1);
				ft_write_args(fd, instruction, infos, head);
			}
			total_size += instruction->size;
		}
		else if (instruction->is_label_only && fd == STDOUT)
			ft_printf("%16s{red}    %s:{eoc}\n", ":", instruction->label);
		instructions = instructions->next;
	}
}
