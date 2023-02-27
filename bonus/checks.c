/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 02:51:33 by oait-bad          #+#    #+#             */
/*   Updated: 2023/02/22 02:51:53 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	num_check(int argc, char **argv)
{
	if (check_error(argc, argv))
	{
		write(1, "Error\n", 6);
		exit(0);
	}
}

void	dup_check(t_node *a)
{
	if (check_doubles(a))
	{
		write(1, "Error\n", 6);
		exit(0);
	}
}
