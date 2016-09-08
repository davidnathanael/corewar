/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 15:23:52 by vbaudin           #+#    #+#             */
/*   Updated: 2016/09/08 17:56:47 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_error(int i)
{
	if (i == 1)
		ft_putendl("Syntax Error.");
	else if (i == 2)
		ft_putendl("End of File with no instructions.");
	else if (i == 3)
		ft_putendl("Your file doesn't seems to be a .s file.");
	else if (i == 4)
		ft_putendl("This file doesn't exist.");
	else if (i == 5)
		ft_putendl("Malloc Error.");
	else if (i == 6)
		ft_putendl("Op Args Invalid.");
	else if (i == 7)
		ft_putendl("ft_check_label error.");
	else if (i == 8)
		ft_putendl("Can't open file.");
	else if (i == 9)
		ft_putendl("Corrupted binary file.");
	exit(0);
}

void	ft_free_and_exit(t_parse *data, char *line, int n)
{
	if (data)
		free_data(data);
	if (line)
		ft_strdel(&line);
	ft_error(n);
}
