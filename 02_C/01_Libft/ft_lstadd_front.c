#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	// input validation
	if (!lst || !new)
		return ;
	new->next = *lst; // point the new's next to the current head
	*lst = new; // update the head to be new
}
/*
#include <stdio.h>
int	main()
{
	// create initial nodes
	t_list	*head = ft_lstnew("hello");
	t_list	*new = ft_lstnew("world");

	// add new node to the front
	ft_lstadd_front(&head, new);

	// print list
	t_list	*current = head;
	while (current)
	{
		printf("%s ->", (char *)current->content);
		current = current->next;
	}
	printf("NULL\n");
}*/