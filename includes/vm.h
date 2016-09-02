/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbichero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 15:17:56 by bbichero          #+#    #+#             */
/*   Updated: 2016/09/02 12:53:13 by vbaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <fcntl.h>
# include <unistd.h>
# include "libft.h"
# include "op.h"

# define		LIVE 		1
# define		LD			2
# define		ST			3
# define		ADD			4
# define		SUB			5
# define		AND			6
# define		OR			7
# define		XOR			8
# define		ZJMP		9
# define		LDI			10
# define		STI			11
# define		FORK		12
# define		LLD			13
# define		LLDI		14
# define		LFORK		15
# define		AFF			16



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
void					ft_introduce_champs(t_vm *vm);
t_vm					*init_vm();

void					ft_get_champions(char **av, t_champion *champions, t_vm *vm);
void					ft_check_header(int fd, char *file);

void					ft_load_champions(t_vm *vm);

void					ft_launch_vm(t_vm *vm);

void					ft_exit_error(char *error, char *var);
int						ft_get_value(char *encoded, int size);
t_op					*ft_get_op_data(int op);
t_args					*ft_get_args(t_vm *vm, t_process *process, t_op *data);

void					ft_and(t_args *args, t_vm *vm, t_process *process);
void		ft_or(t_args *args, t_vm *vm, t_process *process);
void		ft_xor(t_args *args, t_vm *vm, t_process *process);
void		ft_zjmp(t_args *args, t_vm *vm, t_process *process);
void		ft_ldi(t_args *args, t_vm *vm, t_process *process);
void		ft_fork(t_args *args, t_vm *vm, t_process *process);
void		ft_lfork(t_args *args, t_vm *vm, t_process *process);
void		ft_aff(t_args *args, t_vm *vm, t_process *process);
void		ft_live(t_args *args, t_vm *vm, t_process *process);
void		ft_ld(t_args *args, t_vm *vm, t_process *process);
void		ft_st(t_args *args, t_vm *vm, t_process *process);
void		ft_add(t_args *args, t_vm *vm, t_process *process);
void		ft_sub(t_args *args, t_vm *vm, t_process *process);
void		ft_sti(t_args *args, t_vm *vm, t_process *process);
void		ft_lld(t_args *args, t_vm *vm, t_process *process);
void		ft_lldi(t_args *args, t_vm *vm, t_process *process);
#endif
