/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:11:39 by oait-bad          #+#    #+#             */
/*   Updated: 2023/02/26 20:18:08 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	split_error(char **ar)
{
	free_split(ar);
	put_error();
}

void	norme_thing(char **ar, t_node **list)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (ar[i][j] == '-' || ar[i][j] == '+')
		j++;
	if (!ar[i][j])
		split_error(ar);
	while (ar[i][j] && ar[i][j] >= '0' && ar[i][j] <= '9')
		j++;
	if (ar[i][j])
		split_error(ar);
	ft_lstadd_back(list, ft_lstnew(ft_atoi(ar[i])));
}

void	split_args(char **argv, t_node **list)
{
	int		i;
	int		k;
	char	**ar;

	i = 1;
	k = 0;
	while (argv[i])
	{
		ar = ft_split(argv[i], ' ');
		if (!ar[0])
			put_error();
		while (ar[k])
			norme_thing(&ar[k++], list);
		free_split(ar);
		k = 0;
		i++;
	}
}
