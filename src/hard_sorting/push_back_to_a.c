/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:12:21 by oait-bad          #+#    #+#             */
/*   Updated: 2023/02/21 15:58:52 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	fixing(t_node **a)
{
	if (ft_lstsize(*a) > 1)
	{
		if ((*a)->data > (*a)->next->data)
			swap_a(a);
	}
}

void	move_to_top(t_node **a, t_node **b, int data)
{
	int	i;

	i = 1;
	fixing(a);
	while (1)
	{
		i = get_index(*b, data);
		if (i == 0)
		{
			push_a(b, a);
			break ;
		}
		else if (i > ft_lstsize(*b) / 2)
			rev_rotate_b(b);
		else
			rotate_b(b);
	}
	fixing(a);
}

int	*push_back(t_node **b)
{	
	t_type	type;

	type.str = (int *)malloc(sizeof(int) * 2);
	type.max = get_max_number(*b);
	type.sec_max = get_sec_max_num(*b, type.max);
	if (get_index(*b, type.max) < ft_lstsize(*b) / 2)
		type.res = get_index(*b, type.max) + 1;
	else
		type.res = (ft_lstsize(*b) - get_index(*b, type.max)) + 2;
	if (get_index(*b, type.sec_max) < ft_lstsize(*b) / 2)
		type.res2 = get_index(*b, type.sec_max) + 1;
	else
		type.res2 = (ft_lstsize(*b) - get_index(*b, type.sec_max)) + 2;
	if (type.res < type.res2)
	{
		type.str[0] = type.max;
		type.str[1] = type.sec_max;
	}
	else
	{
		type.str[0] = type.sec_max;
		type.str[1] = type.max;
	}
	return (type.str);
}

void	push_back_to_a(t_node **a, t_node **b)
{
	int	*str;
	int	max;

	str = 0;
	while (ft_lstsize(*b))
	{
		if (ft_lstsize(*b) == 1)
		{
			push_a(b, a);
			continue ;
		}
		str = push_back(b);
		max = get_max_number(*b);
		if (str[0] == max)
			move_to_top(a, b, str[0]);
		else
		{
			move_to_top(a, b, str[0]);
			move_to_top(a, b, str[1]);
		}
		free(str);
	}
	free (*b);
}
