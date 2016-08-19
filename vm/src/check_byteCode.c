/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_byteCode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbichero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 15:35:58 by bbichero          #+#    #+#             */
/*   Updated: 2016/08/19 16:44:48 by bbichero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include "vm.h"

int		get_byteCode(char *file)
{
	int			fd;
	int			ret;
	char		*line;
	t_byteCode	*list;

	ret = 0;
	list = NULL;
	if ((fd = open(file, O_RDONLY)) < 0)
		return (-1); //ft_error to implemente.
	while ((ret = get_next_line(fd, &line)) > 0)
		add_link(&list, new_link(line));
	if (ret < 0)
		return(-1); //ft_error to implemente.
	return (0);
}
