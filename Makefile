NAME= push_swap
BONUS_NAME= checker
CC= cc
CFLAGS = -Wall -Wextra -Werror

SRC= src/split_args.c \
     src/some_checks.c \
	 src/push_swap.c \
	 src/get_rank.c \
	 src/put_error.c \
	 src/easy_sorting/sort_three_numbers.c \
	 src/easy_sorting/sort_five_numbers.c \
	 src/hard_sorting/sort_hundred_numbers.c \
	 src/hard_sorting/push_back_to_a.c \
	 src/operators/push_a.c \
	 src/operators/push_b.c \
	 src/operators/swap_a.c \
	 src/operators/swap_b.c \
	 src/operators/swap_ab.c \
	 src/operators/rotate_a.c \
	 src/operators/rotate_b.c \
	 src/operators/rotate_ab.c \
	 src/operators/rev_rotate_a.c \
	 src/operators/rev_rotate_b.c \
	 src/operators/rev_rotate_ab.c \
	 src/include/ft_atoi.c \
	 src/include/ft_lstnew.c \
	 src/include/ft_split.c \
	 src/include/ft_lstadd_back.c \
	 src/include/ft_lstadd_front.c \
	 src/include/ft_lstsize.c \

BONUS= bonus/bonus_op/push_a.c \
	   bonus/bonus_op/push_b.c \
	   bonus/bonus_op/swap_a.c \
	   bonus/bonus_op/swap_b.c \
	   bonus/bonus_op/swap_ab.c \
	   bonus/bonus_op/rotate_a.c \
	   bonus/bonus_op/rotate_b.c \
	   bonus/bonus_op/rotate_ab.c \
	   bonus/bonus_op/rev_rotate_a.c \
	   bonus/bonus_op/rev_rotate_b.c \
	   bonus/bonus_op/rev_rotate_ab.c \
	   bonus/gnl/gnl.c \
	   bonus/gnl/gnl_u.c \
	   bonus/checker.c \
	   bonus/checks.c \
	   src/include/ft_strcmp.c \
	   src/include/ft_lstnew.c \
	   src/include/ft_lstadd_back.c \
	   src/include/ft_lstadd_front.c \
	   src/include/ft_atoi.c \
	   src/include/ft_split.c \
	   src/put_error.c \
	   src/split_args.c \
	   src/some_checks.c \


OBJ= $(SRC:.c=.o)

BONUS_OBJ= $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	 gcc $(CFLAGS) -o $(NAME) $(OBJ)

bonus: $(BONUS_OBJ)
	 gcc $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJ) 
	 
clean: 
	 rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	 rm -f $(NAME) $(BONUS_NAME)

re: fclean all