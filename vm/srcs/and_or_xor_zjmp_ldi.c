/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or_xor_zjmp_ldi.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 13:07:27 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/09/08 18:50:45 by vbaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		ft_and(t_args *args, t_vm *vm, t_process *process)
{
	int		value1;
	int		value2;

	if ((args->types[0] != DIR_CODE && args->types[0] != IND_CODE &&
									args->types[0] != REG_CODE) ||
		(args->types[1] != DIR_CODE && args->types[1] != IND_CODE &&
									args->types[1] != REG_CODE) ||
		args->types[2] != REG_CODE)
	{
		process->carry = 0;
		return ;
	}
	if (ft_check_reg_exist(args))
	{
		value1 = get_value_depending_on_type(0, args, process, vm);
		value2 = get_value_depending_on_type(1, args, process, vm);
		process->reg[args->values[2] - 1] = (value1 & value2);
		if (process->reg[args->values[2] - 1] == 0)
			process->carry = 1;
		else
			process->carry = 0;
	}
	else
		process->carry = 0;
}

void		ft_or(t_args *args, t_vm *vm, t_process *process)
{
	int		value1;
	int		value2;

	if ((args->types[0] != DIR_CODE && args->types[0] != IND_CODE &&
									args->types[0] != REG_CODE) ||
		(args->types[1] != DIR_CODE && args->types[1] != IND_CODE &&
									args->types[1] != REG_CODE) ||
		args->types[2] != REG_CODE)
	{
		process->carry = 0;
		return ;
	}
	if (ft_check_reg_exist(args))
	{
		value1 = get_value_depending_on_type(0, args, process, vm);
		value2 = get_value_depending_on_type(1, args, process, vm);
		process->reg[args->values[2] - 1] = (value1 | value2);
		if (process->reg[args->values[2] - 1] == 0)
			process->carry = 1;
		else
			process->carry = 0;
	}
	else
		process->carry = 0;
}

void		ft_xor(t_args *args, t_vm *vm, t_process *process)
{
	int		value1;
	int		value2;

	if ((args->types[0] != DIR_CODE && args->types[0] != IND_CODE &&
									args->types[0] != REG_CODE) ||
		(args->types[1] != DIR_CODE && args->types[1] != IND_CODE &&
									args->types[1] != REG_CODE) ||
		args->types[2] != REG_CODE)
	{
		process->carry = 0;
		return ;
	}
	if (ft_check_reg_exist(args))
	{
		value1 = get_value_depending_on_type(0, args, process, vm);
		value2 = get_value_depending_on_type(1, args, process, vm);
		process->reg[args->values[2] - 1] = (value1 ^ value2);
		if (process->reg[args->values[2] - 1])
			process->carry = 0;
		else
			process->carry = 1;
	}
	else
		process->carry = 0;
}

void		ft_zjmp(t_args *args, t_vm *vm, t_process *process)
{
	if (process->carry == 1)
		process->pc = ft_loop_memory(process->pc +
									(args->values[0] % IDX_MOD));
	else
		process->pc = (process->pc + 3) % MEM_SIZE;
	(void)vm;
}

void		ft_ldi(t_args *args, t_vm *vm, t_process *process)
{
	int		values[2];
	int		addr;
	int		value;

	if ((args->types[0] != DIR_CODE && args->types[0] != IND_CODE &&
		args->types[0] != REG_CODE) || (args->types[1] != DIR_CODE &&
		args->types[1] != REG_CODE) || args->types[2] != REG_CODE)
	{
		process->carry = 0;
	}
	else if (ft_check_reg_exist(args))
	{
		values[0] = get_value_depending_on_type(0, args, process, vm);
		values[1] = get_value_depending_on_type(1, args, process, vm);
		addr = values[0] + values[1];
		value = ft_get_value(&vm->memory[ft_loop_memory(process->pc +
														addr % IDX_MOD)], 4);
		process->reg[args->values[2] - 1] = value;
		if (value == 0)
			process->carry = 1;
		else
			process->carry = 0;
	}
	else
		process->carry = 0;
}
