#include "ft_list.h"
#include <stddef.h>

int	ft_list_size(t_list *begin_list)
{
	int	count;
	t_list	*current;

	count = 0;
	current = begin_list;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main()
{
	// create a linked list with 3 nodes
	t_list	*n1 = malloc(sizeof(t_list));
	t_list	*n2 = malloc(sizeof(t_list));
	t_list	*n3 = malloc(sizeof(t_list));

	n1->data = "n1";
	n1->next = n2;

	n2->data = "n2";
	n2->next = n3;

	n3->data = "n3";
	n3->next = NULL;

	int	size = ft_list_size(n1);
	printf("list size: %d\n", size);
}*/
