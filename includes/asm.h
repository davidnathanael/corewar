/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 15:37:08 by vbaudin           #+#    #+#             */
/*   Updated: 2016/09/09 05:05:30 by vbaudin          ###   ########.fr       */
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

# define IS_EMPTY			0
# define IS_COMMENT			1
# define IS_CHAMP_NAME		3
# define IS_CHAMP_COMMENT	4

# define STDOUT				1

enum
{
	A_VERIF,
	IS_LABEL
};

typedef struct				s_label
{
	char					*name;
	int						kind;
	struct s_label			*next;
}							t_label;

typedef struct				s_inst
{
	char					*label;
	t_bool					is_label_only;
	char					*opcode;
	int						nb_args;
	char					**args;
	int						size;

}							t_inst;

typedef struct				s_parse
{
	int						isset_name;
	int						setting_name;
	char					*name;
	int						isset_comment;
	int						setting_comment;
	char					*comment;
	int						header_is_parsed;
	int						line_inst;
	int						nb_lines;
	t_label					*label;
}							t_parse;

void						ft_write_output(char *str, t_bool option_a);
void						ft_error(int i);
void						ft_parse(char *file);
void						ft_check_name_comment(char *line, t_parse *data,
												int type);
void						ft_check_instr(char *line, int opcode,
											t_parse *data);
void						ft_check_label(char *line, t_parse *data);
void						ft_end_name_comment(t_parse *data);
void						get_new_label(char *name, int kind, t_parse *data);
int							line_kind(char *line);
int							get_instr(char *line_t);
int							is_correct_file(char *name);
int							get_kind_arg(char *arg, t_parse *data);

void						ft_compile(char *file, t_bool option_a);
t_op						*ft_get_op(char *name);
t_op						*ft_get_op_by_number(int index);
t_header					*ft_get_header(int fd);
t_list						*ft_get_instructions(int fd, t_header *header);
char						*ft_get_label(char *line);
char						*ft_get_opcode(char *line, t_bool has_label);
char						**ft_get_args(char *line, char *opcode,
												t_bool has_label);
int							ft_get_size(char **args, char *opcode);
int							ft_get_label_value(t_list *instructions,
												t_inst *inst, char *label);
int							ft_get_prefix(int nb_args, char **args);
int							ft_get_arg_type(char *arg);
void						free_data(t_parse *data);
void						ft_write_header(int fd, t_header *header);
void						ft_write_instructions(int fd, t_list *instructions);
int							ft_get_value(unsigned char *encoded, int size);

void						ft_disassemble(char *file, t_bool option_a);
void						ft_disassemble_header(int src, int dest);
void						ft_disassemble_body(int src, int dest);

void						ft_print_instruction(t_inst *instruction,
							t_op *infos, int total_size, t_list *head);

void						ft_debug_instruction(t_inst *instruction);
void						ft_debug_header(t_header *header);

t_parse						*malloc_me(void);
int							ft_labelexist(t_parse *data);
void						ft_free_and_exit(t_parse *data, char *line, int n);
int							ft_check_separator(char *tmp);
void						ft_get_headername(char *line, t_header *header);
void						ft_get_headercomment(char *line, t_header *header);
t_header					*ft_initheader(void);
void						ft_print_value(int value, int size);

#endif
