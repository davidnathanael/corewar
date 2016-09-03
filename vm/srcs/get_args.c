/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 14:48:50 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/09/02 14:48:51 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	ft_get_value_size(int type, t_op *data)
{
	if (type == T_REG)
		return (1);
	else if (type == IND)
		return (2);
	else
		return (data->label_size);
}

static void	ft_get_args_values(t_vm *vm, t_process *process, t_op *data, t_args *args)
{
	int			i;
	int			cursor;
	int			size;

	i = 0;
	cursor = (process->pc + data->has_encoding) + 1;
	ft_debug_memory(vm->memory, cursor, 10);
	while (i < args->nb_args)
	{
		size = ft_get_value_size(args->types[i], data);
		args->values[i] = ft_get_value(&(vm->memory[cursor]), size);
		cursor += size;
		i++;
	}
}

static void	ft_get_args_type(t_vm *vm, t_process *process, t_op *data, t_args *args)
{
	int			cursor;
	int			offset;
	int			i;

	cursor = process->pc;
	offset = 6;
	i = 0;
	if (data->has_encoding)
	{
		while (offset > 0)
		{
			args->types[i] = (vm->memory[cursor + 1] >> offset) & 0x3;
			offset -= 2;
			i++;
		}
	}
	else
		args->types[i] = T_DIR;

}

t_args	*ft_get_args(t_vm *vm, t_process *process, t_op *data)
{
	t_args		*args;
	int			i;

	if (!(args = (t_args *)ft_memalloc(sizeof(t_args))))
		ft_exit_error("Malloc args failed.", NULL);
	args->nb_args = data->nb_args;
	ft_bzero(args->types, sizeof(int) * MAX_ARGS_NUMBER);
	ft_bzero(args->values, sizeof(int) * MAX_ARGS_NUMBER);
	ft_get_args_type(vm, process, data, args);
	ft_get_args_values(vm, process, data, args);
	i = 0;
	while (i < 4)
	{
		ft_printf("i : %d | type : %d | value : %d\n", i, args->types[i], args->values[i]);
		i++;
	}
	exit(0);
	return (args);
}
