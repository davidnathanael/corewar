/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_instr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudin <vbaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 15:54:52 by vbaudin           #+#    #+#             */
/*   Updated: 2016/08/23 16:31:36 by vbaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	get_line(int opcode)
{
	int		i;

	i = 0;
	while (g_op_tab[i].name != 0)
	{
		if (g_op_tab[i].code == opcode)
			return (i);
		else
			i++;
	}
	return (-1);
}

static char	*get_instruction(char *line)
{
	char	*line_t;
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strtrim(line);
	while (tmp[i] != '\0' && tmp[i] != COMMENT_CHAR && tmp[i] != ';')
		i++;
	line_t = ft_strsub(tmp, 0, i);
	ft_memdel((void **)&tmp);
	return (line_t);
}

void		ft_check_instr(char *line, int opcode, t_parse *data)
{
	char	**instr;
	char	*in_line;
	char	*tmp;
	int		i;

	i = ft_strlen(g_op_tab[get_line(opcode)].name);
	tmp = get_instruction(line);
	in_line = ft_strsub(tmp, i, ft_strlen(tmp) - 1);
	ft_memdel((void **)&tmp);
	i = 0;
	instr = ft_strsplit(in_line, SEPARATOR_CHAR);
	while (instr[i] != NULL)
	{
		tmp = ft_strtrim(instr[i]);
		if (!(get_kind_arg(tmp, data) && g_op_tab[get_line(opcode)].type_arg[i]))
			ft_free_and_exit(data, tmp, 6);
		ft_memdel((void **)&tmp);
		ft_memdel((void **)&instr[i]);
		i++;
	}
	ft_memdel((void **)&instr);
	ft_memdel((void **)&in_line);
	if (i < g_op_tab[get_line(opcode)].nb_args)
		ft_free_and_exit(data, NULL, 6);
	data->line_inst++;
}
