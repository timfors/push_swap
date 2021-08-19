#include "../includes/push_swap.h"

static void	bubble_sort(int	**data, int size)
{
	int	i;
	int	tmp;
	int	*arr;

	i = 0;
	arr = *data;
	while (i < size - 1)
	{
		while(arr[i + 1] < arr[i] && i >= 0)
		{
			tmp = arr[i + 1];
			arr[i + 1] = arr[i];
			arr[i] = tmp;
			i--;
		}
		i++;
	}
}

static int	set_index(t_element *el)
{
	int		*arr;
	int		i;
	t_element	*tmp;

	arr = elem_to_arr(el);
	if (!arr)
		return (0);
	bubble_sort(&arr, elem_size(el));
	i = 0;
	while (i < elem_size(el))
	{
		tmp = el;
		while (tmp->value != arr[i])
			tmp = tmp->next;
		tmp->index = i;
		i++;
	}
	return (1);
}

int		markup_index_count(t_element *el)
{
	int		result;
	int		prev_index;
	t_element	*first;
	int		roll_count;

	prev_index = el->index;
	result = 1;
	first = el;
	do_roll(&el, 1);
	roll_count = 1;
	while (el != first && el->index == prev_index + 1)
	{
		prev_index++;
		result++;
		do_roll(&el, 1);
		roll_count++;
	}
	while (el != first && roll_count--)
		do_roll(&el, -1);
	return (result);
}

void		markup_index_set(t_element *el)
{
	int		prev_index;
	t_element	*first;
	int		roll_count;

	markup_reset(el);
	prev_index = el->index;
	el->is_marked = 1;
	first = el;
	do_roll(&el, 1);
	roll_count = 1;
	while (el != first && el->index == prev_index + 1)
	{
		prev_index++;
		el->is_marked = 1;
		do_roll(&el, 1);
		roll_count++;
	}
	while (el != first && roll_count--)
		do_roll(&el, -1);
}

int		do_markup_index(t_element *el)
{
	int		max_count;
	int		current_count;
	t_element	*first;

	if (!set_index(el))
		return (0);
	max_count = 0;
	first = 0;
	while (el != first)
	{
		current_count = markup_index_count(el);
		if (current_count > max_count)
		{
			max_count = current_count;
			markup_index_set(el);
		}
		if (!first)
			first = el;
		do_roll(&el, 1);
	}
	return (1);
}
