/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:48:32 by oait-bad          #+#    #+#             */
/*   Updated: 2023/01/06 22:03:28 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char *s2);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *s1);

#endif
