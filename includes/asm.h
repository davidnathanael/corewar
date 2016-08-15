/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 15:37:08 by vbaudin           #+#    #+#             */
/*   Updated: 2016/08/15 14:49:47 by vbaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

#include "libft.h"
#include <fcntl.h>
#include "op.h"
#include "libft.h"

typedef struct		s_parse
{
	int				isset_name;
	int				setting_name;
	char			*name;
	int				isset_comment;
	int				setting_comment;
	char			*comment;
	int				line_header;
	int				line_inst;
	int				nb_lines;
}					t_parse;

void	ft_parse(char *file);
void	ft_check_name_comment(char *line, t_parse *data, int type);

#endif
