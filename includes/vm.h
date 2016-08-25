/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbichero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 15:17:56 by bbichero          #+#    #+#             */
/*   Updated: 2016/08/20 13:11:34 by bbichero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "libft.h"
# include "op.h"

typedef struct			s_champion
{
	char				*name;
	char				*comment;
	unsigned char		*data;
	int					data_len;
	int					champ_nb;
	int					live;
}						t_champion;

typedef struct			s_vm
{
	int					cycle_to_die;
	t_champion			champion[MAX_PLAYERS];
	int					nb_executed_live;
	unsigned char		memory[MEM_SIZE];
}						t_vm;

#endif
