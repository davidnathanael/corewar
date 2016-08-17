/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 13:26:11 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/08/17 19:00:41 by vbaudin          ###   ########.fr       */
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
}

static void	free_data(t_parse *data)
{
	ft_memdel((void **)&data->name);
	ft_memdel((void **)&data->comment);
	ft_memdel((void **)&data);
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
	(data->line_inst == 0) ? ft_error(2) : NULL;
	free_data(data);
}
