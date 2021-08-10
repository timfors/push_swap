#include "../includes/push_swap.h"

void	print_elem(void *content)
{
	int	*data = content;
	char	*str = ft_itoa(*data);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
}

t_collumns	*init_col()
{
	t_collumns	*res;

	res = ft_calloc(sizeof(t_collumns), 1);
	if (!res)
		return (0);
	 res->a = 0;
	 res->b = 0;
	 return (res);
}

int	main()
{
	t_collumns *col = init_col();

	if (!col)
		return (0);
	add_num(&(col->a), 123);
	add_num(&(col->a), 2);
	add_num(&(col->a), 1);
	do_ra(col);
	do_rra(col);
	ft_lstiter(col->a, print_elem);
}
