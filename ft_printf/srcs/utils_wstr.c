/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_wstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 13:32:14 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/03/11 17:15:13 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

wchar_t		*ft_get_spaces_wstr(t_width width)
{
	wchar_t	*spaces;
	int		i;

	spaces = ft_memalloc(sizeof(wchar_t) * width + 1);
	i = 0;
	if (!spaces)
		return (NULL);
	while (i < width)
	{
		spaces[i] = ' ';
		i++;
	}
	spaces[i] = '\0';
	return (spaces);
}

wchar_t		*ft_apply_width_wstr(t_options *options, wchar_t *arg,
			void *orig_arg)
{
	t_width	width;
	int		len;
	wchar_t	*ret;
	wchar_t	*spaces;

	width = options->width;
	len = ft_wstrlen(arg);
	ret = NULL;
	spaces = NULL;
	if (width > (int)len)
	{
		spaces = ft_get_spaces_wstr(width - len);
		if (options->flags->minus ||
			(options->type == T_VOID_PTR && options->flags->zero))
			ret = ft_wstrjoin(arg, spaces);
		else
			ret = ft_wstrjoin(spaces, arg);
		if (!ret)
			return (NULL);
	}
	else
		return (arg);
	if (arg != orig_arg)
		free(arg);
	return (ret);
}

wchar_t		*ft_apply_zero_flag_wstr(t_width width, wchar_t *arg)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (arg[i])
		len = (arg[i++] == ' ') ? len + 1 : len;
	len = (unsigned int)ft_wstrlen(arg) - len;
	i = 0;
	while (arg[i] && (int)len < (int)width)
	{
		if (arg[i] == L' ')
			arg[i] = L'0';
		else if (arg[i] && arg[i] == '-' && ft_isdigit(arg[i + 1]))
		{
			arg[i] = L'0';
			arg[0] = L'-';
		}
		i++;
	}
	return (arg);
}

char		*ft_apply_sharp_flag_hexa(t_specifier specifier,
										t_precision precision,
										t_flags *flags, char *arg)
{
	char	*ret;
	int		spaces;

	ret = arg;
	spaces = 0;
	while ((arg[spaces] == ' ' || arg[spaces] == '0') && arg[spaces])
		spaces++;
	if (ft_atoi(arg) == 0)
		ret = ((specifier == UNS_HEXA || specifier == UNS_HEXA_MAJ)
				&& precision == 0) ? ft_strdup("") : ft_strdup("0");
	else if (spaces >= 2 && precision < 0)
	{
		spaces = (flags->zero) ? spaces - spaces + 2 : spaces;
		ret[spaces - 2] = '0';
		ret[spaces - 1] = (specifier == UNS_HEXA) ? 'x' : 'X';
	}
	else if (specifier == UNS_HEXA)
		ret = ft_strjoin("0x", arg);
	else
		ret = ft_strjoin("0X", arg);
	return (ret);
}
