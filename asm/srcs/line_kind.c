/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_kind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 12:56:22 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/08/19 13:52:20 by vbaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_instr(char *line_t)
{
	char	*instr;
	int		i;

	i = 0;
	while (line_t[i] != '\0' && line_t[i] != ' ' && line_t[i] != '\t')
		i++;
	instr = ft_strsub(line_t, 0, i);
	i = 0;
	while (g_op_tab[i].name != 0)
	{
		if (ft_strcmp(instr, g_op_tab[i].name) == 0)
		{
			ft_memdel((void **)&instr);
			return (g_op_tab[i].code * 10);
		}
		i++;
	}
	ft_memdel((void **)&instr);
	return (-1);
}

static int	is_label(char *line_t)
{
	int		i;
	int		ret;
	char	*lc;

	lc = ft_strdup(LABEL_CHARS);
	i = 0;
	ret = -1;
	while (line_t[i] == '\0')
	{
		if (line_t[i] == LABEL_CHAR && i > 0)
		{
			ret = 1;
			break;
		}
		else if (ft_strchr(lc, line_t[i]) == NULL)
			break;
		else
			i++;
	}
	ft_memdel((void **)&lc);
	return (ret);
}

int			line_kind(char *line)
{
	char	*line_t;
	int		ret;

	ret = 0;
	line_t = ft_strtrim(line);
	if (line_t[0] == '\0')
		ret = 0;
	else if (line_t[0] == COMMENT_CHAR)
		ret = 1;
	else if (line_t[0] == ';')
		ret = 2;
	else if (ft_strncmp(line_t, NAME_CMD_STRING, 
				ft_strlen(NAME_CMD_STRING)) == 0)
		ret = 3;
	else if (ft_strncmp(line_t, COMMENT_CMD_STRING, 
				ft_strlen(COMMENT_CMD_STRING)) == 0)
		ret = 4;
	else if (is_label(line_t))
		ret = 5;
	ft_memdel((void **)&line_t);
	return (ret);
}
