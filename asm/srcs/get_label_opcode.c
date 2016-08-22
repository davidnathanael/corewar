/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 17:42:39 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/08/22 17:42:41 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*ft_get_label(char *line)
{
	char	*label_char_pos;

	label_char_pos = ft_strchr(line, LABEL_CHAR);
	if (label_char_pos != NULL)
	{
		if (*(--label_char_pos) != DIRECT_CHAR)
		{
			while (line && ft_isspace(*line))
				++line;
			return (ft_strsub(line, 0, (label_char_pos - line) + 1));
		}
	}
	return (NULL);
}

char	*ft_get_opcode(char *line, t_bool has_label)
{
	char	*tmp;
	int		len;

	len = 0;
	tmp = NULL;
	if (has_label)
		line = ft_strchr(line, LABEL_CHAR);
	while (ft_isspace(*(++line)))
		;
	tmp = line;
	while (!ft_isspace(*(++tmp)))
		len++;
	return (ft_strsub(line, 0, len + 1));
}
