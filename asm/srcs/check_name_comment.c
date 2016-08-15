/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name_comment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 15:00:55 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/08/15 15:00:56 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void ft_end_name_comment(t_parse *data)
{
	/* code */
	(void)data;
}

static void ft_get_comment(t_parse *data, char *line)
{
	/* code */
	(void)data;
	(void)line;
}

static void ft_get_name(t_parse *data, char *line)
{
	/* code */
	(void)data;
	(void)line;
}

void	ft_check_name_comment(char *line, t_parse *data, int type)
{
	char	*trimmed;

	trimmed = ft_strtrim(line);
	if ((type == 3 && (data->setting_name++)) || data->setting_name == 1)
		ft_get_name(data, trimmed);
	else if ((type == 4 && (data->setting_comment++)) || data->setting_comment == 1)
		ft_get_comment(data, trimmed);
	ft_memdel((void **)&trimmed);
	if (data->setting_name == 2 && data->setting_comment == 2 && data->line_header == 0)
		ft_end_name_comment(data);
}
