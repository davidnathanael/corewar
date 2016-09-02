/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_vm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 13:20:03 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/09/02 13:20:05 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"


void	ft_execute(t_vm *vm, t_process *process)
{
	t_op	*op;
	t_args	*args;

	op = ft_get_op_data(process->waiting_op);
	args = ft_get_args(vm, process, op);
	// (*op->func)(args, vm, process);
}

void	ft_do_process(t_vm *vm)
{
	t_process	*process;

	process = vm->process;
	while (process)
	{
		if (!process->waiting_op)
		{
			process->waiting_op = vm->memory[process->pc];
			process->cycle_to_wait = ft_get_op_data(process->waiting_op)->cycle;
			process->is_waiting = TRUE;
		}
		if (process->cycle_to_wait == 1)
			ft_execute(vm, process);
		else
			--process->cycle_to_wait;
		process = process->next;
	}
}

void	ft_launch_vm(t_vm *vm)
{
	int		cycles;

	cycles = 1;
	while (1)
	{
		ft_do_process(vm);
		cycles++;
	}
}
