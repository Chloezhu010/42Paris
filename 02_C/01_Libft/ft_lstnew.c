#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

#include <stdio.h>

int	main()
{
	int	*num = malloc(sizeof(int));
	
	*num = 42;
	t_list *int_node = ft_lstnew(num);
	if (int_node)
	{
		printf("intger node created\n");
		printf("content: %d\n", *(int*)int_node -> content);
		printf("next: %p\n", (void*)int_node -> next);
	} else
	{
		printf("failed to create integer node\n");
	}
}
