/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 15:37:08 by vbaudin           #+#    #+#             */
/*   Updated: 2016/08/15 13:06:06 by vbaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

#include "libft.h"
#include <fcntl.h>
#include "op.h"
#include "libft.h"

t_op		ft_init_op(char *name, int nb_args, int *type_arg, int code);
void		ft_init_op_bis(t_op *tab, int cycle, char *desc, int octet);

#endif
