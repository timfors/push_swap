/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:13:41 by bojamee           #+#    #+#             */
/*   Updated: 2021/08/23 14:39:00 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_unique(t_element *el, int num)
{
	while (el)
	{
		if (el->value == num)
			return (0);
		el = el->next;
	}
	return (1);
}

static int	clear_splitted(char **str)
{
	int	index;

	index = 0;
	while (str[index])
		free(str[index++]);
	free(str);
	return (0);
}

static int	parse_str(char *str, t_element **el)
{
	int			index;
	int			num;
	t_element	*new_el;
	char		**splitted;

	if (!str)
		return (0);
	index = 0;
	splitted = ft_split(str, ' ');
	if (!splitted)
		return (0);
	while (splitted[index])
	{
		new_el = ft_calloc(sizeof(t_element), 1);
		if (!new_el || ft_atoi_save(splitted[index], &num) == -1
			|| !check_unique(*el, num))
			return (clear_splitted(splitted));
		new_el->value = num;
		index++;
		elem_push_back(el, new_el);
	}
	clear_splitted(splitted);
	return (1);
}

t_element	*parse(char **src, int count)
{
	t_element	*res;
	int			index;

	if (!src)
		return (0);
	index = 1;
	res = 0;
	while (index < count)
	{
		if (!parse_str(src[index], &res))
		{
			elem_clear(&res);
			return (0);
		}
		index++;
	}
	return (res);
}
