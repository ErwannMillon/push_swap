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

const int	**lis_len(const int *arr, int len)
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
	return ((const int **)results);
}

int	*get_lis_max(int *arr, int len, const int *lis, const int *prev)
{
	int			max_len;
	int			index_to_add;
	int			i;
	int			*results;

	results = malloc(2 * sizeof(int));
	index_to_add = 0;
	i = 0;
	//Get max in this loop, then mallox sub to maxlen, then count down the indexes from maxlen to do reverse opti
	while (i < len)
	{
		if (max_len < lis[i])
		{
			max_len = lis[i];
			index_to_add = i;
		}
		i++;
	}
	results[0] = max_len;
	results[1] = index_to_add;
	return (results);
}

void	free_lis_vars(const int **len_and_prev, int *max_and_addindex)
{
	free((void *)len_and_prev[0]);
	free((void *)len_and_prev[1]);
	free((void *)len_and_prev);
	free((void *)max_and_addindex);
}

t_arr get_lis_arr(int *arr, int len)
{
	const int	**len_and_prev = lis_len(arr, len);
	int			*max_and_addindex;
	int			index_to_add;
	t_arr		subsequence;
	int			max_index;

	max_and_addindex = get_lis_max(arr, len, len_and_prev[0], len_and_prev[1]);
	max_index = max_and_addindex[0] - 1;
	index_to_add = max_and_addindex[1];
	subsequence.len = max_index + 1;
	subsequence.arr = malloc((max_index + 2) * sizeof(int));
	while (index_to_add != len_and_prev[1][index_to_add])
	{
		index_to_add = len_and_prev[1][index_to_add];
		subsequence.arr[max_index] = arr[index_to_add];
		max_index--;
	}
	free_lis_vars(len_and_prev, max_and_addindex);
	ft_print_arr(subsequence.arr, subsequence.len, 0);
	return (subsequence);
}