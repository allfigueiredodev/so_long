/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:58:48 by aperis-p          #+#    #+#             */
/*   Updated: 2023/05/25 12:31:06 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_counter(int n)
{
	int	counter;
	int	negative;

	counter = 0;
	negative = 0;
	if (n < 0)
		negative = 1;
	while (n != 0)
	{
		n = n / 10;
		counter ++;
	}
	if (negative == 1)
		return (counter + 2);
	return (counter + 1);
}

static char	*ft_hard_return(int n)
{
	char	*str;
	int		i;

	str = NULL;
	i = 0;
	if (n == 0)
	{
		str = (char *)malloc(2 * sizeof(char));
		if (!str)
			return (NULL);
		*(str + 0) = '0';
		*(str + 1) = '\0';
	}
	else if (n == INT_MIN)
	{
		str = (char *)malloc(12 * sizeof(char));
		if (!str)
			return (NULL);
		ft_strlcpy(str, "-2147483648", 12);
	}		
	return (str);
}

static int	ft_is_negative(int n)
{
	int	sign;

	sign = -1;
	if (n < 0)
		return (n * sign);
	else
		return (n);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		temp;
	int		len;

	len = n_counter(n);
	if (n == 0 || n == INT_MIN)
		return (ft_hard_return(n));
	temp = ft_is_negative(n);
	result = (char *) malloc(n_counter(n) * sizeof(char));
	if (!result)
		return (NULL);
	if (n < 0)
		result[0] = '-';
	result[len - 1] = '\0';
	while (temp != 0)
	{	
		result[(len--) - 2] = (temp % 10) + '0';
		temp = temp / 10;
	}
	return (result);
}
