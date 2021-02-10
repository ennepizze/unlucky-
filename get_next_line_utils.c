/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguido <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:02:57 by nguido            #+#    #+#             */
/*   Updated: 2021/02/09 10:53:37 by nguido           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*s1;
	size_t			i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (!(s1 = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	if (start >= ft_strlen(s))
		return (s1);
	while (s[i] != '\0' && (i < len))
	{
		s1[i] = s[start];
		i++;
		start++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;

	i = ft_strlen(s1);
	if (!(s2 = (char *)malloc((i + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

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

char	*ft_strchr(const char *s, int c)
{
	char	*s1;
	int		i;

	s1 = (char *)s;
	i = 0;
	if ((char)c == '\0' && s1[i] != '\0')
	{
		while (s1[i] != '\0')
		{
			i++;
		}
		s1 = &s1[i];
		return (s1);
	}
	if (s1[i] == (char)c)
		return (&s1[i]);
	while (s1[i] && s1[i] != (char)c)
	{
		i++;
		if (s1[i] == (char)c)
			return (&s1[i]);
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*s3;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	j = 0;
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(s3 = (char *)malloc((i + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	return (s3);
}
