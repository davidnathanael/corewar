/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_label_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 18:28:07 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/08/24 18:28:09 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_inst		*ft_get_target(t_list *instructions, t_inst *inst, char *label, t_bool *is_before)
{
	t_inst		*target;

	target = NULL;
	while (instructions)
	{
		target = instructions->content;
		if (target->label && ft_strcmp(target->label, label) == 0)
			break;
		if (target == inst)
			*is_before = FALSE;
		instructions = instructions->next;
	}
	return (target);
}

int			ft_get_label_value(t_list *instructions, t_inst *inst, char *label)
{
	t_bool		is_before;
	t_bool		add;
	t_inst		*tmp;
	t_inst		*target;
	int			value;

	is_before = TRUE;
	add = FALSE;
	tmp = NULL;
	target = ft_get_target(instructions, inst, label, &is_before);
	value = 0;
	while (instructions)
	{
		tmp = instructions->content;
		if (tmp == inst || tmp == target)
		{
			if (add)
				break;
			add = TRUE;
		}
		value += (add) ? tmp->size : 0;
		instructions = instructions->next;
	}
	return ((is_before) ? -value : value);
}
