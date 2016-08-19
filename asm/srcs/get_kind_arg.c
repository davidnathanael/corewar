/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_kind_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 11:47:05 by vbaudin           #+#    #+#             */
/*   Updated: 2016/08/19 12:47:46 by vbaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	check_t_ind(char *arg, t_parse *data)
{
	(void)arg;
	(void)data;
	return(0);
}

static int	check_t_dir(char *arg, t_parse *data)
{
	(void)arg;
	(void)data;
	return(0);
}

static int	check_t_reg(char *arg, t_parse *data)
{
/*	int		i;

	i = 1;
	while (arg[1])*/
	(void)arg;
	(void)data;
	return(0);
}

int			get_kind_arg(char *arg, t_parse *data)
{
	int		t_kind;

	t_kind = 0;
	if ((ft_isdigit(arg[0]) || (arg[0] == '-')) && ft_isdigit(arg[1]))
		t_kind = check_t_ind(arg, data);
	else if (arg[0] == '%')
		t_kind = check_t_dir(arg, data);
	else if (arg[0] == 'r')
		t_kind = check_t_reg(arg, data);
	return (t_kind);
}
