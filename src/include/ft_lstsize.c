/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:56:16 by oait-bad          #+#    #+#             */
/*   Updated: 2023/02/20 22:08:47 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_lstsize(t_node *lst)
{
	int	k;

	k = 0;
	while (lst)
	{
		lst = lst->next;
		k++;
	}
	return (k);
}
