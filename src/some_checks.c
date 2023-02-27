/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:23:46 by oait-bad          #+#    #+#             */
/*   Updated: 2023/02/27 01:35:03 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_error(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_doubles(t_node *a)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = a;
	if (!tmp)
		return (0);
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->data == tmp2->data)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

void	already_sorted(t_node *a)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = a;
	if (!tmp)
		return ;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			i++;
		tmp = tmp->next;
	}
	if (i == 0)
		exit(0);
}
