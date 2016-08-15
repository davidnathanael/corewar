/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:21:01 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/27 10:52:13 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <libft.h>

t_bool			ft_skip(char *format)
{
	int		i;

	i = 1;
	while ((ft_is_flag(format[i]) || ft_isdigit(format[i])
			|| ft_is_modifier(format[i]) || format[i] == '*') && format[i])
		i++;
	return (i);
}

static t_bool	ft_is_valid_percent(char *format)
{
	if (ft_strcmp(format, "%") == 0)
		return (FALSE);
	if (ft_strcmp(format, "% ") == 0)
		return (FALSE);
	if (ft_strcmp(format, "% h") == 0)
		return (FALSE);
	return (TRUE);
}

int				ft_put(int *printed, char *format)
{
	int		ret;
	char	*to_print;

	ret = 0;
	to_print = NULL;
	while (format[ret] != '%' && format[ret])
		ret++;
	to_print = ft_check_color(ft_strsub(format, 0, ret));
	*printed += ft_putstr(to_print);
	free(to_print);
	return (--ret);
}

static int		ft_print(char *format, va_list ap)
{
	int		ret_do_format;
	int		printed;
	int		*ptr_printed;
	char	*fmt;

	ret_do_format = 0;
	printed = 0;
	ptr_printed = &printed;
	fmt = format;
	while (*fmt)
	{
		if (*fmt != '%' && *fmt)
			fmt += ft_put(ptr_printed, fmt);
		else if (*fmt == '%' && ft_is_valid_percent(fmt))
		{
			ret_do_format = ft_do_format(fmt, ap);
			printed += ret_do_format;
			fmt += ft_skip(fmt);
		}
		else if (!ft_is_valid_percent(fmt))
			break ;
		fmt++;
	}
	return (printed);
}

int				ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	int			ret;

	ret = 0;
	va_start(ap, format);
	ret = ft_print((char *)format, ap);
	va_end(ap);
	return (ret);
}
