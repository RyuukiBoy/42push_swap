/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 23:38:15 by oait-bad          #+#    #+#             */
/*   Updated: 2023/02/22 14:05:44 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	swap_a(t_node **list)
{
	t_node	*tmp;

	if (!*list || !(*list)->next)
		return ;
	tmp = (*list)->next;
	(*list)->next = tmp->next;
	tmp->next = *list;
	*list = tmp;
}
