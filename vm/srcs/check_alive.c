/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_alive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 12:32:54 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/09/08 23:28:52 by vbaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		fuck_the_norm(t_process **process, t_process **tmp)
{
	*process = *tmp;
	(*tmp)->prev = NULL;
}

t_process	*ft_sanitize(t_vm *vm, t_process *process)
{
	t_process	*tmp;
	t_process	*cur;
	int			i;

	i = 0;
	cur = process;
	while (cur->final == 0)
	{
		i++;
		tmp = cur->next;
		if (cur && cur->live == 0)
		{
			if (tmp != NULL)
			{
				tmp->prev = cur->prev;
				if (cur->prev != NULL)
					cur->prev->next = cur->next;
				else
					process = tmp;
			}
			ft_memdel((void **)&cur);
			vm->nb_process--;
		}
		if (tmp)
			cur = tmp;
	}
	return (process);
}

void		ft_restart_lives(t_vm *vm, t_champion *champions,
		t_process *process)
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

void		ft_check_alive(t_vm *vm)
{
	vm->process = ft_sanitize(vm, vm->process);
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
