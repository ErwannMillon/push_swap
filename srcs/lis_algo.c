#include "push_swap.h"
void	update_lis_arrays(int *lis, int *prev_index, int i, int j)
{
	lis[i] = lis[j] + 1;
	prev_index[i] = j;
}

void	init_lis_arrays(int *lis, int *prev_index, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		lis[i] = 1;
		prev_index[i] = i;
		i++;
	}
	ft_print_arr(lis, len, 0);
	ft_printf("\n");
	ft_print_arr(prev_index, len, 0);

}

int	*lis_len(int *arr, int len)
{
	int			*lis;
	int			*prev_index;
	int			i;
	int			j;
	int			**results;

	i = 1;
	lis = malloc(sizeof(int) * (len + 1));
	prev_index = malloc(sizeof(int) * (len + 1));
	init_lis_arrays(lis, prev_index, len);
	results = malloc(sizeof(int *) * 2);
	while (i < len)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
				update_lis_arrays(lis, prev_index, i, j);
			j++;
		}
		i++;
	}
	results[0] = lis;
	results[1] = prev_index;
	return (results);
}

int	*lis_arr(int *arr, int len)
{
	int max_len;
	int	index_to_add;
	int	i;
	int	subsequence;
	int 

	//Get max in this loop, then mallox sub to maxlen, then count down the indexes from maxlen to do reverse opti
	while (i < len)
	{
		if max_len < lis[i]
		{
			idx = prev[idx];
			
		}
}