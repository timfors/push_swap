#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_collumns
{
	t_list	**a;
	t_list	**b;
}			t_collumns;

typedef struct s_flags
{
	int	is_rotate_a;
	int	is_rotate_b;
	int	is_swap_a;
	int	is_swap_b;
	int	is_push_a;
	int	is_push_b;
}		t_flags;

typedef int	(*t_action)(t_collumns *collumns);

int			*get_nums(char **num);
int			sort(t_collumns *collumns);
t_flags		*init_flags(t_collumns *collumns);
t_action	get_action(t_flags flags);

void		do_sa(t_collumns *collumns);
void		do_sb(t_collumns *collumns);
void		do_ss(t_collumns *collumns);
void		do_pa(t_collumns *collumns);
void		do_pb(t_collumns *collumns);
void		do_ra(t_collumns *collumns);
void		do_rb(t_collumns *collumns);
void		do_rr(t_collumns *collumns);
void		do_rra(t_collumns *collumns);
void		do_rrb(t_collumns *collumns);
void		do_rrr(t_collumns *collumns);

void		swap_first(t_list **list);
void		rotate_up(t_list **list);
void		rotate_down(t_list **list);
void		push_first(t_list **dst, t_list **src);
#endif
