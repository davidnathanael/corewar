/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 21:28:38 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/03/11 17:26:00 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

int			ft_get_width(char *format, va_list ap)
{
	int		i;
	int		ret;
	char	*fmt;
	char	*tmp;

	i = 0;
	ret = 0;
	fmt = format;
	tmp = ft_strnew(ft_strlen(format));
	while (!ft_isdigit(*fmt) && *fmt != '.' && *fmt != '*' && *fmt)
		if (*(++fmt) == F_ZERO)
			fmt++;
	if (*fmt == '*' && ft_isdigit(*(fmt + 1)))
	{
		ret = va_arg(ap, int);
		fmt++;
	}
	while (ft_isdigit(*fmt) && *fmt)
		tmp[i++] = *(fmt++);
	if (i > 0)
		ret = ft_atoi(tmp);
	if (*fmt == '*')
		ret = va_arg(ap, int);
	free(tmp);
	return (ret);
}

char		*ft_get_spaces(t_width width)
{
	char	*spaces;
	int		i;

	spaces = ft_strnew(width);
	i = 0;
	if (!spaces)
		return (NULL);
	while (i < width)
	{
		spaces[i] = ' ';
		i++;
	}
	return (spaces);
}

size_t		ft_get_len4width(t_options *options, char *arg)
{
	t_width			width;
	t_specifier		specifier;
	t_flags			*flags;
	int				len;

	width = options->width;
	specifier = options->specifier;
	flags = options->flags;
	len = (options->type == T_CHAR) ? 1 : ft_strlen(arg);
	if (flags->sharp && flags->minus && (specifier == UNS_OCTAL
									|| specifier == UNS_LONG_OCTAL))
		len++;
	else if (flags->sharp && flags->minus && (specifier == UNS_HEXA
									|| specifier == UNS_HEXA_MAJ))
		len += 2;
	else if (flags->plus && arg[0] != '-' && flags->minus
			&& (T_INT <= options->type && options->type <= T_SSIZE_T))
		len++;
	return (len);
}

char		*ft_apply_width(t_options *options, char *arg, void *orig_arg)
{
	size_t	len;
	char	*ret;
	char	*spaces;

	len = ft_get_len4width(options, arg);
	ret = arg;
	spaces = NULL;
	if (!ret)
		return (NULL);
	if (options->width > (int)len)
	{
		spaces = ft_get_spaces(options->width - len);
		if (options->flags->minus ||
			(options->type == T_VOID_PTR && options->flags->zero))
			ret = ft_strjoin(arg, spaces);
		else
			ret = ft_strjoin(spaces, arg);
	}
	if (arg != orig_arg)
		free(arg);
	free(spaces);
	return (ret);
}
