#include "so_long.h"

// size_t	ft_strlen(const char *s)
// {
// 	int	counter;

// 	counter = 0;
// 	while (*s)
// 	{
// 		counter++;
// 		s++;
// 	}
// 	return (counter);
// }


int	ft_strcmp(const char *s1, const char *s2)
{
	while ((*s1 != '\0' || *s2 != '\0'))
	{
		while (*s1 == *s2 && *s1 && *s2)
		{
			s1++;
			s2++;
		}
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	}
	return (0);
}

int ft_count_rows(char **matrix)
{
	int total;

	total = 0;
	while(*matrix)
	{
		total++;
		matrix++;
	}
	return(total);
}

int ft_count_rows_from_fd(char *filename)
{
	int fd;
	char *line;
	int rows;

    fd = open(filename, O_RDONLY);
    line = get_next_line(fd);
	rows = 0;
    while(line)
    {
        rows++;
        free(line);
        line = get_next_line(fd);
    }
    if(line)
        free(line);
    close(fd);
	return(rows);
}

