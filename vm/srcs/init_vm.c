/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 11:44:50 by vbaudin           #+#    #+#             */
/*   Updated: 2016/08/30 11:54:40 by vbaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		init_champ(t_vm *vm)
{
	int		i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		vm->champions[i].name = NULL;
		vm->champions[i].comment = NULL;
		vm->champions[i].data = NULL;
		vm->champions[i].champ_nb = -1;
		vm->champions[i].live = 0;
		i++;
	}
}

t_vm		*init_vm(void)
{
	t_vm	*vm;
	int		i;

	vm = (t_vm *)ft_memalloc(sizeof(t_vm));
	i = 0;
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->nb_executed_live = 0;
	vm->nb_champs = 0;
	vm->process = NULL;
	vm->nb_process = 0;
	vm->lives_in_current_period = 0;
	vm->cycle_in_current_period = 0;
	vm->check_in_current_period = 0;
	vm->dump = -1;
	ft_memset(vm->memory, 0, MEM_SIZE);
	init_champ(vm);
	return (vm);
}
