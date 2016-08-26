/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 14:37:21 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/08/25 14:38:17 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_print_usage()
{
	ft_putstr("usage: ./corewar [-n nb_player] <champion.cor>\n");
	exit(-1);
}

int main(int ac, char **av)
{
	if (ac == 1)
		ft_print_usage();
	ft_parse_command(av);
	return (0);
}
