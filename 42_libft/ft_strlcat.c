/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:52:28 by alassiqu          #+#    #+#             */
/*   Updated: 2023/11/14 10:25:50 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dlen;
	size_t	slen;

	if (!dst && !size)
		return (ft_strlen(src));
	slen = ft_strlen(src);
	j = ft_strlen(dst);
	dlen = j;
	if (size == 0 || size <= dlen)
		return (slen + size);
	i = 0;
	while (src[i] && i < size - dlen - 1)
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (dlen + slen);
}
