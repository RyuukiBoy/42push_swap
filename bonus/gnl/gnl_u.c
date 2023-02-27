/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:48:59 by oait-bad          #+#    #+#             */
/*   Updated: 2023/02/22 02:46:35 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	len;
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	res = (malloc(len * (sizeof (*res)) + 1));
	if (!res)
		return (NULL);
	while (s1[j])
		res[i++] = s1[j++];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = 0;
	free (s1);
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*s2;
	char	*s;

	s2 = (char *)s1;
	s = (char *)malloc(sizeof(char) * ft_strlen(s2) + 1);
	i = 0;
	if (!s)
		return (0);
	while (i < ft_strlen(s2))
	{
		s[i] = s2[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

size_t	ft_strlen(const char *str)
{	
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
