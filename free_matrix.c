/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:38:26 by aperis-p          #+#    #+#             */
/*   Updated: 2023/08/24 13:38:50 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_matrix(t_wdata *wdata)
{
	int	i;

	i = 0;
	while (wdata->mapinfo.map[i])
	{
		free(wdata->mapinfo.map[i]);
		i++;
	}
	free(wdata->mapinfo.map);
}
