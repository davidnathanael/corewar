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
	char	*instr;
	char	*line_t;
	char	*label_name;

	i = 1;
	label_name = get_label_name(line);
	get_new_label(label_name, IS_LABEL, data);
	ft_memdel((void **)&label_name);
	while (line[i - 1] != LABEL_CHAR)
		i++;
	while ((line[i] == ' ' || line[i] =='\t') && line[i] != '\0')
		i++;
	if (line[i] != '\0')
	{
		instr = ft_strsub(line, i, ft_strlen(line) - 1);
		line_t = ft_strtrim(instr);
		ft_memdel((void **)&instr);
		if (get_instr(line_t) >= 10)
			ft_check_instr(line_t, get_instr(line_t) / 10, data);
		else
			ft_error(7);
		ft_memdel((void **)&line_t);
	}
}
