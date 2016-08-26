/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proceed_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 21:27:49 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/03/11 17:13:40 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

int		ft_proceed_ptr(t_options *options, char *arg)
{
	int				ret;
	unsigned long	atoi;
	char			*to_print;
	char			*tmp;

	ret = 0;
	atoi = ft_ultoi(arg);
	to_print = arg;
	tmp = NULL;
	if (options->precision >= 0)
		to_print = ft_apply_precision_ptr(options, to_print, atoi);
	else
	{
		tmp = ft_itoa_base(atoi, "0123456789abcdef");
		to_print = ft_strjoin("0x", tmp);
		free(tmp);
	}
	if (options->width > 0)
		to_print = ft_apply_width(options, to_print, arg);
	if (ft_has_flags(options->flags) && to_print)
		to_print = (char *)ft_apply_flags(options, (wchar_t *)to_print, to_print);
	ret = ft_putstr(to_print);
	return (ret);
}

int		ft_proceed_not_valid_type(t_options *options, char *arg)
{
	int	ret;
	char	*to_print;

	ret = 0;
	to_print = arg;
	if (options->width > 0)
		to_print = ft_apply_width(options, to_print, arg);
	if (ft_has_flags(options->flags) && to_print)
		to_print = (char *)ft_apply_flags(options, (wchar_t *)to_print, arg);
	ret = ft_putstr(to_print);
	return (ret);
}
