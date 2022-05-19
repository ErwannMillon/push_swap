#include "push_swap.h"

void	s(t_node **root)
{
	t_node	*second;
	t_node	*third;
	t_node	*first;

	if (root && *root && (*root)->next)
	{
		first = *root;
		second = (*root)->next;
		(*root)->next = (*root)->next->next;
		second->next = first;
		*root = second;
	}
}

void	p(t_node **src, t_node **dest)
{
	t_node	*tmp;

	tmp = *src;
	*src = (*src)->next;
	if (dest && *dest)
		tmp->next = (*dest);
	*dest = tmp;

}
