/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 09:26:34 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/28 10:23:06 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "printf.h"
#include "libft.h"

int				ft_get_precision(char *format, va_list ap)
{
	int		i;
	int		ret;
	char	*fmt;
	char	*tmp;

	i = 0;
	ret = -1;
	fmt = format;
	tmp = ft_strnew(ft_strlen(format));
	if (!tmp)
		return (ERR_STRNEW);
	if ((fmt = ft_strchr(fmt, '.')))
	{
		if (ft_strchr(fmt, '*'))
			ret = va_arg(ap, int);
		else
		{
			while (++fmt && *fmt && ft_isdigit(*fmt))
				tmp[i++] = *fmt;
			ret = (i == 0) ? 0 : ft_atoi(tmp);
		}
	}
	free(tmp);
	return (ret);
}

char			*ft_prepend_zero(t_precision precision, char *arg)
{
	char	*ret;
	char	*arg_tmp;
	size_t	i;
	size_t	len_zero;
	t_bool	is_negative;

	ret = NULL;
	arg_tmp = arg;
	i = 0;
	len_zero = (size_t)precision - ft_strlen(arg);
	is_negative = arg_tmp[0] == '-' ? TRUE : FALSE;
	ret = ft_strnew(is_negative + precision);
	if (is_negative)
	{
		ret[i++] = '-';
		len_zero += 2;
		arg_tmp++;
	}
	while (i < len_zero)
		ret[i++] = '0';
	while (*arg_tmp)
		ret[i++] = *(arg_tmp++);
	free(arg);
	return (ret);
}

char			*ft_get_zero(int len)
{
	char	*ret;

	ret = ft_strnew((size_t)len);
	if (!ret)
		return (NULL);
	while (len)
		ret[--len] = '0';
	return (ret);
}

wchar_t			*ft_get_zero_wstr(int len)
{
	wchar_t	*ret;

	ret = ft_memalloc(len * sizeof(wchar_t) + 1);
	if (!ret)
		return (NULL);
	while (len)
		ret[--len] = '0';
	return (ret);
}
