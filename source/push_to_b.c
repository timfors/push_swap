#include "../includes/push_swap.h"

int		check_swap(t_element *a, int count, count_func calc_count)
{
	int	new_count;

	do_swap(&a);
	new_count = calc_count(a);
	do_swap(&a);
	return (new_count > count);
}

int		get_marked_count(t_element *a)
{
	int	res;

	res = 0;
	while (a)
	{
		if (a->is_marked)
			res++;
		a = a->next;
	}
	return (res);
}

static int	contains_unmarked(t_element *a)
{
	while (a)
	{
		if (!a->is_marked)
			return (1);
		a = a->next;
	}
	return (0);
}

int	push_to_b_index(t_element **a, t_element **b, t_string **str)
{
	while	(contains_unmarked(*a))
	{
		print_elems(*a, *b);
		if (check_swap(*a, get_marked_count(*a), markup_index_count))
		{
			if (!do_sa(a, str))
				return (0);
			markup_index_set(*a);
		}
		else if ((*a)->is_marked && !do_ra(a, str))
			return (0);
		else if (!(*a)->is_marked && !do_pb(a, b, str))
			return (0);
	}
	return (1);
}

int	push_to_b_value(t_element **a, t_element **b, t_string **str)
{
	while	(contains_unmarked(*a))
	{
		print_elems(*a, *b);
		if (check_swap(*a, get_marked_count(*a), markup_value_count))
		{
			if (!do_sa(a, str))
				return (0);
			markup_value_set(*a);
		}
		else if ((*a)->is_marked && !do_ra(a, str))
			return (0);
		else if (!(*a)->is_marked && !do_pb(a, b, str))
			return (0);
	}
	return (1);
}
