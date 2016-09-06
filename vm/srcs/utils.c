/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 19:23:28 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/09/02 14:01:08 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				ft_get_value(unsigned char *encoded, int size)
{
	int		value;
	int		initial_size;

	value = 0;
	initial_size = size;
	while (size)
	{
		value = value << 8;
		value = value | (*encoded & 0xff);
		++encoded;
		size--;
	}
	if (initial_size == 2)
		return ((short)value);
	return (value);
}

t_op	*ft_get_op_data(int op)
{
	int		i;

	i = 0;
	while (g_op_tab[i].name != NULL)
	{
		if (g_op_tab[i].code == op)
			return (&g_op_tab[i]);
		i++;
	}
	return (NULL);
}

void	write_byte(long value, t_vm *vm, long number, t_process *process)
{
	int		i;
	int		offset;

	i = 0;
	offset = 24;
	while (i < 4)
	{
		vm->memory[ft_loop_memory(process->pc + number + i)] = (value >> offset) & 0xff;
		offset -= 8;
		i++;
	}
}

int	get_value_depending_on_type(int pos, t_args *args,
									t_process *process, t_vm *vm)
{
	int	value;

	value = 0;
	if (args->types[pos] == T_REG)
		value = process->reg[args->values[pos] - 1];
	else if (args->types[pos] == T_IND)
		value = vm->memory[ft_loop_memory((process->pc +
										(args->values[pos] % IDX_MOD)))];
	else if (args->types[pos] == T_DIR)
		value = args->values[pos];
	process->carry = 1;
	return (value);
}

t_bool		ft_check_reg_exist(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->nb_args)
	{
		if (args->types[i] == T_REG)
		{
			if (args->values[i] < 1 || args->values[i] > REG_NUMBER)
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

int		ft_loop_memory(int value)
{
	int		ret;

	ret = value;
	while (ret < 0)
		ret = MEM_SIZE + ret;
	if (ret >= MEM_SIZE)
		ret = value % MEM_SIZE;
	return (ret);
}
