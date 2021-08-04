#include "../includes/push_swap.h"

void	add_num(t_list *lst, int num)
{
	t_list *new = ft_lstnew(&num);
	ft_lstadd_first(lst, new);
}

void	print_elem(int *content)
{
	char *str = ft_itoa(*content);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
}
int	main()
{
	t_collumns *col = ft_calloc(sizeof(col), 1);

	add_num(col->a, 1);
	add_num(col->b, 2);
	ft_lstiter(col->a, print_elem);
}
