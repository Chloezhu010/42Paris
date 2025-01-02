#include "libft.h"

void	ft_lstdelone(t_list *lst, void(*del)(void *))
{
	// input validation
	if (!lst || !del)
		return ;
	// call the delete function on the node's content
	del(lst->content);
	// free the node itself
	free(lst);
}
/*
#include <stdio.h>
void del_content(void *content)
{
	free(content);
}

void print_list(t_list *lst)
{
	while (lst != NULL)
	{
		printf("node content: %s\n", (char *)lst->content);
		lst = lst->next;
	}
}

int	main()
{
	char *str1 = malloc(20 * sizeof(char));
	snprintf(str1, 20, "node1 content");
	char *str2 = malloc(d20 * sizeof(char));
	snprintf(str2, 20, "node2 content");
	char *str3 = malloc(20 * sizeof(char));
	snprintf(str3, 20, "node3 content");

	t_list *node1 = ft_lstnew(str1);
	t_list *node2 = ft_lstnew(str2);
	t_list *node3 = ft_lstnew(str3);

	node1->next = node2;
	node2->next = node3;

	printf("original list:\n");
	print_list(node1);

	ft_lstdelone(node2, del_content);
	printf("afterwards:\n");
	print_list(node1);
}*/
