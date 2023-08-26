/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_keys.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:49:09 by aperis-p          #+#    #+#             */
/*   Updated: 2023/08/24 15:22:58 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_keys(int i, int j, int keys, char **map)
{
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == '1')
				keys |= (1 << 4);
			else if (map[i][j] == '0')
				keys |= (1 << 3);
			else if (map[i][j] == 'P' && (keys & (1 << 2)) < 1)
				keys |= (1 << 2);
			else if (map[i][j] == 'E' && (keys & (1 << 1)) < 1)
				keys |= (1 << 1);
			else if (map[i][j] == 'C')
				keys |= 1;
			else
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (keys);
}

int	has_all_keys(char **map)
{
	int	keys;
	int	i;
	int	j;

	keys = 0b00000;
	i = 0;
	j = 0;
	keys = check_keys(i, j, keys, map);
	if (keys == 31)
		return (1);
	return (0);
}
