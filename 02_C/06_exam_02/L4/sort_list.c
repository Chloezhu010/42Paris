#include "list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list	*start;
	int	swap;

	start = lst; // declare a start to loop through the list
	// loop through the lsit
	while (lst && lst->next)
	{
		// if the cmp return 0, swap the two nodes
		if ((*cmp)(lst->data, lst->next->data) == 0)
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			// reset lst to the start to recheck from the beginning
			lst = start;
		}
		// if no swap is needed, move to the next node
		else
			lst = lst->next;
	}
	// return the start of the sorted list
	return (start);
}

// below for testing
#include <stdlib.h>
#include <stdio.h>

int ascending(int a, int b)
{
	return (a <= b);
}

t_list	*create_node(int data)
{
	t_list	*node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

void	print_list(t_list *list)
{
	while (list)
	{
		printf("%d -> ", list->data);
		list = list->next;
	}
	printf("\n");
}

void	free_list(t_list *list)
{
	t_list	*tmp;
	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

int	main()
{
	// create linked list
	t_list	*head = create_node(3);
	head->next = create_node(2);
	head->next->next = create_node(4);
	head->next->next->next = create_node(1);

	printf("original list: \n");
	print_list(head);

	head = sort_list(head, ascending);
	printf("sorted list: \n");
	print_list(head);

	
}
