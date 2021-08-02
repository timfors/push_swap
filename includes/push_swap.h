#ifndef PUSH_SWAP
# define PUSH_SWAP

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_collums
{
	t_list	**a;
	t_list	**b;
}			t_collumns

int		*get_nums(char **num);
int		sort(t_collumns *collumns);

int		do_sa(t_collumns *collumns);
int		do_sb(t_collumns *collumns);
int		do_ss(t_collumns *collumns);
int		do_pa(t_collumns *collumns);
int		do_pb(t_collumns *collumns);
int		do_ra(t_collumns *collumns);
int		do_rb(t_collumns *collumns);
int		do_rr(t_collumns *collumns);
int		do_rra(t_collumns *collumns);
int		do_rrb(t_collumns *collumns);
int		do_rrr(t_collumns *collumns);

int		swap_first(t_list **list);
int		rotate_up(t_list **list);
int		rotate_down(t_list **list);
int		push_first(t_list **dst, t_list **src);
#endif
