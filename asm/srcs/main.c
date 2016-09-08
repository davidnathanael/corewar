/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 15:10:45 by vbaudin           #+#    #+#             */
/*   Updated: 2016/09/08 13:21:10 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				main(int ac, char **av)
{
	t_bool		option_a;

	option_a = FALSE;
	if (ac == 1 || ac > 3)
		ft_putendl("Usage: ./asm [-a] <sourcefile>");
	else
	{
		if (ft_strcmp("-a", av[1]) == 0)
			option_a = TRUE;
		ft_parse((option_a) ? av[2] : av[1]);
		ft_write_output(av[1], option_a);
		ft_compile((option_a) ? av[2] : av[1], option_a);
	}
	return (0);
}
