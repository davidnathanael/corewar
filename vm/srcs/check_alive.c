/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_alive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 12:32:54 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/09/03 12:32:58 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_sanitize(t_process *process)
{
	t_process	*tmp;
	t_process	*cur;

	cur = process;
	while (cur)
	{
		if (!cur->live)
		{
			tmp = cur->next;
			if (cur->prev)
				cur->prev->next = cur->next;
			if (cur->next)
				cur->next->prev = cur->prev;
			ft_memdel((void **)&cur);
			cur = tmp;
		}
		else
			cur = cur->next;
	}
}

void	ft_restart_lives(t_vm *vm, t_champion *champions, t_process *process)
{
	int		i;

	i = 0;
	while (i < vm->nb_champs)
		champions[i++].live = 0;
	while (process)
	{
		process->live = 0;
		process = process->next;
	}
}

void	ft_check_alive(t_vm *vm)
{
	/*
	** On check si des champions sont morts; !!
	** Si lives_in_current period > NBR | cycle_to_die -= CYCLE_DELTA;
	** si check_in_current_period == MAX_CHECK | cycle_to_die -= CYCLE_DELTA;
	** On met les lives des process et champs a 0 !
	*/
	//ft_sanitize(vm->process);
	vm->check_in_current_period++;
	if (vm->lives_in_current_period > NBR_LIVE)
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		vm->check_in_current_period = 0;
	}
	if (vm->check_in_current_period == MAX_CHECKS)
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		vm->check_in_current_period = 0;
	}
	ft_restart_lives(vm, vm->champions, vm->process);
	vm->cycle_in_current_period = 0;
}
