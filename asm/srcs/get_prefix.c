/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prefix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 00:13:40 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/08/26 00:14:15 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_get_arg_type(char *arg)
{
	if (arg[0] == 'r')
		return (IS_REG);
	else if (arg[0] == DIRECT_CHAR)
	{
		if (arg[1] == LABEL_CHAR)
			return (IS_DIR_LABEL);
		return (IS_DIR_VALUE);
	}
	else
	{
		if (arg[0] == LABEL_CHAR)
			return (IS_IND_LABEL);
		return (IS_IND_VALUE);
	}
}

int		ft_get_prefix(int nb_args, char **args)
{
	int		prefix;
	int		type;
	int		i;

	prefix = 0;
	type = 0;
	i = 0;
	while (i < nb_args)
	{
		type = ft_get_arg_type(args[i]);
		prefix = prefix << 2;
		if (type == IS_REG)
			prefix = prefix | REG_CODE;
		else if (type == IS_DIR_VALUE || type == IS_DIR_LABEL)
			prefix = prefix | DIR_CODE;
		else
			prefix = prefix | IND_CODE;
		i++;
	}
	return (prefix << (((3 - nb_args) * 2) + 2));
}
