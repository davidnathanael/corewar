/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 13:26:11 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/08/15 14:49:45 by vbaudin          ###   ########.fr       */
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
	data->line_header = 0;
	data->line_inst = 0;
	data->nb_lines = 0;
}

void	ft_parse(char *file)
{
	int		fd;
	char	*line;
	t_parse	*data;

	fd = open(file, O_RDONLY);
	if (!(data = (t_parse *)malloc(sizeof(t_parse))))
		exit(0);
	init(data);
	while (get_next_line(fd, &line) > 0)
	{
		data->nb_lines++;
		if (data->setting_name == 1 || data->setting_comment == 1
			|| (line_kind(line) < 5 && line_kind(line) >= 0))
			ft_check_name_comment(line, data, line_kind(line));
		free(line);
	}
}
