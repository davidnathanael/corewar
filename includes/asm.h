/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 15:37:08 by vbaudin           #+#    #+#             */
/*   Updated: 2016/08/20 20:58:01 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include "op.h"
# include "libft.h"
# include "printf.h"

# define IS_CHAMP_NAME 3
# define IS_CHAMP_COMMENT 4

enum
{
	A_VERIF,
	IS_LABEL
};

typedef struct		s_label
{
	char			*name;
	int				kind;
	struct s_label	*next;
}					t_label;

typedef struct		s_inst
{
	char			*label;
	char			*name;
}					t_inst;

typedef struct		s_parse
{
	int				isset_name;
	int				setting_name;
	char			*name;
	int				isset_comment;
	int				setting_comment;
	char			*comment;
	int				header_is_parsed;
	int				line_inst;
	int				nb_lines;
	t_label			*label;
}					t_parse;

void		ft_error(int i);
void		ft_parse(char *file);
void		ft_check_name_comment(char *line, t_parse *data, int type);
void		ft_check_instr(char *line, int opcode, t_parse *data);
void		ft_check_label(char *line, t_parse *data);
void		ft_end_name_comment(t_parse *data);
void		get_new_label(char *name, int kind, t_parse *data);
int			line_kind(char *line);
int			get_instr(char *line_t);
int			is_correct_file(char *name);
int			get_kind_arg(char *arg, t_parse *data);

void		ft_compile(char *file);
t_header	*ft_get_header(int fd);
t_list		*ft_get_instructions(int fd);
void		ft_write_name_comment(char *line, int kind, int fd);

t_parse		*malloc_me(void);

#endif
