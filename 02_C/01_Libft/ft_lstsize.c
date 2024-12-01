#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

#include <stdio.h>
#include <stdlib.h>
int	main()
{
	t_list	*list = NULL;
	int	*first = malloc(sizeof(int));
	*first = 10;
	list = ft_lstnew(first);
	printf("list with one node size: %d\n", ft_lstsize(list));

	int	*second = malloc(sizeof(int));
	*second = 20;
	t_list	*second_node = ft_lstnew(second);
	list->next = second_node;
	printf("list with two nodes size: %d\n", ft_lstsize(list));
}
