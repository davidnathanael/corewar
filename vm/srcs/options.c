/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 18:11:25 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/09/06 18:11:26 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_bool	ft_handle_options(char *option, char ***ptr, t_vm *vm)
{
	char	**av;

	av = (*ptr) + 1;
	if (ft_strcmp(option, "-d") == 0)
	{
		if (ft_is_number(*av))
		{
			vm->dump = ft_atoi(*(av));
			*ptr = *ptr + 1;
		}
		else
			ft_print_usage();
	}
	else if (ft_strcmp(option, "-m") == 0)
		vm->mute = TRUE;
	else
		return (FALSE);
	return (TRUE);
}
