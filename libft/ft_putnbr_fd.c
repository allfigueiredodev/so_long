/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:44:54 by aperis-p          #+#    #+#             */
/*   Updated: 2023/05/25 11:51:42 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nmbr;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nmbr = n * -1;
	}
	else
		nmbr = n;
	if (nmbr >= 10)
	{
		ft_putnbr_fd((nmbr / 10), fd);
	}
	ft_putchar_fd(((nmbr % 10) + '0'), fd);
}
