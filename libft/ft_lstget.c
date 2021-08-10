#include "libft.h"

t_list	*ft_lstget(t_list *lst, int index)
{
	int	i;
	t_list	*result;

	if (ft_lstsize(lst) <= index)
		return (0);
	i = 0;
	result = lst;
	while (i++ < index)
		result = result->next;
	return (result);
}
