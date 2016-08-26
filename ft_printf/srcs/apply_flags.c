/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sharp_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 08:08:08 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/03/11 17:36:00 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

wchar_t	*ft_apply_sharp_flag(t_specifier specifier, t_precision precision,
							t_flags *flags, char *arg)
{
	char	*ret;
	int		spaces;

	ret = NULL;
	spaces = 0;
	while (arg[spaces] == ' ' && arg[spaces])
		spaces++;
	if ((specifier == UNS_OCTAL || specifier == UNS_LONG_OCTAL)
				&& arg[0] != '0')
	{
		if (spaces >= 1)
		{
			arg[spaces - 1] = '0';
			ret = arg;
		}
		else
			ret = ft_strjoin("0", (char *)arg);
	}
	else if (specifier == UNS_HEXA || specifier == UNS_HEXA_MAJ)
		ret = ft_apply_sharp_flag_hexa(specifier, precision, flags, arg);
	else
		ret = ft_strdup(arg);
	return ((wchar_t *)ret);
}

wchar_t	*ft_apply_zero_flag(t_width width, char *arg)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (arg[i])
		len = (arg[i++] == ' ') ? len + 1 : len;
	len = (unsigned int)ft_strlen(arg) - len;
	i = 0;
	while (arg[i] && (int)len < (int)width)
	{
		if (arg[i] == ' ')
			arg[i] = '0';
		else if (arg[i] && arg[i] == '-' && ft_isdigit(arg[i + 1]))
		{
			arg[i] = '0';
			arg[0] = '-';
		}
		i++;
	}
	return ((wchar_t *)arg);
}

wchar_t	*ft_apply_space_flag(t_specifier specifier, char *arg)
{
	if (arg[0] != '-')
	{
		if (specifier == INT || specifier == I_INT)
		{
			if (arg[0] == '0')
				arg[0] = ' ';
			else if (arg[0] != ' ')
				arg = ft_strjoin(" ", arg);
		}
	}
	return ((wchar_t *)arg);
}

wchar_t	*ft_apply_plus_flag(t_options *options, char *arg)
{
	unsigned int	i;
	char			*ret;

	i = 0;
	ret = arg;
	while (ret[i] && (!ft_isdigit(ret[0])) && ret[0])
	{
		if (ret[i] == '-')
			break ;
		if (ft_isdigit(ret[i]))
		{
			ret[i - 1] = '+';
			break ;
		}
		i++;
	}
	if (*ret && ft_isdigit(ret[0]) && ret[0])
	{
		if (ret[0] == '0' && ret[1] && options->flags->zero)
			ret[0] = '+';
		else
			ret = ft_strjoin("+", arg);
	}
	return ((wchar_t *)ret);
}

wchar_t	*ft_apply_flags(t_options *options, wchar_t *arg, void *orig_arg)
{
	wchar_t		*ret;

	ret = arg;
	if (options->flags->zero && options->type == T_WCHAR_T_PTR)
		ret = ft_apply_zero_flag_wstr(options->width, ret);
	else if (options->flags->zero)
		ret = ft_apply_zero_flag(options->width, (char *)ret);
	if (options->flags->sharp && ft_strchr("oOxX", options->specifier))
		ret = ft_apply_sharp_flag(options->specifier, options->precision,
								options->flags, (char *)ret);
	if (options->flags->space)
		ret = ft_apply_space_flag(options->specifier, (char *)ret);
	if (options->flags->plus
		&& ((T_INT <= options->type && options->type <= T_SHORT)
		|| options->type == T_INTMAX_T))
		ret = ft_apply_plus_flag(options, (char *)ret);
	(void)orig_arg;
	return (ret);
}
