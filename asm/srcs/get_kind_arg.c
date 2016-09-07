/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_kind_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 11:47:05 by vbaudin           #+#    #+#             */
/*   Updated: 2016/08/23 16:02:36 by vbaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	check_t_ind(char *arg, t_parse *data)
{
	int		i;
	char		*label_name;

	i = 0;
	if (arg[i] == LABEL_CHAR && arg[i + 1])
	{
		label_name = ft_strsub(arg, i + 1, ft_strlen(arg) - i - 1);
		get_new_label(label_name, A_VERIF, data);
		ft_memdel((void**)&label_name);
	}
	else
	{
		i = (arg[0] == '-') ? 1 : 0;
		if (!arg[i])
			ft_free_and_exit(data, arg, 6);
		while (arg[i] != '\0')
		{
			if (!ft_isdigit(arg[i]))
				ft_free_and_exit(data, arg, 6);
			i++;
		}
	}
	return (T_IND);
}

static int	check_t_dir(char *arg, t_parse *data)
{
	int		i;
	char	*label_name;

	i = 0;
	if (arg[i + 1] == LABEL_CHAR && arg[i + 2] != '\0')
	{
		label_name = ft_strsub(arg, i + 2, ft_strlen(arg) - i - 2);
		get_new_label(label_name, A_VERIF, data);
		ft_memdel((void**)&label_name);
	}
	else if (ft_isdigit(arg[i + 1]) || (arg[i + 1] == '-'
				&& ft_isdigit(arg[i + 2])))
	{
		i += (arg[i + 1] == '-') ? 1 : 0;
		while (arg[++i] != '\0')
			if (!ft_isdigit(arg[i]))
				ft_free_and_exit(data, arg, 6);
	}
	else
		ft_free_and_exit(data, arg, 6);
	return(T_DIR);
}

static int	check_t_reg(char *arg, t_parse *data)
{
	int		i;

	i = 1;
	while (arg[i] != '\0')
	{
		if (!ft_isdigit(arg[i]))
			ft_free_and_exit(data, arg, 6);
		else
			i++;
	}
	i = ft_atoi(&arg[1]);
	if (!(i > 0 && i <= REG_NUMBER))
		ft_free_and_exit(data, arg, 6);
	return(T_REG);
}

int			get_kind_arg(char *arg, t_parse *data)
{
	int		t_kind;

	t_kind = 0;
	if (ft_isdigit(arg[0]) || ((arg[0] == '-') && arg[1] && ft_isdigit(arg[1])) || arg[0] == LABEL_CHAR)
		t_kind = check_t_ind(arg, data);
	else if (arg[0] == DIRECT_CHAR)
		t_kind = check_t_dir(arg, data);
	else if (arg[0] == 'r')
		t_kind = check_t_reg(arg, data);
	return (t_kind);
}
