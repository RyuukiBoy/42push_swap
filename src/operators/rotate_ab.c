/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 23:57:12 by oait-bad          #+#    #+#             */
/*   Updated: 2023/02/22 01:25:49 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rotate(t_node **a)
{
	t_node	*tmp;

	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	ft_lstadd_back(a, tmp);
}

void	rotate_ab(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
