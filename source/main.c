#include "../includes/push_swap.h"
#include <stdio.h>

void	add_num(t_list **lst, int num)
{
	int *content = malloc(sizeof(int));
	if (!content)
		return;
	*content = num;
	t_list *new = ft_lstnew(content);
	ft_lstadd_front(lst, new);
}

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
	add_num(&(col->b), 1);
	do_pb(col);
	ft_lstiter(col->a, print_elem);
}
