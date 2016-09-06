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

int		ft_expected_instr(int opcode, int instr, int i)
{
	int	tmp;

	tmp = g_op_tab[get_line(opcode)].type_arg[i];
	if (tmp == T_REG + T_DIR + T_IND)
		return (1);
	if (tmp == T_REG + T_DIR && (instr == T_REG || instr == T_DIR))
		return (1);
	if (tmp == T_REG + T_IND && (instr == T_REG || instr == T_IND))
		return (1);
	if (tmp == T_DIR + T_IND && (instr == T_DIR || instr == T_IND))
		return (1);
	if (tmp == instr)
		return (1);
	return (0);
}

void		ft_check_tab(char *in_line, int opcode, t_parse *data)
{
	int	i;
	int	n;
	char	*tmp;
	char	**instr;

	i = 0;

	instr = ft_strsplit(in_line, SEPARATOR_CHAR);
	ft_memdel((void **)&in_line);
	while (instr[i] != NULL)
	{
		tmp = ft_strtrim(instr[i]);
		ft_memdel((void **)&instr[i]);
		if (!(n = get_kind_arg(tmp, data)) || !ft_expected_instr(opcode, n, i))
			ft_free_and_exit(data, tmp, 6);
		ft_memdel((void **)&tmp);
		i++;
	}
	ft_memdel((void **)&instr);
	if (i < g_op_tab[get_line(opcode)].nb_args)
		ft_free_and_exit(data, NULL, 6);
}

void		ft_check_instr(char *line, int opcode, t_parse *data)
{
	char	*in_line;
	char	*tmp;
	int		i;

	i = ft_strlen(g_op_tab[get_line(opcode)].name);
	tmp = get_instruction(line);
	if (!ft_check_separator(tmp))
		ft_free_and_exit(data, tmp, 6);
	in_line = ft_strsub(tmp, i, ft_strlen(tmp) - 1);
	ft_memdel((void **)&tmp);
	ft_check_tab(in_line, opcode, data);
	data->line_inst++;
}
