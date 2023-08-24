/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 23:14:34 by aperis-p          #+#    #+#             */
/*   Updated: 2023/08/23 16:47:14 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "libft.h"
#	include <stdint.h>

int	ftprintf_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ftprintf_putstr(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (ftprintf_putstr("(null)"));
	while (*str)
	{
		count += ftprintf_putchar(*str);
		str++;
	}
	return (count);
}

int	ft_putnbr_base(int n, unsigned long base)
{
	unsigned long	nmbr;
	int				counter;

	counter = 0;
	if (n < 0)
	{
		counter += ftprintf_putchar('-');
		nmbr = (unsigned long)n * -1;
	}
	else
		nmbr = n;
	if (nmbr >= base)
		counter += ft_putnbr_base(nmbr / base, base);
	return (counter + ftprintf_putchar((nmbr % base) + '0'));
}

int	ft_format_selector(va_list ap, const char *info)
{
	int	count;

	count = 0;
	{
		if (*(info + 1) == 'c')
			count += ftprintf_putchar(va_arg(ap, int));
		else if (*(info + 1) == 's')
			count += ftprintf_putstr(va_arg(ap, char *));
		else if (*(info + 1) == 'p')
			count += hash_printer(va_arg(ap, unsigned long), 16);
		else if (*(info + 1) == 'd' || *(info + 1) == 'i')
			count += ft_putnbr_base(va_arg(ap, int), 10);
		else if (*(info + 1) == 'u')
			count += ftprintf_itoa(va_arg(ap, unsigned int), 10, 0);
		else if (*(info + 1) == 'x')
			count += ftprintf_itoa(va_arg(ap, unsigned int), 16, 0);
		else if (*(info + 1) == 'X')
			count += ftprintf_itoa(va_arg(ap, unsigned int), 16, 1);
		else if (*(info + 1) == '%')
			count += write(1, info, 1);
	}
	return (count);
}

int	ft_printf(const char *info, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	if (info == 0)
		return (-1);
	va_start(ap, info);
	while (*info)
	{
		if (*info == '%')
		{
			count += ft_format_selector(ap, info);
			info++;
		}
		else
			count += write(1, info, 1);
		info++;
	}
	va_end(ap);
	return (count);
}
