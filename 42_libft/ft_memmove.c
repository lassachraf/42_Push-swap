/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:49:08 by alassiqu          #+#    #+#             */
/*   Updated: 2023/11/13 12:07:57 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	s1 = (unsigned char *)src;
	s2 = (unsigned char *)dest;
	i = 0;
	if (s2 > s1)
		while (n-- > 0)
			s2[n] = s1[n];
	else
	{
		while (i < n)
		{
			s2[i] = s1[i];
			i++;
		}
	}
	return (dest);
}
