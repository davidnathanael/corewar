/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proceed.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 08:04:02 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/03/11 16:33:06 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdlib.h"

int		ft_proceed_int_args(t_options *options, wchar_t *arg)
{
	int			ret;
	t_specifier	specifier;
	t_modifier	modifier;
	t_type		type;

	ret = 0;
	specifier = options->specifier;
	modifier = options->modifier;
	type = options->type;
	if (T_INT <= type && type <= T_SSIZE_T && type != T_CHAR)
		ret = ft_proceed_int(options, (char *)arg);
	else if (type == T_CHAR && specifier == CHAR)
		ret = ft_proceed_char(options, (char *)arg);
	else if ((type == T_CHAR || type == T_UNS_CHAR) && modifier == M_HH)
		ret = ft_proceed_int(options, (char *)arg);
	return (ret);
}

int		ft_proceed_wide_args(t_options *options, wchar_t *arg)
{
	int			ret;

	ret = 0;
	if (options->type == T_WCHAR_T)
		ret = ft_proceed_wchar(options, arg);
	else if (options->type == T_WCHAR_T_PTR)
		ret = ft_proceed_wstr(options, arg);
	return (ret);
}

int		ft_proceed_ptr_args(t_options *options, wchar_t *arg)
{
	int			ret;

	ret = 0;
	if (options->type == T_CHAR_PTR)
		ret = ft_proceed_str(options, (char *)arg);
	else if (options->type == T_VOID_PTR)
		ret = ft_proceed_ptr(options, (char *)arg);
	else if (options->type == T_NOT_VALID_TYPE)
		ret = ft_proceed_not_valid_type(options, (char *)arg);
	return (ret);
}

int		ft_proceed(t_options *options, wchar_t *arg)
{
	int			ret;
	t_type		type;

	ret = 0;
	type = options->type;
	if (T_INT <= type && type <= T_SSIZE_T)
		ret = ft_proceed_int_args(options, arg);
	else if (T_WINT_T <= type && type <= T_WCHAR_T_PTR)
		ret = ft_proceed_wide_args(options, arg);
	else if (T_CHAR_PTR <= type && type <= T_NOT_VALID_TYPE)
		ret = ft_proceed_ptr_args(options, arg);
	return (ret);
}
