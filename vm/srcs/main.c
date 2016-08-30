/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 14:37:21 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/08/30 12:21:52 by vbaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		ft_print_usage(void)
{
	ft_putstr("Usage: ./corewar [-n nb_player] <champion.cor>\n");
	exit(-1);
}

void		ft_debug_champions(t_champion *champions)
{
	int		i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		ft_printf("Le nom du champion numero %d est %s\n", champions[i].champ_nb, champions[i].name);
		i++;
	}
}

int			main(int ac, char **av)
{
	t_vm		vm;

	if (ac == 1)
		ft_print_usage();
	init_vm(&vm);
	ft_parse_command(av);
	ft_get_champions(av, vm.champions);
//	ft_debug_champions(vm.champions);
	return (0);
}
