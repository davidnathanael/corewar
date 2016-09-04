/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_name_comment.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 18:31:12 by vbaudin           #+#    #+#             */
/*   Updated: 2016/08/17 17:26:49 by vbaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		get_end_name_comment(char *line, t_parse *data)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (line[i] != '\0' && j < 2)
		if (line[i++] == '"')
			j++;
	k = i;
	j = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '\t' && j == 0)
		{
			if (line[i] == ';' || line[i] == '#')
				j = 1;
			else
				ft_free_and_exit(data, NULL, 1);
		}
		i++;
	}
	return (k);
}

static int		get_start_name_comment(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '0' && line[i] != '"')
		i++;
	return (i + 1);
}

void			ft_end_name_comment(t_parse *data)
{
	char	*tmp;
	int		end;
	int		start;

	start = get_start_name_comment(data->name);
	end = get_end_name_comment(data->name, data);
	tmp = ft_strdup(data->name);
	ft_memdel((void **)&data->name);
	data->name = ft_strsub(tmp, start, end - start - 1);
	ft_memdel((void **)&tmp);
	start = get_start_name_comment(data->comment);
	end = get_end_name_comment(data->comment, data);
	tmp = ft_strdup(data->comment);
	ft_memdel((void **)&data->comment);
	data->comment = ft_strsub(tmp, start, end - start - 1);
	ft_memdel((void **)&tmp);
	data->header_is_parsed = 1;
}
