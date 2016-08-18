/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_kind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 12:56:22 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/08/15 16:47:33 by vbaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
	ft_memdel((void **)&line_t);
	return (ret);
}
