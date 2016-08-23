/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 15:54:43 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/08/18 15:54:45 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_compile(char *file)
{
	int			fd;
	t_header	*header;
	t_list		*instructions;

	fd = open(file, O_RDONLY);
	header = ft_get_header(fd);
	instructions = ft_get_instructions(fd, header);
}
