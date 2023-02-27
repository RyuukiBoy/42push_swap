/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 23:50:17 by oait-bad          #+#    #+#             */
/*   Updated: 2023/02/22 14:05:49 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	swap(t_node **list)
{
	t_node	*tmp;

	if (!*list || !(*list)->next)
		return ;
	tmp = (*list)->next;
	(*list)->next = tmp->next;
	tmp->next = *list;
	*list = tmp;
}

void	swap_ab(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
}
