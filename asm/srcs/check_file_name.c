/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 18:37:21 by vbaudin           #+#    #+#             */
/*   Updated: 2016/08/17 19:00:09 by vbaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_parse		*malloc_me(void)
{
	t_parse	*data;

	if (!(data = (t_parse *)malloc(sizeof(t_parse))))
		ft_error(5);
	return (data);
}

int			is_correct_file(char *name)
{
	int		fd;

	if (ft_strlen(name) < 3 || name[ft_strlen(name) - 1] != 's' ||
			name[ft_strlen(name) - 2] != '.')
		ft_error(3);
	fd = open(name, O_RDONLY);
	if (fd < 0)
		ft_error(4);
	return (fd);
}
