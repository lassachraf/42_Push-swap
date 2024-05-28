/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 08:40:50 by alassiqu          #+#    #+#             */
/*   Updated: 2024/03/05 20:56:07 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *str, char *buff)
{
	if (buff)
		free(buff);
	return (str);
}

char	*ft_read(int fd, char *buff)
{
	char		*str;
	ssize_t		byte_readed;

	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (ft_free(NULL, buff));
	byte_readed = 1;
	while (byte_readed > 0)
	{
		byte_readed = read(fd, str, BUFFER_SIZE);
		if (byte_readed == -1)
			return (free(str), ft_free(NULL, buff));
		str[byte_readed] = '\0';
		buff = ft_free(ft_strjoin(buff, str), buff);
		if (ft_strchr(str, '\n') >= 0)
			break ;
	}
	free(str);
	return (buff);
}

char	*ft_get_line(char *buff)
{
	char	*line;
	int		i;
	int		check;

	check = 2;
	i = 0;
	if (buff[0] == '\0')
		return (NULL);
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (buff[i] == '\0')
		check = 1;
	line = malloc(sizeof(char) * i + check);
	if (!line)
		return (ft_free(NULL, buff));
	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
	{
		line[i] = buff[i];
		i++;
	}
	if (check == 2)
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_remainder(char *buff)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!buff)
		return (NULL);
	if (buff[0] == '\0')
		return (ft_free(NULL, buff));
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (buff[i] == '\0')
		return (ft_free(NULL, buff));
	line = malloc(sizeof(char) * (ft_strlen(buff) - i + 1));
	if (!line)
		return (free(buff), NULL);
	i++;
	while (buff[i] != '\0')
		line[j++] = buff[i++];
	line[j] = '\0';
	free(buff);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	line = NULL;
	if (fd == 42)
	{
		free(buff);
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free(NULL, buff));
	buff = ft_read(fd, buff);
	if (!buff)
		return (NULL);
	line = ft_get_line(buff);
	buff = ft_remainder(buff);
	return (line);
}
