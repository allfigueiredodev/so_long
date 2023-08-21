#include "so_long.h"

char **file_to_matrix(t_wdata *wdata, char *filename)
{
	char **matrix;
    static char *line;
    int rows;
    int i;
    int fd;

    rows = ft_count_rows_from_fd(filename);
    i = 0;
    fd = open(filename, O_RDONLY);
    wdata->imgdata.fd = open(filename, O_RDONLY);
    matrix = (char **) malloc(sizeof(char*) * (rows + 1));
    if(!matrix)
        return(0);
    line = get_next_line(fd);
    while(rows--)
    {
        matrix[i] = malloc(sizeof(char) * (ft_strlen(line) + 1));
		if(!matrix[i])
			return(0);
        if(line[ft_strlen(line) - 1] == '\n')
            ft_strlcpy(matrix[i], line, ft_strlen(line));
        else if(line[ft_strlen(line) - 1] == '1')
            ft_strlcpy(matrix[i], line, ft_strlen(line) + 1);
        free(line);
        line = get_next_line(fd);
        i++;
    }
    matrix[i] = NULL;
	return(matrix);
} 