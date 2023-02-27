/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:20:21 by oait-bad          #+#    #+#             */
/*   Updated: 2023/02/23 02:14:03 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rev_rotate_b(t_node **b)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = *b;
	tmp2 = *b;
	if (!tmp || !tmp->next)
		return ;
	while (tmp->next)
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	tmp2->next = NULL;
	ft_lstadd_front(b, tmp);
}
