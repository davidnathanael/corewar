/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 14:28:56 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/03/14 14:41:35 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "libft.h"
#include "printf.h"

static int				ft_get_args(t_options *options, va_list ap)
{
	wchar_t			*arg;
	size_t			ret;
	t_type			type;

	arg = NULL;
	ret = 0;
	type = options->type;
	if (NO_TYPE < type && type < T_UNS_INT)
		arg = (wchar_t *)ft_get_signed_args(options, ap);
	else if (T_INTMAX_T < type && type <= T_SSIZE_T)
		arg = (wchar_t *)ft_get_unsigned_args(options, ap);
	else if (type == T_WCHAR_T)
		arg = ft_get_wint_arg(options, ap);
	else if (T_WCHAR_T_PTR <= type && type <= T_NOT_VALID_TYPE)
		arg = ft_get_ptr_arg(options, ap);
	ret = ft_proceed(options, arg);
	free(arg);
	free(options->flags);
	return (ret);
}

static t_options		*ft_get_options(char *format, va_list ap)
{
	t_options	*options;
	char		*subformat;

	options = (t_options *)malloc(sizeof(t_options));
	if (!options)
		return (NULL);
	subformat = ft_strsub(format, 0, ft_skip(format) + 1);
	if (!subformat)
	{
		free(options);
		return (NULL);
	}
	options->flags = ft_get_flags(subformat);
	options->width = ft_get_width(subformat, ap);
	options->precision = ft_get_precision(subformat, ap);
	options->modifier = ft_get_modifier(subformat);
	options->specifier = subformat[ft_strlen(subformat) - 1];
	options->type = 0;
	options->flags = ft_check_flags(options, format);
	if (options->width < 0)
		options->width = -options->width;
	free(subformat);
	return (options);
}

int				ft_do_format(char *format, va_list ap)
{
	int			printed;
	t_options	*options;

	printed = 0;
	options = ft_get_options(format, ap);
	if (!options)
		return (ERROR);
	options = ft_apply_modifier(options);
	printed = ft_get_args(options, ap);
	free(options);
	return (printed);
}
