/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_ld_st_add_sub.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 13:08:32 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/09/08 22:50:44 by vbaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		ft_live(t_args *args, t_vm *vm, t_process *process)
{
	int			i;

	i = 0;
	process->live = 1;
	vm->lives_in_current_period++;
	while (i < vm->nb_champs)
	{
		if (vm->champions[i].champ_nb == args->values[0])
		{
			if (!vm->mute)
				ft_printf("Un processus dit que le joueur %d (%s) est en vie\n",
					vm->champions[i].champ_nb, vm->champions[i].name);
			vm->champions[i].live = 1;
			vm->last_champion_alive_number = vm->champions[i].champ_nb;
			vm->last_champion_alive_name = ft_strdup(vm->champions[i].name);
		}
		i++;
	}
}

void		ft_ld(t_args *args, t_vm *vm, t_process *process)
{
	int		value;

	value = 0;
	if ((args->types[0] != DIR_CODE && args->types[0] != IND_CODE) ||
		args->types[1] != REG_CODE)
	{
		process->carry = 0;
		return ;
	}
	if (args->types[0] == IND_CODE)
		value = vm->memory[ft_loop_memory(process->pc +
										(args->values[0] % IDX_MOD))];
	else if (args->types[0] == DIR_CODE)
		value = args->values[0];
	if (args->values[1] > 0 && args->values[1] <= REG_NUMBER)
	{
		process->reg[args->values[1] - 1] = value;
		if (value == 0)
			process->carry = 1;
		else
			process->carry = 0;
	}
	else
		process->carry = 0;
}

void		ft_st(t_args *args, t_vm *vm, t_process *process)
{
	int	value;

	if (args->types[0] != REG_CODE ||
		(args->types[1] != IND_CODE && args->types[1] != T_REG))
		return ;
	if (args->types[0] == REG_CODE && ft_check_reg_exist(args))
	{
		value = process->reg[args->values[0] - 1];
		if (args->types[1] == REG_CODE)
			process->reg[args->values[1] - 1] = value;
		else if (args->types[1] == IND_CODE)
			write_byte(value, vm, args->values[1] % IDX_MOD, process);
	}
}

void		ft_add(t_args *args, t_vm *vm, t_process *process)
{
	int		value;

	if (args->types[0] != REG_CODE || args->types[1] != REG_CODE ||
		args->types[2] != REG_CODE)
	{
		process->carry = 0;
		return ;
	}
	if (ft_check_reg_exist(args))
	{
		value = process->reg[args->values[0] - 1] +
				process->reg[args->values[1] - 1];
		process->reg[args->values[2] - 1] = value;
		if (value == 0)
			process->carry = 1;
		else
			process->carry = 0;
	}
	else
		process->carry = 0;
	(void)vm;
}

void		ft_sub(t_args *args, t_vm *vm, t_process *process)
{
	int		value;

	if (args->types[0] != REG_CODE || args->types[1] != REG_CODE ||
		args->types[2] != REG_CODE)
	{
		process->carry = 0;
		return ;
	}
	if (ft_check_reg_exist(args))
	{
		value = process->reg[args->values[0] - 1] -
				process->reg[args->values[1] - 1];
		process->reg[args->values[2] - 1] = value;
		if (value == 0)
			process->carry = 1;
		else
			process->carry = 0;
	}
	else
		process->carry = 0;
	(void)vm;
}
