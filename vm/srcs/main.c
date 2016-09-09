/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 14:37:21 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/09/09 05:13:17 by vbaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		ft_print_usage(void)
{
	ft_putstr("Usage: ./corewar [-d unsigned int] ");
	ft_putstr("[-n nb_player] <champion.cor>\n");
	exit(-1);
}

void		ft_execute(t_vm *vm, t_process *process)
{
	t_op		*op;
	t_args		*args;

	op = ft_get_op_data(process->waiting_op);
	args = ft_get_args(vm, process, op);
	ft_redirect_op(args, vm, process);
	process->is_waiting = FALSE;
	process->waiting_op = 0;
	if (args)
		free(args);
}

void		ft_free_vm(t_vm *vm)
{
	t_process	*tmp;
	int			i;

	i = 0;
	while (vm->process)
	{
		tmp = vm->process->next;
		free(vm->process);
		vm->process = tmp;
	}
	while (i < vm->nb_champs)
	{
		ft_strdel(&vm->champions[i].name);
		ft_strdel(&vm->champions[i].comment);
		i++;
	}
}

int			main(int ac, char **av)
{
	t_vm		*vm;

	if (ac == 1)
		ft_print_usage();
	vm = init_vm();
	ft_parse_command(av, vm);
	ft_get_champions(av, vm->champions, vm);
	ft_load_champions(vm);
	ft_introduce_champs(vm);
	ft_launch_vm(vm);
	printf("The Player %d, %s Wins\n", vm->last_champion_alive_number,
			vm->last_champion_alive_name);
	ft_free_vm(vm);
	return (0);
}
