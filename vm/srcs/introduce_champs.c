/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   introduce_champs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 12:38:36 by vbaudin           #+#    #+#             */
/*   Updated: 2016/09/02 12:54:08 by vbaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		ft_introduce_champs(t_vm *vm)
{
	int		i;

	i = 0;
	ft_putendl("Let the battle begin...");
	while (i < vm->nb_champs)
	{
		ft_printf("* Player %d, weighing %d bytes, name : %s, comment = %s\n",
				vm->champions[i].champ_nb, vm->champions[i].data_size,
				vm->champions[i].name, vm->champions[i].comment);
		i++;
	}
}
