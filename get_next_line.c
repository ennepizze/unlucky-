/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguido <nguido@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 09:26:21 by nguido            #+#    #+#             */
/*   Updated: 2021/02/10 15:25:06 by nguido           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	i = 0;
	len = count * size;
	if (!(ptr = malloc((count * size) * sizeof(char))))
		return (NULL);
	while (i < len)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

int		ft_eol(char **s, char **line, int fd)
{
	size_t i;

	i = 0;
	while (s[fd][i] != '\0')
		i++;
	*line = ft_substr(s[fd], 0, i);
	free(s[fd]);
	s[fd] = NULL;
	return (0);
}

int		ft_return_line(char **s, char **line, int fd)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (s[fd][i] != '\n')
		i++;
	*line = ft_substr(s[fd], 0, i);
	tmp = ft_strdup(&s[fd][i + 1]);
	free(s[fd]);
	s[fd] = ft_strdup(tmp);
	free(tmp);
	return (1);
}

int		ft_eof(char **line)
{
	*line = ft_calloc(sizeof(char), 1);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*s[255];
	char		*tmp;
	int			ret;
	char		buffer[BUFFER_SIZE + 1];

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if ((!s[fd] && (s[fd] = ft_calloc(1, 1))) || s[fd])
			tmp = ft_strjoin(s[fd], buffer);
		free(s[fd]);
		s[fd] = ft_strdup(tmp);
		free(tmp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (s[fd] != NULL && ft_strchr(s[fd], '\n'))
		return (ft_return_line(s, line, fd));
	else if (ret == 0 && s[fd] != NULL)
		return (ft_eol(s, line, fd));
	return (ft_eof(line));
}
