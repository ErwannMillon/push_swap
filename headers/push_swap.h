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

//LIS FUNCTIONS
int	*lis_len(int *arr, int len);

//STACK OPERATIONS
void	p(t_node **src, t_node **dest);
void	r(t_node **root);
void	rr(t_node **root);
void	s(t_node **root);
//LIST UTILS
t_node	*ft_last_elem(t_node *lst);
void	ft_print_list(t_node *root);
//PARSING
t_node	*create_list(int *a, int len, t_arr sortedarr);
t_arr	*parse_args_to_arr(int argc, char **argv);
void	ft_print_stacks(t_node *a, t_node *b);

#endif