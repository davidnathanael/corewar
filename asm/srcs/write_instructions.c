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

static int		ft_get_arg_type(char *arg)
{
	if (arg[0] == 'r')
		return (IS_REG);
	else if (arg[0] == DIRECT_CHAR)
	{
		if (arg[1] == LABEL_CHAR)
			return (IS_DIR_LABEL);
		else
			return (IS_DIR_VALUE);
	}
	else
		return (IS_IND);
}

static void		ft_write_prefix(int fd, int nb_args, char **args)
{
	int		prefix;
	int		type;
	int		i;

	prefix = 0;
	type = 0;
	i = 0;
	while (i < nb_args)
	{
		type = ft_get_arg_type(args[i]);
		prefix = prefix << 2;
		if (type == IS_REG)
			prefix = prefix | T_REG;
		else if (type == IS_DIR_VALUE || type == IS_DIR_LABEL)
			prefix = prefix | T_DIR;
		else
			prefix = prefix | T_IND;
		i++;
	}
	prefix = prefix << (((3 - nb_args) * 2) + 2);
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
	if (infos->needs_prefix)
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
		else
			ft_write_value(fd, ft_atoi(&(inst->args[i][0])), 2);
		i++;
	}
}

void	ft_write_instructions(int fd, t_list *instructions)
{
	t_list	*head;
	t_inst	*instruction;
	t_op	*infos;

	head = instructions;
	instruction = NULL;
	infos = NULL;
	while(instructions)
	{
		instruction = instructions->content;
		infos = ft_get_op(instruction->opcode);
		write(fd, &(infos->code), 1);
		ft_write_args(fd, instruction, infos, head);
		instructions = instructions->next;
	}
}
