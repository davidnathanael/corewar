#include "asm.h"

int	ft_check_separator(char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == SEPARATOR_CHAR && tmp[i + 1] && tmp[i + 1] == SEPARATOR_CHAR)
			return (0);
		if (tmp[i] == SEPARATOR_CHAR && !tmp[i + 1])
			return (0);
		i++;
	}
	return (1);
}
