/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 14:37:21 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/09/02 12:57:04 by vbaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		ft_print_usage(void)
{
	ft_putstr("Usage: ./corewar [-d unsigned int] ");
	ft_putstr("[-n nb_player] <champion.cor>\n");
	exit(-1);
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
	printf("Le gagnant est le joueur %s qui porte le numero %d\n",
		vm->last_champion_alive_name, vm->last_champion_alive_number);
	return (0);
}
