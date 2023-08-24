#include "so_long.h"

char **get_matrix(int rows, int fd)
{
	int i;
	static char *line;
	char **matrix;

	i = 0;
	line = get_next_line(fd);
	matrix = (char **) malloc(sizeof(char*) * (rows + 1));
	if(!matrix)
		return(0);
	while(rows--)
	{
		matrix[i] = malloc(sizeof(char) * (gnl_strlen(line) + 1));
		if(!matrix[i])
			return(0);
		if(line[gnl_strlen(line) - 1] == '\n')
			gnl_strlcpy(matrix[i], line, gnl_strlen(line));
		else if(line[gnl_strlen(line) - 1] == '1')
			gnl_strlcpy(matrix[i], line, gnl_strlen(line) + 1);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	matrix[i] = NULL;
	return(matrix);	
}

char **file_to_matrix(t_wdata *wdata, char *filename)
{
    int rows;
 
    rows = ft_count_rows_from_fd(filename);
    wdata->imgdata.fd = open(filename, O_RDONLY);
    if(wdata->imgdata.fd < 0)
    {
        perror("Error");
        exit(0);
    }
	return(get_matrix(rows, wdata->imgdata.fd));
} 