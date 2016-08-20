/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_byteCode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbichero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 15:35:58 by bbichero          #+#    #+#             */
/*   Updated: 2016/08/20 13:10:48 by bbichero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "vm.h"

int		get_byteCode(char *file)
{
	int			fd;
	int			ret;
	t_header	*header;

	header = (t_header *)malloc(sizeof(t_header));
	if (!(fd = open(file, O_RDONLY)))
		return (-1); //ft_error to implemente.
	while ((ret = read(fd, header, 64)) > 0)
	{
		printf("%x\n", header->magic);
	}
	if (ret < 0)
		return(-1); //ft_error to implemente.
	return (0);
}
