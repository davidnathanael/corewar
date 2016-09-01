/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 19:23:28 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/09/01 19:23:30 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				ft_get_value(char *encoded, int size)
{
	int		value;

	value = 0;
	while (size)
	{
		value = value << 8;
		value = value | (*encoded & 0xff);
		++encoded;
		size--;
	}
	return (value);
}
