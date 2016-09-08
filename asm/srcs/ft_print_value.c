/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 17:34:23 by jbateau           #+#    #+#             */
/*   Updated: 2016/09/08 17:34:55 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			ft_print_value(int value, int size)
{
	int		print;
	int		initial_size;

	print = 0;
	initial_size = size;
	while (size)
	{
		print = (value >> (size * 8 - 8)) & 0xff;
		ft_printf("%-4d", print);
		size--;
	}
	while (++initial_size <= 4)
		ft_putstr("    ");
	ft_putstr("  ");
}
