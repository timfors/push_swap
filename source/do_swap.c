#include "../includes/push_swap.h"

static void	do_swap(t_list **lst)
{
	t_list	*tmp;
	if (!lst || ft_lstsize(*lst) <= 1)
		return ;
	tmp = *lst;
	*lst = tmp->next;
	tmp->next = (*lst)->next;
	(*lst)->next = tmp;
}

void		do_sa(t_collumns *collumns)
{
	do_swap(&(collumns->a));
	ft_putstr_fd("sa\n", 1);
}

void		do_sb(t_collumns *collumns)
{
	do_swap(&(collumns->b));
	ft_putstr_fd("sb\n", 1);
}

void		do_ss(t_collumns *collumns)
{
	do_swap(&(collumns->a));
	do_swap(&(collumns->b));
	ft_putstr_fd("ss\n", 1);
}
