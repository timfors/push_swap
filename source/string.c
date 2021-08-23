/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:33:39 by bojamee           #+#    #+#             */
/*   Updated: 2021/08/23 14:35:06 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_string	*string_create(const char *new_str)
{
	char		*chars;
	t_string	*new_elem;

	if (!new_str)
		return (0);
	chars = ft_strdup(new_str);
	if (!chars)
		return (0);
	new_elem = ft_calloc(sizeof(t_string), 1);
	if (!new_elem)
	{
		free(chars);
		return (0);
	}
	new_elem->content = chars;
	return (new_elem);
}

int	string_size(t_string *str)
{
	int	res;

	res = 0;
	while (str)
	{
		res++;
		str = str->next;
	}
	return (res);
}

int	string_add(t_string **str, const char *new_str)
{
	t_string	*new;
	t_string	*tmp;

	new = string_create(new_str);
	if (!new)
	{
		string_clear(str);
		return (0);
	}
	tmp = *str;
	if (!tmp)
		*str = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (1);
}

void	string_clear(t_string **str)
{
	t_string	*prev;
	t_string	*current;

	if (!str || !*str)
		return ;
	prev = *str;
	current = prev->next;
	while (prev)
	{
		if (prev->content)
			free(prev->content);
		free(prev);
		prev = current;
		if (current)
			current = current->next;
	}
}

void	string_print(t_string *str)
{
	t_string	*tmp;

	if (!str)
		return ;
	tmp = str;
	while (tmp)
	{
		ft_putstr_fd(tmp->content, 1);
		tmp = tmp->next;
	}
}
