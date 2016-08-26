/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 16:22:03 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/08/25 16:22:05 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_exit_error(char *error, char *var)
{
	ft_putstr("Error : ");
	ft_putstr(error);
	if (var)
		ft_putstr(var);
	ft_putchar('\n');
	exit(-1);
}
