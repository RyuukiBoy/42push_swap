/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 00:21:03 by oait-bad          #+#    #+#             */
/*   Updated: 2023/02/25 01:56:26 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_n_swap_moves(t_node **a, t_node **b, char *str)
{
	if (!ft_strcmp(str, "pa\n"))
		push_a(b, a);
	else if (!ft_strcmp(str, "pb\n"))
		push_b(a, b);
	else if (!ft_strcmp(str, "sa\n"))
		swap_a(a);
	else if (!ft_strcmp(str, "sb\n"))
		swap_b(b);
	else if (!ft_strcmp(str, "ss\n"))
		swap_ab(a, b);
	else if (!ft_strcmp(str, "ra\n"))
		rotate_a(a);
	else if (!ft_strcmp(str, "rb\n"))
		rotate_b(b);
	else if (!ft_strcmp(str, "rr\n"))
		rotate_ab(a, b);
	else if (!ft_strcmp(str, "rra\n"))
		rev_rotate_a(a);
	else if (!ft_strcmp(str, "rrb\n"))
		rev_rotate_b(b);
	else if (!ft_strcmp(str, "rrr\n"))
		rev_rotate_ab(a, b);
	else
		put_error();
}

int	check_sorted(t_node *a)
{
	t_node	*tmp;

	tmp = a;
	while (tmp && tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	*buff;

	a = 0;
	b = 0;
	split_args(argv, &a);
	if (check_error(argc, argv) || check_doubles(a))
		put_error();
	if (argc < 2)
		return (0);
	buff = get_next_line(0);
	while (buff)
	{
		push_n_swap_moves(&a, &b, buff);
		free(buff);
		buff = get_next_line(0);
	}
	if (check_sorted(a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
