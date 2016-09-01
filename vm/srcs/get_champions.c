/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_champions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 15:22:57 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/08/25 15:23:01 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				ft_get_value(char *encoded, int size)
{
	int		value;

	value = 0;
	while (size)
	{
		value = value << 8;
		value = value | (*encoded & 0xff);
		++encoded;
		size--;
	}
	return (value);
}

static void		ft_extract_data(t_champion *champion, int fd)
{
	char		buf[CHAMP_MAX_SIZE];
	int			size;

	size = read(fd, buf, champion->data_size);
	// ft_printf("DEBUG ---> size 1 : %d\n", champion->data_size);
	if (size == 0)
		ft_exit_error("Champion has no instructions in body : ", champion->name);
	champion->data = ft_memalloc(size);
	champion->data  = (unsigned char *)ft_memcpy(champion->data, buf, size);
	size = read(fd, buf, CHAMP_MAX_SIZE + 1);
	// ft_printf("DEBUG ---> size : %d\n", size);

	if (size > CHAMP_MAX_SIZE)
		ft_exit_error("Champion exceeded maximum allowed size : ", champion->name);
	if (size > 0)
		ft_exit_error("Champion size is bigger than indicated in header : ", champion->name);
}

static void		ft_extract_header(t_champion *champion, int fd, char *file)
{
	char		buf[HEADER_SIZE];

	ft_check_header(fd, file);
	lseek(fd, 0, SEEK_SET);
	read(fd, buf, 4);
	ft_get_value(buf, 4);
	read(fd, buf, PROG_NAME_LENGTH + 4);
	champion->name = ft_strdup(buf);
	read(fd, buf, 4);
	champion->data_size = ft_get_value(buf, 4);
	read(fd, buf, COMMENT_LENGTH + 4);
	champion->comment = ft_strdup(buf);
}

static void		ft_extract_champion(t_champion *champion, char *file, int champ_nb)
{
	int		fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		ft_exit_error("Could not open file : ", file);
	ft_extract_header(champion, fd, file);
	ft_extract_data(champion, fd);
	champion->champ_nb = champ_nb;
	champion->live = 0;
	close(fd);
}

void	ft_get_champions(char **av, t_champion *champions, t_vm *vm)
{
	int		i;
	int		nb_extracted_champ;
	int 	champ_nb;

	i = 0;
	nb_extracted_champ = 0;
	champ_nb = 0;
	while (av[++i])
	{
		if (ft_strcmp(av[i], "-n") == 0)
		{
			champ_nb = ft_atoi(av[i + 1]);
			ft_extract_champion(&champions[nb_extracted_champ], av[i + 2], champ_nb);
			nb_extracted_champ++;
			i += 2;
		}
		else
		{
			ft_extract_champion(&champions[nb_extracted_champ], av[i], ++champ_nb);
			nb_extracted_champ++;
		}
		vm->nb_champs++;
	}
}
