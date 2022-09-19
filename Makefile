BONUSSRCS = checker.c \
			checker2.c \
			input_parse.c \
			handle_input_errors.c \
			num_utils.c \
			composite_stack_operations.c \
			cleanup_functions.c \
			list_utils.c \
			list_search.c \
			list_utils2.c \
			stack_operations.c
SRCS := main.c \
		input_parse.c \
		list_utils.c \
		stack_operations.c \
		lis_algo.c \
		lis_algo2.c \
		cleanup_functions.c \
		list_search.c \
		num_utils.c \
		move_operations.c \
		pathfind_from_b.c \
		move_unsorted_to_b.c \
		list_utils2.c \
		reinsert_after_target.c \
		reinsert_before_target.c \
		reinsert_before_closest.c \
		composite_stack_operations.c \
		handle_input_errors.c
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
INCLUDEDIR = ./headers
SRCDIR = ./srcs
ASAN = -fsanitize=address -g
LIBFTDIR = $(SRCDIR)/libftextended
LIBFTINCLUDES = $(LIBFTDIR)/headers
SRCSPREFIX = $(addprefix $(SRCDIR)/, $(SRCS))
BONUSPREFIX= $(addprefix $(SRCDIR)/, $(BONUSSRCS))
OBJS := $(SRCSPREFIX:%.c=%.o)
BONUSOBJS := $(BONUSPREFIX:%.c=%.o)
#ADD CFLAGS!!!

%.o: %.c
	gcc -ggdb3 -I$(INCLUDEDIR) -I$(LIBFTINCLUDES) -c $< -o $@
all: $(NAME)
$(NAME): $(LIBFTDIR)/libft.a $(OBJS)
	gcc -ggdb3 $(OBJS) $(CFLAGS) -o $(NAME) $(LIBFTDIR)/libft.a
$(LIBFTDIR)/libft.a:
	# git submodule init
	# git submodule update
	$(MAKE) -C $(LIBFTDIR)
test: $(LIBFTDIR)/libft.a $(OBJS)
	gcc -g $(OBJS) -o test_$(NAME) $(LIBFTDIR)/libft.a
checker: $(LIBFTDIR)/libft.a $(BONUSOBJS)
	gcc -ggdb3 $(CFLAGS) $(BONUSOBJS) -o checker $(LIBFTDIR)/libft.a
bonus: checker
asan: $(LIBFTDIR)/libft.a $(OBJS)
	gcc -fsanitize=address $(OBJS) -o $(NAME) $(LIBFTDIR)/libft.a
git:
	git add $(SRCSPREFIX) Makefile $(INCLUDEDIR) .gitmodules
clean:
	$(MAKE) -C $(LIBFTDIR)/ clean
	rm -f $(OBJS)
fclean: clean
	$(MAKE) -C $(LIBFTDIR)/ fclean
	rm -f $(NAME)
re: fclean $(NAME) test
proj_clean:
	rm -f $(OBJS)
	rm -f $(BONUSOBJS)
	rm -f $(NAME)
re_proj: proj_clean $(NAME)
.PHONY:	all clean fclean re bonus
