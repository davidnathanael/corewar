/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_lh_modifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 09:43:33 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/26 11:00:37 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_type		ft_apply_l_modifier(t_specifier specifier)
{
	t_type		type;

	type = NO_TYPE;
	if (specifier == INT || specifier == I_INT || specifier == LONG)
		type = T_LONG;
	else if (specifier == UNS_OCTAL || specifier == UNS_LONG_OCTAL
			|| specifier == UNS_INT || specifier == UNS_LONG
			|| specifier == UNS_HEXA || specifier == UNS_HEXA_MAJ
			|| specifier == BINARY)
		type = T_UNS_LONG;
	else if (specifier == CHAR)
		type = T_WCHAR_T;
	else if (specifier == STR)
		type = T_WCHAR_T_PTR;
	else if (specifier == PTR)
		type = T_VOID_PTR;
	else
		type = T_NOT_VALID_TYPE;
	return (type);
}

t_type		ft_apply_ll_modifier(t_specifier specifier)
{
	t_type		type;

	type = NO_TYPE;
	if (specifier == INT || specifier == I_INT
		|| specifier == LONG)
		type = T_LONG_LONG;
	else if (specifier == UNS_OCTAL || specifier == UNS_INT
		|| specifier == UNS_LONG_OCTAL || specifier == UNS_LONG
		|| specifier == UNS_HEXA || specifier == UNS_HEXA_MAJ
		|| specifier == BINARY)
		type = T_UNS_LONG_LONG;
	else
		type = T_NOT_VALID_TYPE;
	return (type);
}

t_type		ft_apply_h_modifier(t_specifier specifier)
{
	t_type		type;

	type = NO_TYPE;
	if (specifier == INT || specifier == I_INT)
		type = T_SHORT;
	else if (specifier == UNS_LONG)
		type = T_UNS_LONG;
	else if (specifier == UNS_OCTAL || specifier == UNS_LONG_OCTAL
		|| specifier == UNS_INT || specifier == UNS_LONG || specifier == LONG
		|| specifier == UNS_HEXA || specifier == UNS_HEXA_MAJ
		|| specifier == BINARY)
		type = T_UNS_SHORT;
	else
		type = T_NOT_VALID_TYPE;
	return (type);
}

t_type		ft_apply_hh_modifier(t_specifier specifier)
{
	t_type		type;

	type = NO_TYPE;
	if (specifier == INT || specifier == I_INT)
		type = T_CHAR;
	else if (specifier == UNS_OCTAL || specifier == UNS_INT
		|| specifier == UNS_HEXA || specifier == UNS_HEXA_MAJ
		|| specifier == BINARY)
		type = T_UNS_CHAR;
	else if (specifier == UNS_LONG_OCTAL || specifier == UNS_LONG
		|| specifier == LONG)
		type = T_UNS_SHORT;
	else
		type = T_NOT_VALID_TYPE;
	return (type);
}
