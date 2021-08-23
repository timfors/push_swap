#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>


typedef struct s_element
{
	int			index;
	int			value;
	struct s_element	*next;
	int			is_marked;
}				t_element;

t_element	*elem_create(int num);
int		elem_size(t_element *el);
void		elem_push_front(t_element **dst, t_element *new_el);
void		elem_push_back(t_element **dst, t_element *new_el);
void		elem_clear(t_element **el);
t_element	*elem_last(t_element *el);
t_element	*elem_get(t_element *el, int index);
int		*elem_to_arr(t_element *el);
t_element	*elem_copy(t_element *el);
t_element	*elem_max(t_element *el);
t_element	*elem_min(t_element *el);
int		elem_index(t_element *el, t_element *target);

typedef struct s_string
{
	char		*content;
	struct s_string	*next;
}			t_string;

int		string_add(t_string **str, const char *new_str);
void		string_clear(t_string **str);
void		string_print(t_string *str);
int		string_size(t_string *str);

t_element	*parse(char **str, int count);

typedef int	(*count_func)(t_element *);
typedef void	(*set_mark)(t_element *);

void		markup_reset(t_element *a);

t_string	*sort_index(t_element *a);

int		do_markup_index(t_element *a);
int		markup_index_count(t_element *a);
void		markup_index_set(t_element *a);
int		push_to_b_index(t_element **a, t_element **b, t_string **str);

int		do_markup_value(t_element *a);
int		markup_value_count(t_element *a);
void		markup_value_set(t_element *a);
int		push_to_b_value(t_element **a, t_element **b, t_string **str);

t_string	*sort_value(t_element *marked_elems);

int		push_to_a(t_element **a, t_element **b, t_string **str);
int		count_for_rotate(t_element *a, int target);
int		rotate(t_element **a, t_element **b, t_string **str, int index); 

int		rotate_to_min(t_element **a, t_string **str);

int		do_sa(t_element **a, t_string **str);
int		do_sb(t_element **b, t_string **str);
int		do_ss(t_element **a, t_element **b, t_string **str);
int		do_pa(t_element **a, t_element **b, t_string **str);
int		do_pb(t_element **a, t_element **b, t_string **str);
int		do_ra(t_element **a, t_string **str);
int		do_rb(t_element **b, t_string **str);
int		do_rr(t_element **a, t_element **b, t_string **str);
int		do_rra(t_element **a, t_string **str);
int		do_rrb(t_element **b, t_string **str);
int		do_rrr(t_element **a, t_element **b, t_string **str);

int		check_swap(t_element *a, int count, count_func calc_count, set_mark mark);

void		push_first(t_element **dst, t_element **src);
void		do_swap(t_element **el);
void		do_roll(t_element **el, int direction);

#endif
