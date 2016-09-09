/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_vm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 13:20:03 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/09/09 05:13:34 by vbaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <time.h>

t_op			*ft_get_op_data(int op)
{
	int			i;

	i = 0;
	while (g_op_tab[i].name != NULL)
	{
		if (g_op_tab[i].code == op)
		{
			return (&g_op_tab[i]);
		}
		i++;
	}
	return (NULL);
}

static int		get_next_pc(t_vm *vm, t_process *process, int op)
{
	int			cursor;

	cursor = process->pc;
	if (op == LIVE)
		cursor += 4;
	else if (op == FORK || op == LFORK)
		cursor += 2;
	else if (op > 0 && op < 17)
		cursor = ft_handle_coding_byte(cursor, vm, op);
	cursor++;
	cursor = ft_loop_memory(cursor);
	return (cursor);
}

static void		ft_do_2(t_vm *vm, t_process *process)
{
	process->waiting_op = vm->memory[process->pc];
	process->cycle_to_wait =
	ft_get_op_data(process->waiting_op)->cycle;
	process->is_waiting = TRUE;
}

void			ft_do_process(t_vm *vm)
{
	t_process	*process;
	int			next_pc;
	int			op;

	process = vm->process;
	while (process)
	{
		op = vm->memory[ft_loop_memory(process->pc)];
		next_pc = get_next_pc(vm, process, op);
		if (!process->waiting_op)
		{
			if (vm->memory[process->pc] > 0 && vm->memory[process->pc] < 17)
				ft_do_2(vm, process);
			else
				process->pc = ft_loop_memory(++process->pc);
		}
		else if (process->cycle_to_wait == 1 && process->waiting_op)
			ft_execute(vm, process);
		else
			--process->cycle_to_wait;
		if (op != ZJMP && !process->is_waiting)
			process->pc = next_pc;
		process = process->next;
	}
}

void			ft_launch_vm(t_vm *vm)
{
	int			cycles;

	cycles = 1;
	while (1)
	{
		if (vm->dump > 0 && cycles == vm->dump)
			ft_dump_memory(vm->memory, 0, MEM_SIZE);
		if (vm->cycle_in_current_period == vm->cycle_to_die)
			ft_check_alive(vm);
		if (vm->cycle_to_die < 0 || vm->nb_process <= 0)
			break ;
		ft_do_process(vm);
		vm->cycle_in_current_period++;
		cycles++;
	}
}
