/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:38:14 by aperis-p          #+#    #+#             */
/*   Updated: 2023/08/23 16:46:51 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_find_line_break(int fd, char *checkpoint);
char	*ft_parse_line(char *checkpoint);
char	*ft_next_chars(char *checkpoint);

char	*get_next_line(int fd)
{
	char		*actual_line[4096];
	static char	*checkpoint;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	checkpoint = ft_find_line_break(fd, checkpoint);
	if (!checkpoint)
		return (NULL);
	actual_line[fd] = ft_parse_line(checkpoint);
	if (actual_line[fd] == NULL)
		return (NULL);
	checkpoint = ft_next_chars(checkpoint);
	return (actual_line[fd]);
}

char	*ft_find_line_break(int fd, char *checkpoint)
{
	char	*buffer;
	ssize_t	read_bytes;

	if (gnl_strchr(checkpoint, '\n') != NULL)
		return (checkpoint);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	read_bytes = 1;
	while (gnl_strchr(checkpoint, '\n') == NULL && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (read_bytes == 0)
			break ;
		buffer[read_bytes] = '\0';
		checkpoint = gnl_strjoin(checkpoint, buffer);
	}
	free(buffer);
	return (checkpoint);
}

char	*ft_parse_line(char *checkpoint)
{
	int		i;
	char	*parsed;

	i = 0;
	if (checkpoint[i] == '\0')
		return (NULL);
	while (checkpoint[i] != '\0' && checkpoint[i] != '\n')
		i++;
	if (checkpoint[i] == '\n')
	{
		parsed = (char *) malloc((i + 2) * sizeof(char));
		if (!parsed)
			return (NULL);
		gnl_strlcpy(parsed, checkpoint, i + 2);
	}
	if (gnl_strlen(checkpoint) == 0 && checkpoint[i] == '\0')
		return (NULL);
	else if (checkpoint[i] == '\0')
	{
		parsed = (char *) malloc((i + 1) * sizeof(char));
		if (!parsed)
			return (NULL);
		gnl_strlcpy(parsed, checkpoint, i + 1);
	}
	return (parsed);
}

char	*ft_next_chars(char *checkpoint)
{
	int		i;
	int		j;
	char	*first_chars;

	i = 0;
	j = 0;
	if (checkpoint == NULL)
		return (NULL);
	while (checkpoint[i] != '\0' && checkpoint[i] != '\n')
		i++;
	if (!checkpoint[i] || !checkpoint[i + 1])
	{
		free(checkpoint);
		return (NULL);
	}
	first_chars = malloc((gnl_strlen(checkpoint) - i + 1) * sizeof(char));
	if (!first_chars)
		return (NULL);
	i++;
	while (checkpoint[i] != '\0')
		first_chars[j++] = checkpoint[i++];
	first_chars[j] = '\0';
	free(checkpoint);
	return (first_chars);
}
