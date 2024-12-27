#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;	

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
/*
#include <stdio.h>
int	main()
{
	// create a linked list of node 123
	// t_list *node1 = NULL;
	t_list *node1 = ft_lstnew("node1");
	t_list *node2 = ft_lstnew("node2");
	t_list *node3 = ft_lstnew("node3");

	node1->next = node2;
	node2->next = node3;

	// print the list size
	printf("list size: %d\n", ft_lstsize(node1));
}*/