/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 14:37:21 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/09/01 08:16:18 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		ft_print_usage(void)
{
	ft_putstr("Usage: ./corewar [-n nb_player] <champion.cor>\n");
	exit(-1);
}

void		ft_debug_champions(t_champion *champions, t_vm *vm)
{
	int		i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		ft_printf("Le nom du champion numero {red}%d{eoc} est %s\nSon commentaire est : %s\nLa size de sa data est : %d\n", champions[i].champ_nb, champions[i].name, champions[i].comment, champions[i].data_size);
		i++;
	}
	ft_printf("Le nombre total de champions est de %d\n", vm->nb_champs);
}

int			main(int ac, char **av)
{
	t_vm		*vm;

	if (ac == 1)
		ft_print_usage();
	vm = init_vm();
	ft_parse_command(av);
	ft_get_champions(av, vm->champions, vm);
//	ft_debug_champions(vm->champions, vm);
	ft_load_champions(vm);
	
	return (0);
}
