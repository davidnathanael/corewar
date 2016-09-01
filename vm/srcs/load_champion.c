/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_champion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 14:14:31 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/09/01 14:14:33 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	ft_debug_mem(t_vm *vm)
{
	int		i;

	i = 0;
	while (i != MEM_SIZE)
	{
		ft_printf("%02x ", vm->memory[i++]);
		if (i % (MEM_SIZE / 64) == 0)
			ft_putchar('\n');
	}

	while (vm->process)
	{
		ft_printf("reg[0]  = %d\npc = %d %02x\n", vm->process->reg[0], vm->process->pc, vm->memory[vm->process->pc]);
		vm->process = vm->process->next;
	}
}

t_process	*ft_init_process(t_process *process, t_champion *champion, int cursor)
{
	t_process	*new;

	if (!(new = (t_process *)ft_memalloc(sizeof(t_process))))
		ft_exit_error("Malloc t_process failed", NULL);
	new->reg[0] = champion->champ_nb;
	new->pc = cursor;
	new->carry = 0;
	new->waiting_op = 0;
	new->cycle_to_wait = 0;
	new->is_waiting = FALSE;
	new->prev = NULL;
	if (!process)
	{
		new->next = NULL;
		return (new);
	}
	new->next = process;
	process->prev = new;
	return (new);
}

void	ft_load_champions(t_vm *vm)
{
	int		size;
	int		cursor;
	int		i;

	size = MEM_SIZE / vm->nb_champs;
	cursor = 0;
	i = 0;
	while (i < vm->nb_champs)
	{
		ft_memcpy(&(vm->memory[cursor]), vm->champions[i].data, vm->champions[i].data_size);
		vm->process = ft_init_process(vm->process, &(vm->champions[i]), cursor);
		i++;
		cursor += size;
	}
	ft_debug_mem(vm);
}
