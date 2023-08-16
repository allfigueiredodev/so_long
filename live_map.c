#include "so_long.h"

char **live_map(int nrows, int fd2)
{
	static char **live_map;
	static int i;
	char *line;

	i = 0;
	line = get_next_line(fd2);
	live_map = (char **) malloc(sizeof(char*) * (nrows + 1));
	if(!live_map)
		return(0);
	while(line)
	{
		live_map[i] = malloc(sizeof(char) * (ft_strlen(line) + 1));
		if(!live_map[i])
			return(0);
		ft_strlcpy(live_map[i], line, ft_strlen(line) + 1);
		ft_putstr(live_map[i]);
		i++;
		free(line);
		line = get_next_line(fd2);
	}
	live_map[i] = NULL;
	free(line);
	return(live_map);
} 