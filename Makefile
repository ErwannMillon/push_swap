SRCS := main.c \
		input_parse.c \
		list_utils.c \
		stack_operations.c
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
INCLUDEDIR = ./headers
SRCDIR = ./srcs
ASAN = -fsanitize=address -g
LIBFTDIR = $(SRCDIR)/libftextended
LIBFTINCLUDES = $(LIBFTDIR)/headers
SRCSPREFIX = $(addprefix $(SRCDIR)/, $(SRCS))
OBJS := $(SRCSPREFIX:%.c=%.o)
#ADD CFLAGS!!!

%.o: %.c
	gcc -ggdb -I$(INCLUDEDIR) -I$(LIBFTINCLUDES) $(ASAN) -c $< -o $@
all: $(NAME)
$(NAME): $(LIBFTDIR)/libft.a $(OBJS)
	gcc -ggdb $(OBJS) $(ASAN) -o $(NAME) $(LIBFTDIR)/libft.a
$(LIBFTDIR)/libft.a:
	$(MAKE) -C $(LIBFTDIR)
test: $(NAME)
	gcc -ggdb $(SRCDIR)/main.c $(SRCS) $(LIBFTDIR)/libft.a
asan: $(OBJS)
	gcc -fsanitize=address $(OBJS) -o $(NAME)
git:
	git add $(SRCSPREFIX) Makefile $(INCLUDEDIR)
clean:
	$(MAKE) -C $(LIBFTDIR)/ clean
	rm -f $(OBJS)
fclean: clean
	$(MAKE) -C $(LIBFTDIR)/ fclean
	rm -f $(NAME)
re: fclean $(NAME)

.PHONY:	all clean fclean re 
