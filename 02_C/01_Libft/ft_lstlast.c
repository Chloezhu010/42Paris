#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/*
#include <stdio.h>
int	main()
{
	t_list *node1 = ft_lstnew("node1");
	t_list *node2 = ft_lstnew("node2");
	t_list *node3 = ft_lstnew("node3");
	node1->next = node2;
	node2->next = node3;

	t_list *last_node = ft_lstlast(node1);
	printf("last node's ptr address: %p\n", (char *)last_node);
	printf("last node's content: %s\n", (char *)last_node->content);
	printf("last node's next: %s\n", (char *)last_node->next);
}*/
