#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	// input valdiation
	if (!lst || !new)
		return ;
	// handle list is null case
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	// loop the list until end, then add new
	current = *lst;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	new->next = NULL;
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

	t_list *new = ft_lstnew("new");
	ft_lstadd_back(&node1, new);

	t_list *current = node1;
	while (current)
	{
		printf("%s ->", (char *)current->content);
		current = current->next;
	}
}*/