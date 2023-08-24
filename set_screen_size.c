/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_screen_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:17:44 by aperis-p          #+#    #+#             */
/*   Updated: 2023/08/24 16:20:52 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_screen_size(t_point *w_h, t_wdata wdata)
{
	w_h->x = gnl_strlen(wdata.mapinfo.map[0]);
	w_h->y = ft_count_rows(wdata.mapinfo.map);
}
