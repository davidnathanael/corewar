/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 13:43:45 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/08/15 13:43:49 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_put_file(void)
{
	ft_putendl("Usage: ./asm <sourcefile>");
	return (0);
}

t_bool	iscor(char *s)
{
	int		len;

	if (s)
	{
		len = ft_strlen(s);
		if (s[len - 1] == 's' && s[len - 2] == '.')
			return (TRUE);
	}
	return (FALSE);
}

t_bool	ft_is_name_com(char *line)
{
	static	int name = 0;
	static	int com = 0;

	if (ft_strncmp(line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) == 0
			&& !name)
	{
		name = 1;
		return (TRUE);
	}
	else if (ft_strncmp(line, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING))
			== 0 && !com)
	{
		com = 1;
		return (TRUE);
	}
	return (FALSE);
}

t_bool	ft_islabel(char *line)
{
	int		i;

	i = 0;
	while (line[i] != LABEL_CHAR)
	{
		if (!ft_strchr(LABEL_CHARS, line[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	ft_isvalid_line(char *line)
{
	static	int count = 0;

	if (++count <= 2)
	{
		if (ft_is_name_com(line))
			return (TRUE);
	}
	else
	{
		if (ft_islabel(line))
			return (TRUE);
	}
	return (FALSE);
}

t_list	*get_lines(int fd)
{
	char *buf;
	t_list *lines;

	lines = NULL;
	while (get_next_line(fd, &buf))
		if (buf[0] != '\0' && ft_isvalid_line(buf))
			ft_lstappend(&lines, ft_lstnew(buf, ft_strlen(buf) + 1));
	return (lines);
}

void	print_content(t_list *lines)
{
	while (lines)
	{
		ft_putendl(lines->content);
		lines = lines->next;
	}
}

void	ft_create_bin(t_list *lines)
{
	int		fd;

	if ((fd = open("zork.cor", O_CREAT, S_IRWXU)) > 0)
	{
		close(fd);
		if ((fd = open("zork.cor", O_RDWR)))
		{
		}
	}
}