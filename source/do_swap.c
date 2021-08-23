/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:04:03 by bojamee           #+#    #+#             */
/*   Updated: 2021/08/23 14:04:44 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_swap(t_element **el)
{
	t_element	*tmp;

	if (!el || elem_size(*el) <= 1)
		return ;
	tmp = *el;
	*el = tmp->next;
	tmp->next = (*el)->next;
	(*el)->next = tmp;
}

int	do_sa(t_element **a, t_string **str)
{
	do_swap(a);
	return (string_add(str, "sa\n"));
}

int	do_sb(t_element **b, t_string **str)
{
	do_swap(b);
	return (string_add(str, "sb\n"));
}

int	do_ss(t_element **a, t_element **b, t_string **str)
{
	do_swap(a);
	do_swap(b);
	return (string_add(str, "ss\n"));
}
