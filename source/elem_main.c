/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:07:34 by bojamee           #+#    #+#             */
/*   Updated: 2021/08/23 14:07:46 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_element	*elem_create(int num)
{
	t_element	*res;

	res = ft_calloc(sizeof(t_element), 1);
	if (!res)
		return (0);
	res->value = num;
	return (res);
}

void	elem_push_front(t_element **dst, t_element *new_el)
{
	if (!dst || !new_el)
		return ;
	new_el->next = *dst;
	*dst = new_el;
}

void	elem_push_back(t_element **dst, t_element *new_el)
{
	if (!dst || !new_el)
		return ;
	if (*dst)
		elem_last(*dst)->next = new_el;
	else
		*dst = new_el;
}

void	elem_clear(t_element **el)
{
	t_element	*prev;
	t_element	*current;

	if (!el || !*el)
		return ;
	prev = *el;
	current = prev->next;
	while (prev)
	{
		free(prev);
		prev = current;
		if (current)
			current = current->next;
	}
	*el = 0;
}
