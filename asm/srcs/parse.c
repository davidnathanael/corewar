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

void	free_data(t_parse *data)
{
	t_label	*c_label;

	if (data->name)
		ft_memdel((void **)&data->name);
	if (data->comment)
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

char	*ft_free_and_trim(char *line)
{
	char	*tmp;

	tmp = ft_strtrim(line);
	ft_strdel(&line);
	return (tmp);
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
		line = ft_free_and_trim(line);
		if (data->setting_name == 1 || data->setting_comment == 1
			|| (line_kind(line) < 5 && line_kind(line) >= 0))
			ft_check_name_comment(line, data, line_kind(line));
		else if (line_kind(line) == 5)
			ft_check_label(line, data);
		else if (line_kind(line) >= 10 && data->header_is_parsed == 1)
			ft_check_instr(line, line_kind(line) / 10, data);
		else
			ft_free_and_exit(data, line, 1);
		ft_strdel(&line);
	}
	!ft_labelexist(data) ? ft_free_and_exit(data, NULL, 1) : NULL;
	(data->line_inst == 0) ? ft_free_and_exit(data, NULL, 2) : NULL;
	free_data(data);
}
