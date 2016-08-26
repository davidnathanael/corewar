/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 08:47:36 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/03/11 15:46:55 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

static t_flags		*ft_init_flags(void)
{
	t_flags		*flags;

	flags = (t_flags *)malloc(sizeof(t_flags));
	if (!flags)
		return (NULL);
	flags->sharp = FALSE;
	flags->zero = FALSE;
	flags->minus = FALSE;
	flags->plus = FALSE;
	flags->space = FALSE;
	return (flags);
}

/*
** ZERO flag is handled in ft_check_flags
*/

t_flags				*ft_get_flags(char *format)
{
	char		*fmt;
	t_flags		*flags;

	fmt = format;
	flags = ft_init_flags();
	if (!flags)
		return (0);
	while (*fmt)
	{
		if (*fmt == F_SHARP)
			flags->sharp = TRUE;
		if (*fmt == F_MINUS)
			flags->minus = TRUE;
		if (*fmt == F_PLUS)
			flags->plus = TRUE;
		if (*fmt == F_SPACE)
			flags->space = TRUE;
		fmt++;
	}
	return (flags);
}

t_bool				ft_has_flags(t_flags *flags)
{
	if (flags->sharp)
		return (TRUE);
	if (flags->zero)
		return (TRUE);
	if (flags->minus)
		return (TRUE);
	if (flags->plus)
		return (TRUE);
	if (flags->space)
		return (TRUE);
	return (FALSE);
}

t_bool				ft_is_flag(char c)
{
	if (c == ' ')
		return (TRUE);
	if (c == '+')
		return (TRUE);
	if (c == '-')
		return (TRUE);
	if (c == '#')
		return (TRUE);
	if (c == '0')
		return (TRUE);
	if (c == '.')
		return (TRUE);
	return (FALSE);
}

t_flags				*ft_check_flags(t_options *options, char *format)
{
	char			*subformat;
	unsigned int	i;

	subformat = ft_strsub(format, 0, ft_skip(format) + 1);
	i = 0;
	while (ft_strchr(" +-#0%", subformat[i]) && subformat[i])
	{
		if (subformat[i] == '0')
			options->flags->zero = TRUE;
		i++;
	}
	if (options->width < 0)
		options->flags->minus = TRUE;
	if (options->precision > 0)
		options->flags->zero = FALSE;
	if (options->flags->minus)
		options->flags->zero = FALSE;
	if (options->flags->plus)
		options->flags->space = FALSE;
	free(subformat);
	return (options->flags);
}
