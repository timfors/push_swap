/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_get_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:07:00 by bojamee           #+#    #+#             */
/*   Updated: 2021/08/23 14:07:15 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_element	*elem_max(t_element *el)
{
	t_element	*res;

	res = 0;
	while (el)
	{
		if (!res || el->value > res->value)
			res = el;
		el = el->next;
	}
	return (res);
}

t_element	*elem_min(t_element *el)
{
	t_element	*res;

	res = 0;
	while (el)
	{
		if (!res || el->value < res->value)
			res = el;
		el = el->next;
	}
	return (res);
}

int	elem_index(t_element *el, t_element *target)
{
	int	res;

	res = 0;
	while (el && el != target)
	{
		res++;
		el = el->next;
	}
	if (!el)
		return (-1);
	return (res);
}
