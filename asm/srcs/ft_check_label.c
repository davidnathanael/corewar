/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_label.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 15:58:42 by vbaudin           #+#    #+#             */
/*   Updated: 2016/08/23 17:50:03 by vbaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char		*get_label_name(char *line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
		i++;
	j = 1;
	while (line[j] != LABEL_CHAR)
		j++;
	return (ft_strsub(line, i, j));
}

void			ft_check_label(char *line, t_parse *data)
{
	int		i;
	char	*line_t;
	char	*str;

	i = 1;
	str = get_label_name(line);
	get_new_label(str, IS_LABEL, data);
	ft_memdel((void **)&str);
	while (line[i - 1] != LABEL_CHAR)
		i++;
	while ((line[i] == ' ' || line[i] =='\t') && line[i] != '\0')
		i++;
	if (line[i] != '\0')
	{
		str = ft_strsub(line, i, ft_strlen(line) - 1);
		line_t = ft_strtrim(str);
		ft_memdel((void **)&str);
		if (get_instr(line_t) >= 10)
			ft_check_instr(line_t, get_instr(line_t) / 10, data);
		else if (line_t && line_t[0] && (line_t[0] == COMMENT_CHAR || line_t[0] == ';'))
			i++;
		else
		{
			ft_strdel(&line_t);
			ft_free_and_exit(data, line, 7);
		}
		ft_memdel((void **)&line_t);
	}
}
