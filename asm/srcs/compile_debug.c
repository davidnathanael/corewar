/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile_debug.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 21:31:48 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/08/22 21:31:49 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_debug_instruction(t_inst *instruction)
{
	int i = 0;
	ft_printf("{bold}LABEL   -> {green}%s{eoc}\n", instruction->label);
	ft_printf("{bold}OPCODE  -> {green}%s{eoc}\n", instruction->opcode);
	ft_printf("{bold}NB_ARGS -> {green}%d{eoc}\n", instruction->nb_args);
	ft_printf("{bold}SIZE    -> {green}%d{eoc}\n", instruction->size);
	ft_printf("{bold}ARGS\n");
	while (i < instruction->nb_args)
		ft_printf("  -> {green}%s{eoc}\n", instruction->args[i++]);
	ft_putchar('\n');
}
