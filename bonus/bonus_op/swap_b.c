/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:41:39 by oait-bad          #+#    #+#             */
/*   Updated: 2023/02/22 14:05:52 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	swap_b(t_node **list)
{
	t_node	*tmp;

	if (!*list || !(*list)->next)
		return ;
	tmp = *list;
	*list = (*list)->next;
	tmp->next = (*list)->next;
	(*list)->next = tmp;
}
