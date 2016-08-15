/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 15:23:52 by vbaudin           #+#    #+#             */
/*   Updated: 2016/08/15 15:33:02 by vbaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_error(int i)
{
	if (i == 1)
		ft_printf("Syntax Error");
	else if (i == 2)
		ft_printf("End of File with no instructions");
	exit (0);
}
