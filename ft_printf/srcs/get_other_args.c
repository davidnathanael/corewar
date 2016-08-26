/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_other_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 09:11:59 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/28 10:23:15 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <inttypes.h>
#include "ft_printf.h"
#include "libft.h"

wchar_t		*ft_set_unvalid_type(t_options *options)
{
	char	*str;

	str = ft_strnew(1);
	str[0] = options->specifier;
	return ((wchar_t *)str);
}

wchar_t		*ft_get_ptr_arg(t_options *options, va_list ap)
{
	wchar_t		*arg;
	t_type		type;

	arg = NULL;
	type = options->type;
	if (type == T_WCHAR_T_PTR)
		arg = ft_wstrdup(va_arg(ap, wchar_t *));
	else if (type == T_CHAR_PTR)
		arg = (wchar_t *)ft_strdup(va_arg(ap, char *));
	else if (type == T_VOID_PTR)
		arg = (wchar_t *)ft_itoa_base(va_arg(ap, unsigned long), "0123456789");
	else if (type == T_NOT_VALID_TYPE)
		arg = ft_set_unvalid_type(options);
	return (arg);
}

wchar_t		*ft_get_wint_arg(t_options *options, va_list ap)
{
	wchar_t		*arg;

	(void)options;
	arg = (wchar_t *)malloc(sizeof(wchar_t) * 2);
	arg[0] = (wchar_t)va_arg(ap, wint_t);
	return (arg);
}
