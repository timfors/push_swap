#include "../includes/push_swap.h"

void	add_num(t_list **lst, int num)
{
	int *content = malloc(sizeof(int));
	if (!content)
		return;
	*content = num;
	t_list *new = ft_lstnew(content);
	ft_lstadd_back(lst, new);
}

int	check_unique(char **src, int count, int index)
{
	char	*str;

	if (index >= count)
		return (-1);
	str = *(src + index);
	while (++index < count)
		if (!ft_strcmp(str, src[index]))
			return (-1);
	return (1);
}

int	check_str(char **src, int count, int index)
{
	if (!src || check_unique(src, count, index) == -1)
		return (-1);
	return (1);
}

t_list	*parse(char **src, int count)
{
	t_list	*res;
	int	index;
	int	num;

	if (!src)
		return (0);
	index = 1;
	res = 0;
	while (index < count)
	{
		if (check_str(src, count, index) == -1
				|| ft_atoi_save(src[index], &num) == -1)
			return (0);
		add_num(&res, num);
		index++;

	}
	return (res);
	
}
