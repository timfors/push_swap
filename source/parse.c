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
	if (!src || check_unique(src, index) == -1)
		return (-1);
	while(str)
	{
		if (!str || !ft_is_digit(*str))
			return (-1);
		str++;
	}
	return (1);
}

int	check_num(int *num, char *str)
{
	int		index;
	long long	res;
	int		len;

	if (!str || !num)
		return (-1);
	index = 0;
	len = (int)ft_strlen(str);
	while (index < len)
	{
		res += ft_pow(str[index] + '0', len - index);
		if (res > )
	}
}

t_list	*parse(char **src, int count)
{
	t_list	*res;
	int	index;

	if (!src)
		return (-1);
	index = 0;
	res = 0;
	while (index < count)
	{
		if (check_str(src, count, index) == -1)
			return (-1);

	}
	
}
