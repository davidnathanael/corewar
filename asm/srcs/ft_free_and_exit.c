#include "asm.h"

void   	ft_free_and_exit(t_parse *data, char *line, int n)
{
	if (data)
       		free_data(data);
       	if (line)
       		ft_strdel(&line);
       	ft_error(n);
}
