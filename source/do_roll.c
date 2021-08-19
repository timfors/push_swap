#include "../includes/push_swap.h"

void	do_roll(t_element **el, int direction)
{
	t_element	*first;
	t_element	*tmp;
	int		size;

	if (!el || elem_size(*el) <= 1 || !direction)
		return ;
	size = elem_size(*el);
	if (size == 2)
		do_swap(el);
	else if (direction > 0)
	{
		first = *el;
		*el = first->next;
		first->next = 0;
		elem_last(*el)->next = first;
	}
	else 
	{
		tmp = elem_get(*el, size - 2);
		tmp->next->next = *el;
		*el = tmp->next;
		tmp->next = 0;
	}
}

int	do_ra(t_element **a, t_string **str)
{
	do_roll(a, 1);
	return (string_add(str, "ra\n"));
}

int	do_rb(t_element **b, t_string **str)
{
	do_roll(b, 1);
	return (string_add(str, "rb\n"));
}

int	do_rr(t_element **a, t_element **b, t_string **str)
{
	do_roll(a, 1);
	do_roll(b, 1);
	return (string_add(str, "rr\n"));
}
