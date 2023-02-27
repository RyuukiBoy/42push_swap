/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:44:31 by oait-bad          #+#    #+#             */
/*   Updated: 2023/02/24 18:58:11 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>

typedef struct s_node
{
	int				data;
	int				rank;
	struct s_node	*next;
}					t_node;

typedef struct s_type
{
	int		max;
	int		sec_max;
	int		res;
	int		res2;
	int		*str;
	int		i;
	int		count;
	int		size;
}			t_type;

//additional functions
void	split_args(char **argv, t_node **list);
int		check_error(int argc, char **argv);
void	get_rank(t_node **a);
int		check_doubles(t_node *list);
void	already_sorted(t_node *a);
int		get_max_number(t_node *a);
int		get_sec_max_num(t_node *a, int max);
int		get_index(t_node *b, int index);
void	put_error(void);
void	free_split(char **split);

//easy sorting
void	sort_three_numbers(t_node **a);
void	sort_five_numbers(t_node **a, t_node **b);

// hard sorting
void	sort_hundred_numbers(t_node **a, t_node **b, int base);
void	push_back_to_a(t_node **a, t_node **b);

//includes
int		ft_atoi(char *str);
t_node	*ft_lstnew(int data);
char	**ft_split(char const *s, char c);
void	ft_lstadd_back(t_node **lst, t_node *new);
void	ft_lstadd_front(t_node **lst, t_node *new);
int		ft_lstsize(t_node *lst);
int		ft_strcmp(char *s1, char *s2);

//operators
void	swap_a(t_node **list);
void	swap_b(t_node **list);
void	swap_ab(t_node **a, t_node **b);
void	push_a(t_node **b, t_node **a);
void	push_b(t_node **a, t_node **b);
void	rotate_a(t_node **list);
void	rotate_b(t_node **list);
void	rotate_ab(t_node **a, t_node **b);
void	rev_rotate_a(t_node **list);
void	rev_rotate_b(t_node **list);
void	rev_rotate_ab(t_node **a, t_node **b);

//bonus checker
char	*get_next_line(int fd);
void	num_check(int argc, char **argv);
void	dup_check(t_node *a);
void	rotate(t_node **a);
void	rev_rotate(t_node **a);
void	swap(t_node **a);

#endif