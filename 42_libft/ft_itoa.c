/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:36:11 by alassiqu          #+#    #+#             */
/*   Updated: 2023/11/13 20:24:26 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_convert(char *str, long i, int sign, int digits)
{
	if (sign)
		str[0] = '-';
	while (--digits >= sign)
	{
		str[digits] = i % 10 + '0';
		i /= 10;
	}
}

char	*ft_itoa(int n)
{
	int		digits;
	int		sign;
	char	*str;
	long	i;

	i = (long)n;
	sign = 0;
	if (i < 0)
	{
		sign = 1;
		i *= -1;
	}
	digits = ft_count_digits(i) + sign;
	str = (char *)malloc(digits + 1);
	if (!str)
		return (NULL);
	str[digits] = '\0';
	ft_convert(str, i, sign, digits);
	return (str);
}
