/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 12:06:31 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/09/08 12:06:32 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool		ft_is_in_array(int *array, int value, int size)
{
	while (size)
	{
		--size;
		if (array[size] == value)
			return (TRUE);
	}
	return (FALSE);
}
