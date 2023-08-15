#include "so_long.h"

void	ft_putstr(char *s)
{
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}