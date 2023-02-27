/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred_numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 00:08:15 by oait-bad          #+#    #+#             */
/*   Updated: 2023/02/21 19:05:03 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	get_max_number(t_node *a)
{
	int		max;
	t_node	*tmp;

	tmp = a;
	max = tmp->data;
	while (tmp)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->next;
	}
	return (max);
}

int	get_sec_max_num(t_node *a, int max)
{
	int		sec_max;
	t_node	*tmp;

	tmp = a;
	sec_max = tmp->data;
	if (tmp->data == max)
		sec_max = tmp->next->data;
	while (tmp)
	{
		if (tmp->data < max && tmp->data > sec_max)
			sec_max = tmp->data;
		tmp = tmp->next;
	}
	return (sec_max);
}

int	get_index(t_node *b, int index)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = b;
	while (tmp)
	{
		if (tmp->data == index)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	sort_hundred_numbers(t_node **a, t_node **b, int base)
{
	t_type	type;

	type.i = 1;
	type.count = 0;
	type.size = ft_lstsize(*a) / base;
	while (ft_lstsize(*a))
	{
		if ((*a)->rank <= type.i * type.size)
		{
			if ((*a)->rank >= (type.i * type.size) - (type.size / 2))
				push_b(a, b);
			else
			{
				push_b(a, b);
				rotate_b(b);
			}
			type.count++;
		}
		else
			rotate_a(a);
		if (type.count == type.size * type.i)
			type.i++;
	}
	push_back_to_a(a, b);
}
