#include "../inlcudes/push_swap.h"

void push_first(t_list **dst, t_list **src)
{
	t_list *src_first;

	src_first = *src;
	*src = src_first->next;
	ft_lst_add_front(dst, src_first);
}

int	do_pa(t_collumns *collumns)
{
	push_first(collumns->b, collumns->a);
	ft_putstr_fd("pa'\n", 1);
}

int	do_pb(t_collumns *collumns)
{
	push_first(collumns->a, collumns->b);
	ft_putstr_fd("pb'\n", 1);
}
