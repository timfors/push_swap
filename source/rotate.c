#include "../includes/push_swap.h"

int	rotate_to_min(t_element **a, t_string **str)
{
	int	roll;
	int	size;

	roll = count_for_rotate(*a, elem_min(*a)->value);
	size = elem_size(*a);
	if (roll > size / 2)
	{
		while (roll++ < size)
			if (!do_rra(a, str))
				return (0);
	}
	else
		while (roll--)
			if (!do_ra(a, str))
				return (0);
	return (1);
}
