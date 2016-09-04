/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_new_label.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 16:28:53 by vbaudin           #+#    #+#             */
/*   Updated: 2016/08/19 12:40:57 by vbaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		get_new_label(char *name, int kind, t_parse *data)
{
	t_label		*c_label;
	t_label		*new_label;

	if (!(new_label = (t_label *)malloc(sizeof(t_label))))
		ft_free_and_exit(data, name, 5);
	if (data->label != NULL)
	{
		c_label = data->label;
		while (c_label != NULL && c_label->next != NULL)
			c_label = c_label->next;
	}
	new_label->name = ft_strdup(name);
	new_label->kind = kind;
	new_label->next = NULL;
	if (data->label == NULL)
		data->label = new_label;
	else
		c_label->next = new_label;
}
