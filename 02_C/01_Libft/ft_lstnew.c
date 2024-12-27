#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/*
#include <stdio.h>
int	main()
{
	char	*string = "hello, linked list";
	t_list	*node1 = ft_lstnew(string);

	// check the content and next ptr of the node
	if (node1)
	{
		printf("node 1 content: %s\n", (char *)node1->content);
		printf("node 1 next: %s (should be null)\n", (char *)node1->next);
	}
	else
		printf("node creation failed\n");
}*/
