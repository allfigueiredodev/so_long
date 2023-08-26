/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:01:18 by aperis-p          #+#    #+#             */
/*   Updated: 2023/08/24 15:43:58 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_rows(char **matrix)
{
	int	total;

	total = 0;
	while (*matrix)
	{
		total++;
		matrix++;
	}
	return (total);
}

int	ft_count_rows_from_fd(char *filename)
{
	int		fd;
	char	*line;
	int		rows;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		exit(0);
	}
	line = get_next_line(fd);
	rows = 0;
	while (line)
	{
		rows++;
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	return (rows);
}
