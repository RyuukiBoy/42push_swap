/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_ab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:40:37 by oait-bad          #+#    #+#             */
/*   Updated: 2023/02/23 02:14:20 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rev_rotate(t_node **a)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = *a;
	tmp2 = *a;
	if (!*a || !(*a)->next)
		return ;
	while (tmp->next)
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	tmp2->next = NULL;
}

void	rev_rotate_ab(t_node **a, t_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
}
