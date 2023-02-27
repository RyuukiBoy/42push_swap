/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:54:50 by oait-bad          #+#    #+#             */
/*   Updated: 2023/02/18 16:38:51 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	get_min_pos(t_node *list)
{
	int		num;
	int		i;
	int		k;
	t_node	*temp;

	i = 0;
	k = i;
	temp = list;
	num = list->data;
	while (temp)
	{
		if (temp->data < num)
		{
			k = i;
			num = temp->data;
		}
		temp = temp->next;
		i++;
	}
	return (k);
}

void	sort_five_numbers(t_node **a, t_node **b)
{
	int	index;

	while (ft_lstsize(*a) > 3)
	{
		index = get_min_pos(*a);
		if (index == 0)
			push_b(a, b);
		else if (index <= ft_lstsize(*a) / 2)
			rotate_a(a);
		else if (index > ft_lstsize(*a) / 2)
			rev_rotate_a(a);
	}
	sort_three_numbers(a);
	while (*b)
		push_a(b, a);
}
