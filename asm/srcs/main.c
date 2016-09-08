/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 15:10:45 by vbaudin           #+#    #+#             */
/*   Updated: 2016/09/08 13:21:10 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				main(int ac, char **av)
{
	char		*extension;
	t_bool		option_a;
	int			i;

	extension = NULL;
	option_a = (ft_strcmp(av[1], "-a") == 0) ? TRUE : FALSE;
	i = (option_a) ? 2 : 1;
	while (i < ac)
	{
		extension = ft_strchr(av[i], '.');
		if (extension && ft_strcmp(extension, ".s") == 0)
		{
			ft_parse(av[i]);
			ft_compile(av[i], option_a);
		}
		else if (extension && ft_strcmp(extension, ".cor") == 0)
			{
				ft_disassemble(av[i], option_a);
				ft_printf("Disassemble %s {green}[OK]{eoc}\n", av[i]);
			}
		else
		{
			ft_printf("Incorrect file extension : %s\n", av[i]);
			exit(0);
		}
		i++;
	}
	return (0);
}
