/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:05:09 by bojamee           #+#    #+#             */
/*   Updated: 2021/08/23 14:05:44 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	elem_size(t_element *el)
{
	int	res;

	res = 0;
	while (el)
	{
		res++;
		el = el->next;
	}
	return (res);
}

t_element	*elem_last(t_element *el)
{
	if (!el)
		return (0);
	while (el->next)
		el = el->next;
	return (el);
}

t_element	*elem_get(t_element *el, int index)
{
	int	i;

	i = 0;
	while (el && i != index)
	{
		i++;
		el = el->next;
	}
	if (index != i)
		return (0);
	return (el);
}

int	*elem_to_arr(t_element *el)
{
	int	*res;
	int	i;

	res = malloc(sizeof(int) * elem_size(el));
	if (!res)
		return (0);
	i = 0;
	while (el)
	{
		res[i] = el->value;
		el = el->next;
		i++;
	}
	return (res);
}

t_element	*elem_copy(t_element *src)
{
	t_element	*res;
	t_element	*new;

	res = 0;
	while (src)
	{
		new = elem_create(src->value);
		if (!new)
		{
			elem_clear(&res);
			return (0);
		}
		new->index = src->index;
		new->is_marked = src->is_marked;
		elem_push_back(&res, new);
		src = src->next;
	}
	return (res);
}
