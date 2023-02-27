/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 00:31:32 by oait-bad          #+#    #+#             */
/*   Updated: 2023/02/27 01:35:14 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_atoi(char *str)
{	
	int		i;
	int		sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{	
		if (str[i] == '-')
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{	
		nb = nb * 10 + (str[i] - '0');
		if (nb > INT_MAX || nb < INT_MIN)
			put_error();
		i++;
	}
	return (nb * sign);
}
