#include "../includes/push_swap.h"

void	do_rra(t_collumns *collumns)
{
	do_roll(&(collumns->a), -1);
	ft_putstr_fd("rra\n", 1);
}

void	do_rrb(t_collumns *collumns)
{
	do_roll(&(collumns->b), -1);
	ft_putstr_fd("rrb\n", 1);
}

void	do_rrr(t_collumns *collumns)
{
	do_roll(&(collumns->a), -1);
	do_roll(&(collumns->b), -1);
	ft_putstr_fd("rrr\n", 1);
}
