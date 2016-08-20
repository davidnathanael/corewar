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

# include "../includes/libft.h"
# include "../includes/op.h"

typedef struct			s_byteCode
{
	char				*line;
	struct s_byteCode	*next;
}						t_byteCode;

void					add_link(t_byteCode **list, t_byteCode *new);
int						get_byteCode(char *file);
t_byteCode				*new_link(char *line);

#endif
