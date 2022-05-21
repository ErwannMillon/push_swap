#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "ft_printf.h"
# include <stdio.h>

# define PA 1
# define PB 2
# define SA 3
# define SB 4
# define SS 5
# define RR 6
# define RA 7
# define RB 8
# define RRB 9
# define RRA 10
# define RRR 11

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
void		init_lis_arrays(int *lis, int *prev_index, int len);
void		update_lis_arrays(int *lis, int *prev_index, int i, int j);
int			*get_lis_max(int *arr, int len, const int *lis, const int *prev);
void		free_lis_vars(const int **len_and_prev, int *max_and_addindex);
t_arr		get_lis_arr(int *arr, int len);
t_arr		get_rotating_lis(int *arr, int len);
const int	**lis_len(const int *arr, int len);
t_arr		unsorted_lis_filter(t_arr lis, t_arr a);
//STACK OPERATIONS
void		p(t_node **src, t_node **dest);
void		r(t_node **root);
void		rr(t_node **root);
void		s(t_node **root);
//MOVE OPERATIONS
t_arr		move_to_top(int num, t_node *root);

//MOVE UNSORTED TO B
int			get_num_to_push(t_arr sub, t_node *a, t_arr moved);

//LIST SEARCH UTILS
int			dist_to_top(int num, t_node *root);
int			dist_to_bottom(int num, t_node *root);
int			ft_get_list_index(int num, t_node *root);

//ARR UTILS
t_arr		extend_path(t_arr arr, t_arr extension);

//LIST UTILS
int			ft_list_len(t_node *lst);
t_node		*ft_last_elem(t_node *lst);
void		ft_print_list(t_node *root);
//PARSING
t_node		*create_list(int *a, int len, t_arr sortedarr);
t_arr		parse_args_to_arr(int argc, char **argv);
void		ft_print_stacks(t_node *a, t_node *b);
//FREE FUNCTIONS
void		exit_cleanup(t_arr lis, t_arr sortedarr, t_node *a, t_arr arr);
void		ft_free_list(t_node *root);
//NUM UTILS
int			min(int a, int b);
int			max(int a, int b);

#endif