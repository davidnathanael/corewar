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

void		ft_write_output(char *str, t_bool option_a)
{
	int		i;
	char	*tmp;

	tmp = ft_strdup(str);
	i = 0;
	while (tmp[i] != '.')
		i++;
	tmp[i] = '\0';
	if (option_a)
		ft_printf("Dumping annotated program on standard output\n");
	else
		ft_printf("Writing in the file %s.cor\n", tmp);
	ft_memdel((void**)&tmp);
}
