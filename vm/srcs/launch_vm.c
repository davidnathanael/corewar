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
		}
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
