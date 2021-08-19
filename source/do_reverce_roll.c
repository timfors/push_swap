#include "../includes/push_swap.h"

int	do_rra(t_element **a, t_string **str)
{
	do_roll(a, -1);
	return (string_add(str, "rra\n"));
}

int	do_rrb(t_element **b, t_string **str)
{
	do_roll(b, -1);
	return (string_add(str, "rrb\n"));
}

int	do_rrr(t_element **a, t_element **b, t_string **str)
{
	do_roll(a, -1);
	do_roll(b, -1);
	return (string_add(str, "rrr\n"));
}
