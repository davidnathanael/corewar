/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 13:26:11 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/08/23 17:50:46 by vbaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	init(t_parse *data)
{
	data->isset_name = 0;
	data->setting_name = 0;
	data->name = NULL;
	data->isset_comment = 0;
	data->setting_comment = 0;
	data->comment = NULL;
	data->header_is_parsed = 0;
	data->line_inst = 0;
	data->nb_lines = 0;
	data->label = NULL;
}

static void	free_data(t_parse *data)
{
	t_label	*c_label;

	ft_memdel((void **)&data->name);
	ft_memdel((void **)&data->comment);
	while (data->label != NULL)
	{
		c_label = data->label;
		data->label = data->label->next;
		ft_memdel((void **)&c_label->name);
		ft_memdel((void **)&c_label);
	}
	ft_memdel((void **)&data);
}

int	ft_labelchr(t_parse *data, char *name)
{
	t_label	*label;

	label = data->label;
	while (label)
	{
		if (label->kind && label->name && !ft_strcmp(label->name, name))
			return	(1);
		label = label->next;
	}
	return	(0);
}

int	ft_labelexist(t_parse *data)
{
	t_label	*label;

	label = data->label;
	while (label)
	{
		if (!label->kind && label->name && !ft_labelchr(data, label->name))
			return (0);
		label = label->next;
	}
	return (1);
}

void	ft_parse(char *file)
{
	int		fd;
	char	*line;
	t_parse	*data;

	fd = is_correct_file(file);
	data = malloc_me();
	init(data);
	while (get_next_line(fd, &line) > 0)
	{
		data->nb_lines++;
		if (data->setting_name == 1 || data->setting_comment == 1
			|| (line_kind(line) < 5 && line_kind(line) >= 0))
			ft_check_name_comment(line, data, line_kind(line));
		else if (line_kind(line) == 5)
			ft_check_label(line, data);
		else if (line_kind(line) >= 10 && data->header_is_parsed == 1)
			ft_check_instr(line, line_kind(line) / 10, data);
		else
			ft_error(1);
		free(line);
	}
	if (!ft_labelexist(data))
		ft_error(1);
	(data->line_inst == 0) ? ft_error(2) : NULL;
	free_data(data);
}
