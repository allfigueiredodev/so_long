/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:51:51 by aperis-p          #+#    #+#             */
/*   Updated: 2023/08/24 13:52:54 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_keypress(int keysym, t_wdata *wdata)
{
	if (keysym == UP || keysym == DOWN || keysym == LEFT || keysym == RIGHT
		|| keysym == WUP || keysym == SDOWN
		|| keysym == ALEFT || keysym == DRIGHT)
	{
		if (controller(keysym, wdata))
			ft_printf("Total moves: %d\n", wdata->game_data.moves);
	}
	else if (keysym == ESC)
		on_destroy(wdata);
	return (0);
}
