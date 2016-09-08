/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_get_header.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 15:08:34 by jbateau           #+#    #+#             */
/*   Updated: 2016/09/08 16:22:20 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_get_headercomment(char *line, t_header *header)
{
	char	*start;
	int		len;

	start = ft_strchr(line, '"') + 1;
	len = 0;
	while (start[len] && start[len] != '"')
		len++;
	len = (len > COMMENT_LENGTH) ? COMMENT_LENGTH : len;
	ft_strncpy(header->comment, start, len);
}

void		ft_get_headername(char *line, t_header *header)
{
	char	*start;
	int		len;

	start = ft_strchr(line, '"') + 1;
	len = 0;
	while (start[len] && start[len] != '"')
		len++;
	len = (len > PROG_NAME_LENGTH) ? PROG_NAME_LENGTH : len;
	ft_strncpy(header->prog_name, start, len);
}

t_header	*ft_initheader(void)
{
	t_header	*header;

	if (!(header = (t_header *)malloc(sizeof(t_header))))
		return (NULL);
	ft_bzero(&header->prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(&header->comment, COMMENT_LENGTH + 1);
	header->prog_size = 0;
	header->isset_comment = 0;
	header->isset_name = 0;
	header->setting = 0;
	header->tmp = NULL;
	header->magic = COREWAR_EXEC_MAGIC;
	return (header);
}
