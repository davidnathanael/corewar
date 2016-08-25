/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbichero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 15:22:04 by bbichero          #+#    #+#             */
/*   Updated: 2016/08/19 16:12:23 by bbichero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "vm.h"

t_byteCode	*new_link(char *line)
{
	t_byteCode	*new;

	if (!(new = (t_byteCode *)malloc(sizeof(t_byteCode))))
		return (NULL); //ft_error to impletement.
	new->line = line;
	new->next = NULL;
	return (new);
}

void		add_link(t_byteCode **list, t_byteCode *new)
{
	t_byteCode	*tmp;

	if (!(*list))
		*list = new;
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
