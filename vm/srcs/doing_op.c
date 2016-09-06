/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doing_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 11:05:36 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/09/03 11:05:39 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	ft_redirect_op_2(t_args *args, t_vm *vm, t_process *process)
{
	if (process->waiting_op == STI)
		ft_sti(args, vm, process);
	else if (process->waiting_op == FORK)
		ft_fork(args, vm, process);
	else if (process->waiting_op == LLD)
		ft_lld(args, vm, process);
	else if (process->waiting_op == LLDI)
		ft_lldi(args, vm, process);
	else if (process->waiting_op == LFORK)
		ft_lfork(args, vm, process);
	else if (process->waiting_op == AFF)
		ft_aff(args, vm, process);
}

void		ft_redirect_op(t_args *args, t_vm *vm, t_process *process)
{
	if (process->waiting_op == LIVE)
		ft_live(args, vm, process);
	else if (process->waiting_op == LD)
		ft_ld(args, vm, process);
	else if (process->waiting_op == ST)
		ft_st(args, vm, process);
	else if (process->waiting_op == ADD)
		ft_add(args, vm, process);
	else if (process->waiting_op == SUB)
		ft_sub(args, vm, process);
	else if (process->waiting_op == AND)
		ft_and(args, vm, process);
	else if (process->waiting_op == OR)
		ft_or(args, vm, process);
	else if (process->waiting_op == XOR)
		ft_xor(args, vm, process);
	else if (process->waiting_op == ZJMP)
		ft_zjmp(args, vm, process);
	else if (process->waiting_op == LDI)
		ft_ldi(args, vm, process);
	else
		ft_redirect_op_2(args, vm, process);
}
