#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	// input validation
	if (!lst || !*lst || !del)
		return ;
	// loop through *lst and call del function to delete current node and the subsequent nodes' content
	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		del(temp->content);
		free(temp);
	}
	// ptr to the list set to NULL
	*lst = NULL;
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
	char *str2 = malloc(20 * sizeof(char));
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

	ft_lstclear(&node1, del_content);
	printf("afterwards:\n");
	print_list(node1);	
}*/