#include "../includes/push_swap.h"

int		check_swap(t_element *a, int count, count_func calc_count, set_mark mark)
{
	int		new_count;
	int		max_count;
	t_element	*first;

	do_swap(&a);
	max_count = count;
	new_count = calc_count(a);
	first = 0;
	while (a != first)
	{
		new_count = calc_count(a);
		if (new_count > max_count)
		{
			mark(a);
			max_count = new_count;
		}
		if (!first)
			first = a;
		do_roll(&a, 1);
	}
	do_swap(&a);
	return (max_count > count);
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
		if (check_swap(*a, get_marked_count(*a), markup_index_count, markup_index_set))
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
		if (check_swap(*a, get_marked_count(*a), markup_value_count, markup_value_set))
		{
			if (!do_sa(a, str))
				return (0);
		}
		else if ((*a)->is_marked && !do_ra(a, str))
			return (0);
		else if (!(*a)->is_marked && !do_pb(a, b, str))
			return (0);
	}
	return (1);
}
