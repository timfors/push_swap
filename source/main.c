#include "../includes/push_swap.h"
#include <stdio.h>

void	print_elems(t_element *a, t_element *b)
{
	while (a || b)
	{
		printf("|\t");
		if (a)
		{
			printf("%d", a->value);
			a = a->next;
		}
		printf("\t|\t");
		if (b)
		{
			printf("%d", b->value);
			b = b->next;
		}
		printf("\t|\n");
	}
	printf("-\t-\t-\t-\t-\n");
}


void	print_elems_full(t_element *a)
{
	while (a)
	{
		printf("__\t\t\t__\n\n");
		printf("VALUE:\t\t%d\n", a->value);
		printf("INDEX:\t\t%d\n", a->index);
		printf("IS_MARKED:\t%d\n", a->is_marked);
		a = a->next;
	}
	printf("--------------------\n---------------------\n");
}

int	main(int argc, char **argv)
{
	t_element	*a;
	t_element	*b;
	t_string	*str;

	a = parse(argv, argc);
	b = 0;
	str = 0;
	if (a && do_markup_value(a))
	{
		print_elems_full(a);
		push_to_b_value(&a, &b, &str);
		print_elems(a, b);
		string_print(str);
	}
	else 
		ft_putstr_fd("Error\n", 1);
	elem_clear(&a);
}
