/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 11:48:29 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/09/08 16:36:10 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	ft_get_param_size(char *param, t_op *data)
{
	if (param[0] == 'r')
		return (1);
	else if (param[0] == DIRECT_CHAR)
		return (data->label_size);
	else
		return (2);
}

int			ft_get_size(char **args, char *opcode)
{
	int		i;
	int		size;
	t_op	*data;

	i = 0;
	size = 1;
	data = ft_get_op(opcode);
	while (args[i])
	{
		size += ft_get_param_size(args[i], data);
		i++;
	}
	return (size + data->octet);
}
