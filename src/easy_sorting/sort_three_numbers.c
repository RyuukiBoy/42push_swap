/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:09:40 by oait-bad          #+#    #+#             */
/*   Updated: 2023/02/13 11:47:27 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	get_max_pos(t_node	*list)
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
		if (temp->data > num)
		{
			k = i;
			num = temp->data;
		}
		temp = temp->next;
		i++;
	}
	return (k);
}

void	sort_three_numbers(t_node **a)
{
	int	index;

	index = get_max_pos(*a);
	if (ft_lstsize(*a) == 3)
	{
		if (index == 0)
			rotate_a(a);
		if (index == 1)
			rev_rotate_a(a);
		if ((*a)->data > (*a)->next->data)
			swap_a(a);
	}
}
