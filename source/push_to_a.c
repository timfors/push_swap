/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:19:28 by bojamee           #+#    #+#             */
/*   Updated: 2021/08/23 14:30:14 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	count_for_rotate(t_element *a, int target)
{
	int	prev;
	int	max_v;
	int	min_v;
	int	res;

	max_v = elem_max(a)->value;
	min_v = elem_min(a)->value;
	res = 0;
	if (target > max_v)
		target = max_v;
	else if (target < min_v)
		target = min_v;
	prev = elem_last(a)->value;
	while (a)
	{
		if ((prev < target && a->value > target)
			|| (target == max_v && prev == max_v)
			|| (target == min_v && a->value == min_v))
			return (res);
		prev = a->value;
		a = a->next;
		res++;
	}
	return (-1);
}

static int	get_total_steps(int a, int b)
{
	int	res;

	res = 0;
	if (a > 0 && b > 0)
	{
		if (a >= b)
			res = a;
		else
			res = b;
	}
	else if (a < 0 && b < 0)
	{
		if (a <= b)
			res = (-a);
		else
			res = (-b);
	}
	else if (a <= 0 && b >= 0)
		res = b - a;
	else if (a >= 0 && b <= 0)
		res = a - b;
	if (res < 0)
		res = (-res);
	return (res);
}

static void	set_steps(int *a_steps, int *b_steps, int size_a, int size_b)
{
	int	reverse_a;
	int	reverse_b;

	reverse_a = size_a - *a_steps;
	reverse_b = size_b - *b_steps;
	if ((reverse_a < *a_steps && reverse_b < *b_steps)
		|| (reverse_a < *a_steps && reverse_b >= *b_steps
			&& *b_steps >= reverse_b - reverse_a
			&& reverse_b - reverse_a <= *b_steps - *a_steps)
		|| (reverse_a >= *a_steps
			&& reverse_b < *b_steps && *a_steps >= reverse_a - reverse_b
			&& reverse_a - reverse_b <= *a_steps - *b_steps))
	{
		*a_steps = -reverse_a;
		*b_steps = -reverse_b;
	}
	else if (reverse_a < *a_steps && reverse_a < *a_steps - *b_steps)
		*a_steps = -reverse_a;
	else if (reverse_b < *b_steps && reverse_b < *b_steps - *a_steps)
		*b_steps = -reverse_b;
}

int	rotate(t_element **a, t_element **b, t_string **str, int index)
{
	int	b_rotate;
	int	a_rotate;

	b_rotate = index;
	a_rotate = count_for_rotate(*a, elem_get(*b, index)->value);
	set_steps(&a_rotate, &b_rotate, elem_size(*a), elem_size(*b));
	while (a_rotate > 0 && b_rotate > 0 && a_rotate-- && b_rotate--)
		if (!do_rr(a, b, str))
			return (0);
	while (a_rotate < 0 && b_rotate < 0 && a_rotate++ && b_rotate++)
		if (!do_rrr(a, b, str))
			return (0);
	while (a_rotate > 0 && a_rotate--)
		if (!do_ra(a, str))
			return (0);
	while (a_rotate < 0 && a_rotate++)
		if (!do_rra(a, str))
			return (0);
	while (b_rotate > 0 && b_rotate--)
		if (!do_rb(b, str))
			return (0);
	while (b_rotate < 0 && b_rotate++)
		if (!do_rrb(b, str))
			return (0);
	return (1);
}

int	push_to_a(t_element **a, t_element **b, t_string **str)
{
	int	steps_a;
	int	steps_b;
	int	min_steps;
	int	min_index;
	int	index_b;

	while (elem_size(*b))
	{
		min_steps = MAX_INT;
		index_b = 0;
		while (index_b < elem_size(*b))
		{
			steps_b = index_b;
			steps_a = count_for_rotate(*a, elem_get(*b, index_b++)->value);
			set_steps(&steps_a, &steps_b, elem_size(*a), elem_size(*b));
			if (get_total_steps(steps_a, steps_b) < min_steps)
			{
				min_steps = get_total_steps(steps_a, steps_b);
				min_index = index_b - 1;
			}
		}
		if (!rotate(a, b, str, min_index) || !do_pa(a, b, str))
			return (0);
	}
	return (1);
}
