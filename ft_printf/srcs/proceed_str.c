/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proceed_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 21:13:33 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/03/11 16:43:17 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <locale.h>
#include "printf.h"
#include "libft.h"

int		ft_proceed_str(t_options *options, char *arg)
{
	int		ret;
	char	*to_print;

	ret = 0;
	to_print = arg;
	if (options->precision >= 0)
		to_print = ft_apply_precision_str(options, to_print);
	if (options->width > 0)
		to_print = ft_apply_width(options, to_print, arg);
	if (ft_has_flags(options->flags) && to_print)
		to_print = (char *)ft_apply_flags(options, (wchar_t *)to_print, arg);
	ret = ft_putstr(to_print);
	return (ret);
}

int		ft_proceed_char(t_options *options, char *arg)
{
	int		ret;
	char	*to_print;

	ret = 0;
	to_print = ft_strnew(1);
	to_print[0] = (unsigned char)ft_atoi(arg);
	if (options->precision >= 0)
		to_print = ft_apply_precision_str(options, to_print);
	if (options->width > 0)
		to_print = ft_apply_width(options, to_print, arg);
	if (ft_has_flags(options->flags) && to_print)
		to_print = (char *)ft_apply_flags(options, (wchar_t *)to_print, arg);
	if (ft_atoi(arg) == 0)
	{
		if (options->flags->minus)
			ft_putchar((unsigned char)ft_atoi(arg));
		ret = ft_putstr(to_print);
		if (!options->flags->minus)
			ft_putchar((unsigned char)ft_atoi(arg));
		ret++;
	}
	else
		ret = ft_putstr(to_print);
	return (ret);
}
