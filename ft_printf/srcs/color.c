/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 11:25:50 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/26 23:54:08 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "printf.h"

char	**ft_init_colors(void)
{
	char	**colors;

	colors = (char **)malloc(sizeof(char *) * (NB_COLORS + 1));
	if (!colors)
		return (NULL);
	colors[0] = ft_strdup("{bold}");
	colors[1] = ft_strdup("{unbold}");
	colors[2] = ft_strdup("{red}");
	colors[3] = ft_strdup("{green}");
	colors[4] = ft_strdup("{blue}");
	colors[5] = ft_strdup("{yellow}");
	colors[6] = ft_strdup("{magenta}");
	colors[7] = ft_strdup("{cyan}");
	colors[8] = ft_strdup("{default}");
	colors[9] = ft_strdup("{eoc}");
	colors[10] = ft_strdup("\0");
	return (colors);
}

char	*ft_get_color_code(char *color)
{
	char	*ret;

	ret = NULL;
	if (ft_strcmp(color, "{bold}") == 0)
		ret = ft_strdup(ANSI_BOLD);
	else if (ft_strcmp(color, "{unbold}") == 0)
		ret = ft_strdup(ANSI_UNBOLD);
	else if (ft_strcmp(color, "{red}") == 0)
		ret = ft_strdup(ANSI_COLOR_RED);
	else if (ft_strcmp(color, "{green}") == 0)
		ret = ft_strdup(ANSI_COLOR_GREEN);
	else if (ft_strcmp(color, "{blue}") == 0)
		ret = ft_strdup(ANSI_COLOR_BLUE);
	else if (ft_strcmp(color, "{yellow}") == 0)
		ret = ft_strdup(ANSI_COLOR_YELLOW);
	else if (ft_strcmp(color, "{magenta}") == 0)
		ret = ft_strdup(ANSI_COLOR_MAGENTA);
	else if (ft_strcmp(color, "{cyan}") == 0)
		ret = ft_strdup(ANSI_COLOR_CYAN);
	else if (ft_strcmp(color, "{default}") == 0)
		ret = ft_strdup(ANSI_COLOR_DEFAULT);
	else if (ft_strcmp(color, "{eoc}") == 0)
		ret = ft_strdup(ANSI_COLOR_RESET);
	return (ret);
}

char	*ft_check_color(char *str)
{
	char	**colors;
	char	*color_code;
	char	*ret;
	int		i;

	colors = ft_init_colors();
	color_code = NULL;
	ret = str;
	i = 0;
	while (i < NB_COLORS)
	{
		if (ft_strstr(str, colors[i]))
		{
			color_code = ft_get_color_code(colors[i]);
			ret = ft_strreplace(ret, colors[i], color_code);
			free(color_code);
		}
		i++;
	}
	i = 0;
	while (i <= NB_COLORS)
		free(colors[i++]);
	free(colors);
	return (ret);
}
