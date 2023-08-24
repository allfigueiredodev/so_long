/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:58:48 by aperis-p          #+#    #+#             */
/*   Updated: 2023/08/23 16:54:49 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ftprintf_itoa(unsigned long n, int base, int caps)
{
	int		count;
	char	*hexa_chrs;

	count = 0;
	if (caps)
		hexa_chrs = "0123456789ABCDEF";
	else
		hexa_chrs = "0123456789abcdef";
	if (n < (unsigned long)base)
		return (ftprintf_putchar(hexa_chrs[n]));
	else
	{
		count = ftprintf_itoa(n / base, base, caps);
		return (count + ftprintf_itoa(n % base, base, caps));
	}
}

int	hash_printer(unsigned long n, int base)
{
	if (!n)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	if (base == 16)
		ftprintf_putstr("0x");
	else if (base == 8)
		ftprintf_putstr("0");
	return (ftprintf_itoa(n, base, 0) + 2);
}
