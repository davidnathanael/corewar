/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 15:23:52 by vbaudin           #+#    #+#             */
/*   Updated: 2016/08/17 18:54:04 by vbaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_error(int i)
{
	if (i == 1)
		ft_putendl("Syntax Error.");
	else if (i == 2)
		ft_putendl("End of File with no instructions.");
	else if (i == 3)
		ft_putendl("Your file doesn't seems to be a .s file.");
	else if (i == 4)
		ft_putendl("This file doesn't exist.");
	else if (i == 5)
		ft_putendl("Malloc Error.");
	exit (0);
}
