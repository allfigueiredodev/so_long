#include "so_long.h"

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
	if(fd < 0)
	{
		perror("Error");
		exit(0);
	}
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

void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] == '1' || tab[cur.y][cur.x] == '#')
		return;
	tab[cur.y][cur.x] = '#';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point start)
{
	fill(tab, size, start, tab[start.y][start.x]);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	unsigned int	i;

	i = 0;
	ptr = NULL;
	if (!nmemb || !size)
		return (malloc(0));
	if (((nmemb * size) / size) != nmemb)
		return (ptr);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (ptr);
	while (i < (nmemb * size))
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}
