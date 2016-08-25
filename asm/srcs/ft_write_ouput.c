/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_ouput.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 12:10:55 by vbaudin           #+#    #+#             */
/*   Updated: 2016/08/25 12:31:19 by vbaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_write_output(char *str)
{
	int		i;
	char	*tmp;

	tmp = ft_strdup(str);
	i = 0;
	while (tmp[i] != '.')
		i++;
	tmp[i] = '\0';
	ft_putstr("Writing in the file ");
	ft_putstr(tmp);
	ft_putendl(".cor");
	ft_memdel((void**)&tmp);
}
