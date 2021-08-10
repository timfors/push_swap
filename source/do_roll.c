#include "../includes/push_swap.h"

void	do_roll(t_list **lst, int direction)
{
	t_list	*first;
	t_list	*tmp;
	int	list_size;

	if (!lst || ft_lstsize(*lst) <= 1 || !direction)
		return ;
	list_size = ft_lstsize(*lst);
	if (list_size == 2)
		do_swap(lst);
	else if (direction > 0)
	{
		first = *lst;
		*lst = first->next;
		first->next = 0;
		ft_lstlast(*lst)->next = first;
	}
	else 
	{
		tmp = ft_lstget(*lst, list_size - 2);
		tmp->next->next = *lst;
		*lst = tmp->next;
		tmp->next = 0;
	}
}

void	do_ra(t_collumns *collumns)
{
	do_roll(&(collumns->a), 1);
	ft_putstr_fd("ra\n", 1);
}

void	do_rb(t_collumns *collumns)
{
	do_roll(&(collumns->b), 1);
	ft_putstr_fd("rb\n", 1);
}

void	do_rr(t_collumns *collumns)
{
	do_roll(&(collumns->a), 1);
	do_roll(&(collumns->b), 1);
	ft_putstr_fd("rr\n", 1);
}
