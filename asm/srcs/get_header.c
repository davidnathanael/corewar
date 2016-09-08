/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 17:44:12 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/09/08 15:31:56 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				ft_cnt_setting(char *line, t_header *header)
{
	int			i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '"')
			header->setting++;
		i++;
	}
	return (1);
}

static void		ft_name_chr(t_header *header, char *line)
{
	ft_cnt_setting(line, header);
	if (header->setting != 2)
	{
		if (!header->tmp)
			header->tmp = ft_strdup(line);
		else
			header->tmp = ft_strjoin(header->tmp, line);
	}
	else
	{
		if (header->tmp)
		{
			ft_get_headername(ft_strjoin(header->tmp, line), header);
			ft_strdel(&(header->tmp));
		}
		else
			ft_get_headername(line, header);
		header->isset_name = 1;
		header->setting = 0;
	}
}

static void		ft_comment_chr(t_header *header, char *line)
{
	ft_cnt_setting(line, header);
	if (header->setting != 2)
	{
		if (line && line[0])
		{
			if (!header->tmp)
				header->tmp = ft_strdup(line);
			else
				header->tmp = ft_strjoin(header->tmp, line);
		}
	}
	else
	{
		if (header->tmp)
		{
			ft_get_headercomment(ft_strjoin(header->tmp, line), header);
			ft_strdel(&(header->tmp));
		}
		else
			ft_get_headercomment(line, header);
		header->isset_comment = 1;
	}
}

t_header		*ft_get_header(int fd)
{
	t_header	*header;
	char		*line;
	int			kind;

	header = ft_initheader();
	while (get_next_line(fd, &line) > 0 && (!header->isset_name || !header->isset_comment))
	{
		kind = line_kind(line);
		if ((kind == IS_CHAMP_NAME || header->tmp) && !header->isset_name)
			ft_name_chr(header, line);
		else if ((kind == IS_CHAMP_COMMENT || header->tmp) && !header->isset_comment)
			ft_comment_chr(header, line);
		free(line);
	}
	return (header);
}
