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

void	delete_col(t_collumns *col)
{
	if (!col)
		return ;
	ft_lstclear(&(col->a), free);
	ft_lstclear(&(col->b), free);
	free(col);
}

int	main(int argc, char **argv)
{
	t_collumns *col = init_col();

	if (!col)
		return (0);
	col->a = parse(argv, argc);
	if (col->a)
	{
		ft_lstiter(col->a, print_elem);
	}
	else 
		ft_putstr_fd("Error\n", 1);
	delete_col(col);
}
