/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:17:55 by oait-bad          #+#    #+#             */
/*   Updated: 2023/02/16 02:10:32 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rev_rotate_a(t_node **a)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = *a;
	tmp2 = *a;
	while (tmp->next)
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	tmp2->next = NULL;
	ft_lstadd_front(a, tmp);
	write(1, "rra\n", 4);
}
