/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 15:10:45 by vbaudin           #+#    #+#             */
/*   Updated: 2016/08/23 18:09:01 by vbaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				main(int ac, char **av)
{
	if (ac != 2)
		ft_putendl("Usage: ./asm <sourcefile>");
	else
	{
		ft_parse(av[1]);
		ft_putstr("The file ");
		ft_putstr((ft_strrchr(av[1], '/') + 1) ? ft_strrchr(av[1], '/') + 1 : av[1]);
		ft_putendl(" is good.");
		ft_compile(av[1]);
	}
	return (0);
}
