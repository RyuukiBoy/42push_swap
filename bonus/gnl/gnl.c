/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:48:16 by oait-bad          #+#    #+#             */
/*   Updated: 2023/01/06 16:17:23 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char	*ft_find_nl(int fd, char *str)
{
	char	*buff;
	ssize_t	i;

	i = 1;
	buff = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!ft_strchr(str, '\n') && i)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free (str);
			free (buff);
			return (NULL);
		}
		buff[i] = '\0';
		str = ft_strjoin_gnl(str, buff);
	}
	free (buff);
	return (str);
}

char	*ft_after_nl(char *str)
{
	char	*nstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	i++;
	nstr = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!nstr)
	{
		free (str);
		return (NULL);
	}
	while (str[i])
		nstr[j++] = str[i++];
	nstr[j] = '\0';
	free (str);
	return (nstr);
}

char	*ft_line_rt(char *str)
{
	char	*nls;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!ft_strlen(str))
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		nls = malloc(sizeof(char) * (i + 2));
	else
		nls = malloc(sizeof(char) * (i + 1));
	if (!nls)
		return (NULL);
	while (j <= i && str[j])
	{	
		nls[j] = str[j];
		j++;
	}
	nls[j] = '\0';
	return (nls);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	str = ft_find_nl(fd, str);
	if (!str)
		return (NULL);
	ret = ft_line_rt(str);
	str = ft_after_nl(str);
	return (ret);
}
