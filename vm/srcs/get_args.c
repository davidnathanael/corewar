/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 14:48:50 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/09/02 14:48:51 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_args	*ft_get_args(t_vm *vm, t_process *process, t_op *data)
{
	t_args		*args;
	int			cursor;
	int			offset;
	int			i;

	if (!(args = (t_args *)ft_memalloc(sizeof(t_args))))
		ft_exit_error("Malloc args failed.", NULL);
	args->nb_args = data->nb_args;
	cursor = process->pc;
	offset = 6;
	i = 0;
	if (data->needs_prefix)
	{
		while (offset > 0)
		{
			args->types[i] = (vm->memory[cursor + 1] >> offset) & 0x3;
			offset -= 2;
			i++;
		}
	}
	i = 0;
	while (i < 4)
	{
		ft_printf("i : %d | type : %b\n", i, args->types[i]);
		i++;
	}
	exit(0);
	return (args);
}
