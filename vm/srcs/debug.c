/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 01:44:10 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/09/03 01:48:52 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_debug_memory(unsigned char *memory, int cursor, int size)
{
	int	i = 0;

	ft_printf("{red}================{eoc}\nDebugging memory from %d for %d octets...\n\n", cursor, size);
	while (i < size)
	{
		if ((i + cursor) >= MEM_SIZE)
		{
			ft_putendl("\n\nReached end of memory\n");
			break ;
		}
		ft_printf("%02X ", memory[i + cursor]);
		if (i && i % 32 == 0)
			ft_putchar('\n');
		i++;
	}
	ft_printf("\n{red}================{eoc}\n\n");
}
