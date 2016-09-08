/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 17:42:39 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/09/08 16:36:37 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*ft_get_label(char *line)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strtrim(line);
	while (tmp[i] && ft_strchr(LABEL_CHARS, tmp[i]))
		i++;
	if (tmp[i] == LABEL_CHAR)
		return (ft_strsub(tmp, 0, i));
	return (NULL);
}

char	*ft_get_opcode(char *line, t_bool has_label)
{
	char	*tmp;
	int		len;

	len = 0;
	tmp = NULL;
	if (has_label)
		line = ft_strchr(line, LABEL_CHAR) + 1;
	while (ft_isspace(*line))
		++line;
	tmp = line;
	while (!ft_isspace(*(++tmp)))
		len++;
	return (ft_strsub(line, 0, len + 1));
}
