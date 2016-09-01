/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <ddela-cr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 10:48:40 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/09/01 08:13:18 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	ft_check_numbers(int *champ_nb)
{
	int		nb;
	int		i;
	int		j;

	nb = champ_nb[0];
	i = 0;
	j = 0;
	while (i < MAX_PLAYERS)
	{
		while (j < MAX_PLAYERS)
		{
			if (champ_nb[j] > MAX_PLAYERS)
				ft_exit_error("Champion number greater than MAX_PLAYERS : ", ft_itoa(champ_nb[j]));
			if (i != j && champ_nb[i] == champ_nb[j] && champ_nb[i] != 0 && champ_nb[j] != 0)//On check les slots non attribuer a des champions ce qui fait planter le programme !! Fixer pour le moment avec les deux derniers arguments du While !!
				ft_exit_error("Duplicate champion number : ", ft_itoa(champ_nb[i]));
			j++;
		}
		j = 0;
		i++;
	}
}

static int		ft_get_available_number(int *champ_nb)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	if (!champ_nb)
		return (0);
	while (i < MAX_PLAYERS)
	{
		if (champ_nb[i] > nb)
			nb = champ_nb[i];
		i++;
	}
	return (++nb);
}

static int		ft_check_file(char *file, int *champ_nb)
{
	int		fd;
	char	*last_dot;

	if ((fd = open(file, O_RDONLY)) == -1)
		ft_exit_error("Could not open file : ", file);
	last_dot = ft_strrchr(file, '.');
	if (!last_dot)
		ft_exit_error("Incorrect file, enter .cor file : ", file);
	if (ft_strcmp(last_dot, ".cor") != 0)
		ft_exit_error("Incorrect file, enter .cor file : ", file);
	close(fd);
	return (ft_get_available_number(champ_nb));
}

static int		ft_check_number(char ***ptr, char **av)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while(av[i])
		i++;
	if (i <= 2)
		ft_print_usage();
	ret = ft_atoi(av[1]);
	ft_check_file(av[2], NULL);
	*ptr = *ptr + 2;
	return (ret);
}

void			ft_parse_command(char **av)
{
	int		champ_nb[MAX_PLAYERS];
	int		i;

	i = 0;
	ft_bzero(champ_nb, sizeof(int) * MAX_PLAYERS);
	while (*(++av))
	{
		if (ft_strcmp(*av, "-n") == 0)
			champ_nb[i] = ft_check_number(&av, av);
		else
			champ_nb[i] = ft_check_file(*av, champ_nb);
		if (++i > MAX_PLAYERS)
			ft_exit_error("Too much players, max players : ", ft_itoa(MAX_PLAYERS));
	}
	ft_check_numbers(champ_nb);
}
