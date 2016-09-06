/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 01:44:10 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/09/03 18:49:49 by vbaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_dump_memory(unsigned char *memory, int cursor, int size)
{
	int	i;

	i = 0;
	ft_printf("\e[2J\e[H");
	ft_printf("{red}==============================={eoc}\n");
	ft_printf("Debugging memory from %d for %d octets...\n\n", cursor, size);
	while (i < size)
	{
		if ((i + cursor) >= MEM_SIZE)
		{
			ft_putendl("\n\nReached end of memory\n");
			break ;
		}
		if (i && i % 64 == 0)
			ft_putchar('\n');
		ft_printf("%02X ", memory[i + cursor]);
		i++;
	}
	ft_printf("\n{red}==============================={eoc}\n\n");
	exit(0);
}
