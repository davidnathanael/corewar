/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 15:10:45 by vbaudin           #+#    #+#             */
/*   Updated: 2016/08/12 11:31:51 by vbaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

int		ft_put_file(void)
{
	ft_putendl("Usage: ./asm <sourcefile>");
	return (0);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		return (ft_put_file());
	return (0);
}
