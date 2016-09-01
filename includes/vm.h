/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbichero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 15:17:56 by bbichero          #+#    #+#             */
/*   Updated: 2016/09/01 08:19:24 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <fcntl.h>
# include <unistd.h>
# include "libft.h"
# include "op.h"

typedef struct			s_args
{
	int					nb_args;
	int					types[MAX_ARGS_NUMBER];
	int					values[MAX_ARGS_NUMBER];
}						t_args;

typedef struct			s_process
{
	int					reg[REG_NUMBER];
	int					pc;
	int					carry;
	int					waiting_op;
	int					cycle_to_wait;
	t_bool				is_waiting;
	struct s_process	*next;
	struct s_process	*prev;
}						t_process;

typedef struct			s_champion
{
	char				*name;
	char				*comment;
	unsigned char		*data;
	int					data_size;
	int					champ_nb;
	int					live;
}						t_champion;

typedef struct			s_vm
{
	int					cycle_to_die;
	t_champion			champions[MAX_PLAYERS];
	int					nb_executed_live;
	unsigned char		memory[MEM_SIZE];
	int					nb_champs;
	t_process			*process;
}						t_vm;

void					ft_parse_command(char **av);
void					ft_print_usage(void);
t_vm					*init_vm();

void					ft_get_champions(char **av, t_champion *champions, t_vm *vm);
void					ft_check_header(int fd, char *file);

void					ft_load_champions(t_vm *vm);

void					ft_exit_error(char *error, char *var);
int						ft_get_value(char *encoded, int size);

#endif
