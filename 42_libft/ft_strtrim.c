/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 23:02:30 by alassiqu          #+#    #+#             */
/*   Updated: 2023/11/14 16:06:50 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_copy(char *res, char *s, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	char	*s;
	int		len;

	if (!s1)
		return (NULL);
	s = (char *)s1;
	if (!set || !set[0])
		return (ft_strdup(s1));
	while (*s && ft_is_char_in_set(*s, set))
		s++;
	if (!*s)
		return (ft_strdup(s));
	len = ft_strlen(s) - 1;
	while (ft_is_char_in_set(s[len], set))
		len--;
	len++;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res = ft_copy(res, s, len);
	return (res);
}
