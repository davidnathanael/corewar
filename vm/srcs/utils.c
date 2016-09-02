/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 19:23:28 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/09/02 14:01:08 by ddela-cr         ###   ########.fr       */
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

t_op	*ft_get_op_data(int op)
{
	int		i;

	i = 0;
	while (g_op_tab[i].name != NULL)
	{
		if (g_op_tab[i].code == op)
			return (&g_op_tab[i]);
		i++;
	}
	return (NULL);
}
