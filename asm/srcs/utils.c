/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 16:13:48 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/09/08 16:13:49 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			ft_get_value(unsigned char *encoded, int size)
{
	int		value;
	int		initial_size;

	value = 0;
	initial_size = size;
	while (size)
	{
		value = value << 8;
		value = value | (*encoded & 0xff);
		++encoded;
		size--;
	}
	if (initial_size == 2)
		return ((short)value);
	return (value);
}
