#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
#include <stdio.h>
#include <string.h>
void to_uppercase(void *content)
{
    char *str = (char *)content;
    while (*str) {
        if (*str >= 'a' && *str <= 'z')
            *str -= 32; // Convert to uppercase
        str++;
    }
}

void print_content(void *content)
{
    printf("Node content: %s\n", (char *)content);
}

int	main()
{
	// Create a list with 3 nodes
    t_list *node1 = ft_lstnew(strdup("node1 content"));
    t_list *node2 = ft_lstnew(strdup("node2 content"));
    t_list *node3 = ft_lstnew(strdup("node3 content"));

    node1->next = node2;
    node2->next = node3;

	// Print original list
    printf("Original list:\n");
    ft_lstiter(node1, print_content);

	// Apply to_uppercase function to each node's content
    ft_lstiter(node1, to_uppercase);

    // Print modified list
    printf("\nModified list:\n");
    ft_lstiter(node1, print_content);
}*/
