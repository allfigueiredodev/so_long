/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:37:49 by aperis-p          #+#    #+#             */
/*   Updated: 2023/08/24 13:38:16 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_copy(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
