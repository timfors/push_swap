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
	if (a && do_markup_index(a))
	{
		push_to_b_index(&a, &b, &str);
		print_elems(a, b);
		push_to_a(&a, &b, &str);
		int roll = count_for_rotate(a, elem_min(a)->value);
		int size = elem_size(a);
		if (roll > (size / 2))
			while (roll++ < size)
				do_rra(&a, &str);
		else if (roll)
			while (roll--)
				if (!do_ra(&a, &str))
					return (0);
		printf("TOTAL: %d", string_size(str));
	}
	else 
		ft_putstr_fd("Error\n", 1);
	elem_clear(&a);
}
