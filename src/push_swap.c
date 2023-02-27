/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:48:38 by oait-bad          #+#    #+#             */
/*   Updated: 2023/02/27 02:35:22 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	num_check(int argc, char **argv)
{
	if (check_error(argc, argv))
	{	
		write(1, "Error\n", 6);
		exit(1);
	}
}

void	dup_check(t_node *a)
{
	if (check_doubles(a))
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = 0;
	b = 0;
	if (argc == 1)
		return (0);
	split_args(argv, &a);
	already_sorted(a);
	num_check(argc, argv);
	dup_check(a);
	get_rank(&a);
	if (ft_lstsize(a) == 2 && a->data > a->next->data)
		swap_a(&a);
	else if (ft_lstsize(a) == 3)
		sort_three_numbers(&a);
	else if (ft_lstsize(a) <= 5 && ft_lstsize(a) > 3)
		sort_five_numbers(&a, &b);
	else if (ft_lstsize(a) > 5 && ft_lstsize(a) <= 100)
		sort_hundred_numbers(&a, &b, 4);
	else if (ft_lstsize(a) > 100)
		sort_hundred_numbers(&a, &b, 9);
}
