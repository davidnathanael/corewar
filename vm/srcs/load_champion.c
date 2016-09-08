/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_champion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 14:14:31 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/09/08 22:30:11 by vbaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_process	*ft_create_final(t_process *prev)
{
	t_process	*final;
	if (!(final = (t_process *)ft_memalloc(sizeof(t_process))))
		ft_exit_error("Malloc t_process failed", NULL);
	final->pc = 0;
	final->carry = 0;
	final->waiting_op = 0;
	final->cycle_to_wait = 0;
	final->op_size = 1;
	final->is_waiting = FALSE;
	final->live = 0;
	final->final = 1;
	final->next = NULL;
	final->prev = prev;
	return (final);
}

t_process	*ft_init_process(t_process *process, t_champion *champion,
							int cursor)
{
	t_process	*new;

	if (!(new = (t_process *)ft_memalloc(sizeof(t_process))))
		ft_exit_error("Malloc t_process failed", NULL);
	new->reg[0] = champion->champ_nb;
	new->pc = cursor;
	new->carry = 0;
	new->waiting_op = 0;
	new->cycle_to_wait = 0;
	new->op_size = 1;
	new->is_waiting = FALSE;
	new->live = 0;
	new->prev = NULL;
	new->final = 0;
	if (!process)
	{
		new->next = ft_create_final(new);
		return (new);
	}
	new->next = process;
	process->prev = new;
	return (new);
}

void		ft_load_champions(t_vm *vm)
{
	int		size;
	int		cursor;
	int		i;

	size = MEM_SIZE / vm->nb_champs;
	cursor = 0;
	i = 0;
	while (i < vm->nb_champs)
	{
		ft_memcpy(&(vm->memory[cursor]), vm->champions[i].data,
				vm->champions[i].data_size);
		vm->process = ft_init_process(vm->process, &(vm->champions[i]), cursor);
		vm->nb_process++;
		i++;
		cursor += size;
	}
	i--;
	vm->last_champion_alive_number = vm->champions[i].champ_nb;
	vm->last_champion_alive_name = vm->champions[i].name;
}
