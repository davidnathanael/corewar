/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name_comment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 15:00:55 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/08/17 18:37:04 by vbaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	ft_check_data(char *line, char *type, t_parse *data)
{
	char	*data_txt;
	int		i;

	i = 0;
	data_txt = ft_strsub(line, ft_strlen(type),
			ft_strlen(line) - ft_strlen(type));
	while (data_txt[i] != '\0' && (data_txt[i] == ' ' || data_txt[i] == '\t'))
		i++;
	if (data_txt[i] == '"')
		i++;
	else
		ft_error(1);
	while (data_txt[i] != '\0' && data_txt[i] != '"')
		i++;
	if (data_txt[i] == '"')
	{
		if (ft_strcmp(type, NAME_CMD_STRING) == 0)
			data->setting_name++;
		else if (ft_strcmp(type, COMMENT_CMD_STRING) == 0)
			data->setting_comment++;
	}
	ft_memdel((void **)&data_txt);
}

static void ft_get_comment(t_parse *data, char *line)
{
	char	*tmp;

	if (data->comment == NULL)
		data->comment = ft_strdup(line);
	else
	{
		tmp = ft_strdup(data->comment);
		ft_memdel((void **)&data->comment);
		data->comment = ft_strjoin(tmp, line);
		ft_memdel((void **)&tmp);
	}
	data->isset_comment = 1;
	ft_check_data(data->comment, COMMENT_CMD_STRING, data);
}

static void ft_get_name(t_parse *data, char *line)
{
	char	*tmp;

	if (data->name == NULL)
		data->name = ft_strdup(line);
	else
	{
		tmp = ft_strdup(data->name);
		ft_memdel((void **)&data->name);
		data->name = ft_strjoin(tmp, line);
		ft_memdel((void **)&tmp);
	}
	data->isset_name = 1;
	ft_check_data(data->name, NAME_CMD_STRING, data);
}

void	ft_check_name_comment(char *line, t_parse *data, int type)
{
	char	*trimmed;

	trimmed = ft_strtrim(line);
	if ((type == 3 && (data->setting_name++)) || data->setting_name == 1)
		ft_get_name(data, trimmed);
	else if ((type == 4 && (data->setting_comment++)) ||
			data->setting_comment == 1)
		ft_get_comment(data, trimmed);
	ft_memdel((void **)&trimmed);
	if (data->setting_name == 2 && data->setting_comment == 2 &&
			data->header_is_parsed == 0)
		ft_end_name_comment(data);
}
