/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:08:12 by bojamee           #+#    #+#             */
/*   Updated: 2021/08/23 15:51:39 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_string	*sort_index(t_element *a)
{
	t_element	*new_a;
	t_element	*b;
	t_string	*str;

	new_a = elem_copy(a);
	str = 0;
	b = 0;
	if (!new_a)
		return (0);
	if (!do_markup_index(new_a) || !push_to_b_index(&new_a, &b, &str)
		|| !push_to_a(&new_a, &b, &str) || !rotate_to_min(&new_a, &str))
	{
		elem_clear(&b);
		elem_clear(&new_a);
		return (0);
	}
	elem_clear(&b);
	elem_clear(&new_a);
	return (str);
}

t_string	*sort_value(t_element *a)
{
	t_element	*new_a;
	t_element	*b;
	t_string	*str;

	new_a = elem_copy(a);
	str = 0;
	b = 0;
	if (!new_a)
		return (0);
	if (!do_markup_value(new_a) || !push_to_b_value(&new_a, &b, &str)
		|| !push_to_a(&new_a, &b, &str) || !rotate_to_min(&new_a, &str))
	{
		elem_clear(&b);
		elem_clear(&new_a);
		return (0);
	}
	elem_clear(&b);
	elem_clear(&new_a);
	return (str);
}

static	void	proceed_strs(t_string **str_index, t_string **str_value)
{
	if (!str_index && !str_value)
		ft_putstr_fd("Error\n", 1);
	else if (!*str_index && *str_value)
		string_print(*str_value);
	else if (*str_index && !*str_value)
		string_print(*str_index);
	else if (string_size(*str_index) < string_size(*str_value))
		string_print(*str_index);
	else
		string_print(*str_value);
	if (*str_index)
		string_clear(str_index);
	if (*str_value)
		string_clear(str_value);
}

int	main(int argc, char **argv)
{
	t_element	*a;
	t_string	*str_index;
	t_string	*str_value;

	if (argc == 1)
		return (1);
	a = parse(argv, argc);
	if (!a)
	{
		ft_putstr_fd("Error\n", 1);
		return (-1);
	}
	str_index = sort_index(a);
	str_value = sort_value(a);
	elem_clear(&a);
	proceed_strs(&str_index, &str_value);
}
