/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 12:12:40 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/08/23 12:12:42 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_op	*ft_get_op(char *name)
{
	int		i;

	i = 0;
	while (g_op_tab[i].name != NULL)
	{
		if (ft_strcmp(g_op_tab[i].name, name) == 0)
			return (&g_op_tab[i]);
		i++;
	}
	return (NULL);
}
