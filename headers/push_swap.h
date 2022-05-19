#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "ft_printf.h"
# include <stdio.h>

typedef struct s_node
{
	int				num;
	int				sorted_index;
	int				previous_in_sorted;
	int				next_in_sorted;
	struct s_node	*next;
}				t_node;

typedef struct s_arr
{
	int	*arr;
	int	len;
}		t_arr;

//STACK OPERATIONS
void	p(t_node **src, t_node **dest);
void	s(t_node **root);
//LIST UTILS
void	ft_print_list(t_node *root);
//PARSING
int		parse_args(int argc, char **argv);

#endif