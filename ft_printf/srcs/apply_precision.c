/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 23:19:33 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/03/11 16:26:09 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "printf.h"

char			*ft_apply_precision(t_options *options, char *arg)
{
	char	*ret;
	char	*tmp;
	size_t	len;

	ret = ft_strdup(arg);
	tmp = ret;
	len = (arg[0] == '-') ? ft_strlen(arg) - 1 : ft_strlen(arg);
	if ((int)len < options->precision)
		ret = ft_prepend_zero(options->precision, ret);
	else if (options->precision == 0 && ft_atoi(arg) == 0)
	{
		ret = ft_strdup("");
		free(tmp);
	}
	return (ret);
}

char			*ft_apply_precision_str(t_options *options, char *arg)
{
	char	*ret;
	char	*zero;

	ret = NULL;
	zero = NULL;
	if (!arg)
		ret = ft_get_zero(options->precision);
	else
	{
		if (ft_strlen(ft_strtrim((char *)arg)) > (size_t)options->precision)
			ret = ft_strsub(arg, 0, (size_t)options->precision);
		else
			ret = ft_strdup(arg);
	}
	return (ret);
}

char			*ft_apply_precision_ptr(t_options *options, char *arg,
									unsigned long atoi)
{
	char	*ret;
	char	*zero;

	ret = NULL;
	zero = NULL;
	if (atoi == 0)
	{
		if (options->precision == 0)
			return (ft_strdup("0x"));
		else if (options->precision > 0)
			ret = ft_get_zero(options->precision);
	}
	else
	{
		arg = ft_itoa_base(atoi, "0123456789abcdef");
		if ((int)ft_strlen(arg) < options->precision)
			ret = ft_strjoin(ft_get_zero(options->precision - \
								ft_strlen(arg)), arg);
		else
			ret = ft_strdup(arg);
	}
	return (ft_strjoin("0x", ret));
}

wchar_t			*ft_apply_precision_wstr(t_options *options, wchar_t *arg)
{
	wchar_t	*ret;

	ret = NULL;
	if (!arg)
		ret = ft_get_zero_wstr(options->precision);
	else
	{
		if (ft_wstrlen(arg) > options->precision)
			ret = ft_wstrsub(arg, 0, options->precision);
		else
			ret = ft_wstrdup(arg);
	}
	return (ret);
}
