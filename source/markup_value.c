#include "../includes/push_swap.h"

void	markup_reset(t_element *el)
{
	while (el)
	{
		el->is_marked = 0;
		el = el->next;
	}
}

int	markup_value_count(t_element *el)
{
	int		result;
	int		roll_count;
	t_element	*first;
	t_element	*prev;

	prev = el;
	first = el;
	do_roll(&el, 1);
	roll_count = 1;
	result = 1;
	while (el != first && el->value > prev->value)
	{
		result++;
		prev = el;
		do_roll(&el, 1);
		roll_count++;
	}
	while (el != first && roll_count--)
		do_roll(&el, -1);
	return (result);
}

void	markup_value_set(t_element *el)
{
	t_element	*first;
	t_element	*prev;
	int		roll_count;

	markup_reset(el);
	prev = el;
	roll_count = 1;
	el->is_marked = 1;
	first = prev;
	do_roll(&el, 1);
	while (el != first && el->value > prev->value)
	{
		el->is_marked = 1;
		prev = el;
		do_roll(&el, 1);
		roll_count++;
	}
	while (el != first && roll_count--)
		do_roll(&el, -1);
}

int	do_markup_value(t_element *a)
{
	int		max_count;
	int		current_count;
	t_element	*first;

	max_count = 0;
	first = 0;
	while (a != first)
	{
		current_count = markup_value_count(a);
		if (current_count > max_count)
		{
			max_count = current_count;
			markup_value_set(a);
		}
		if (!first)
			first = a;
		do_roll(&a, 1);

	}
	return (1);
}
