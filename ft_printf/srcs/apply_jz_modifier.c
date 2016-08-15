/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_jz_modifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 09:47:20 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/26 11:01:24 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_type		ft_apply_j_modifier(t_specifier specifier)
{
	t_type		type;

	type = NO_TYPE;
	if (specifier == INT || specifier == I_INT || specifier == LONG)
		type = T_LONG_LONG;
	else if (specifier == UNS_OCTAL || specifier == UNS_LONG_OCTAL
		|| specifier == UNS_INT || specifier == UNS_LONG
		|| specifier == UNS_HEXA || specifier == UNS_HEXA_MAJ
		|| specifier == BINARY)
		type = T_UNS_LONG_LONG;
	else
		type = T_NOT_VALID_TYPE;
	return (type);
}

t_type		ft_apply_z_modifier(t_specifier specifier)
{
	t_type		type;

	type = NO_TYPE;
	if (specifier == INT || specifier == I_INT || specifier == LONG)
		type = T_SSIZE_T;
	else if (specifier == UNS_OCTAL || specifier == UNS_LONG_OCTAL
		|| specifier == UNS_INT || specifier == UNS_LONG
		|| specifier == UNS_HEXA || specifier == UNS_HEXA_MAJ
		|| specifier == BINARY)
		type = T_SIZE_T;
	else
		type = T_NOT_VALID_TYPE;
	return (type);
}
