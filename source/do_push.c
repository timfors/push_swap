#include "../includes/push_swap.h"

void	push_first(t_element **dst, t_element **src)
{
	t_element	*src_first;

	src_first = *src;
	*src = src_first->next;
	elem_push_front(dst, src_first);
}

int	do_pa(t_element **a, t_element **b, t_string **str)
{
	push_first(a, b);
	return (string_add(str, "pa\n"));
}

int	do_pb(t_element **a, t_element **b, t_string **str)
{
	push_first(b, a);
	return (string_add(str, "pb\n"));
}
