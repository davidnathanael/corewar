/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_coding_byte.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 17:13:18 by vbaudin           #+#    #+#             */
/*   Updated: 2016/09/08 17:58:47 by vbaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_handle_coding_byte(int cursor, t_vm *vm, int op)
{
	unsigned char	encoding;
	int				offset;

	offset = 6;
	encoding = vm->memory[ft_loop_memory(cursor + 1)];
	cursor++;
	while ((encoding >> offset) & 0b11)
	{
		if (((encoding >> offset) & 0b11) == REG_CODE)
			cursor++;
		else if (((encoding >> offset) & 0b11) == DIR_CODE)
			cursor += ft_get_op_data(op)->label_size;
		else if (((encoding >> offset) & 0b11) == IND_CODE)
			cursor += 2;
		offset -= 2;
	}
	cursor = ft_loop_memory(cursor);
	return (cursor);
}
