/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 21:00:57 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/08/22 21:00:59 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_get_nb_args(char *opcode)
{
	int		i;
	int		nb_args;

	i = 0;
	nb_args = 0;
	while (g_op_tab[i].name != NULL)
	{
		if (ft_strcmp(g_op_tab[i].name, opcode) == 0)
			nb_args = g_op_tab[i].nb_args;
		i++;
	}
	return (nb_args);
}

char	**ft_get_args(char *line, char *opcode, t_bool has_label)
{
	char	**args;
	char	*tmp;
	int		i;

	args = NULL;
	tmp = NULL;
	i = 0;
	line = ft_strstr((has_label) ? ft_strchr(line, LABEL_CHAR) : line, opcode);
	while (!ft_isspace(*line))
		++line;
	args = ft_strsplit(line, SEPARATOR_CHAR);
	while (args[i])
	{
		tmp = args[i];
		args[i] = ft_strtrim(args[i]);
		free(tmp);
		i++;
	}
	return (args);
}
