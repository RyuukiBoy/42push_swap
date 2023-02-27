/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rank.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:13:03 by oait-bad          #+#    #+#             */
/*   Updated: 2023/02/22 00:28:08 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*copy_list(t_node *a)
{
	t_node	*tmp;
	t_node	*copy;

	copy = 0;
	tmp = a;
	while (tmp)
	{
		ft_lstadd_back(&copy, ft_lstnew(tmp->data));
		tmp = tmp->next;
	}
	return (copy);
}

t_node	*sorted_stack(t_node *a)
{
	int		tmp;
	t_node	*tmp1;

	tmp1 = a;
	if (!tmp1)
		return (0);
	while (tmp1->next)
	{
		if (tmp1->data > tmp1->next->data)
		{	
			tmp = tmp1->data;
			tmp1->data = tmp1->next->data;
			tmp1->next->data = tmp;
			tmp1 = a;
		}
		else
			tmp1 = tmp1->next;
	}
	tmp1 = a;
	return (tmp1);
}

void	free_list(t_node *a)
{
	t_node	*tmp;

	while (a)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
}

void	get_rank(t_node **a)
{
	int		i;
	t_node	*temp;
	t_node	*tmp;
	t_node	*temp1;

	i = 1;
	temp1 = *a;
	tmp = sorted_stack(copy_list(*a));
	temp = tmp;
	while (temp)
	{
		while (temp1)
		{
			if (temp1->data == temp->data)
			{
				temp1->rank = i;
				break ;
			}
			temp1 = temp1->next;
		}
		i++;
		temp1 = *a;
		temp = temp->next;
	}
	free_list(tmp);
}
