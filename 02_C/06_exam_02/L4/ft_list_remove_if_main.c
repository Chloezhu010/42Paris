#include "ft_list.h"  // Include the definition of the t_list structure
#include <stdlib.h>   // For malloc and free
#include <stdio.h>    // For printf

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

// Comparison function for integers
int cmp(void *a, void *b)
{
    return (*(int*)a - *(int*)b);  // Return 0 if equal
}

// Function to print the list
void print_list(t_list *list)
{
    while (list != NULL)
    {
        printf("%d -> ", *(int*)list->data);  // Print the data
        list = list->next;
    }
    printf("NULL\n");
}

// Function to create a new node
t_list *create_node(int data)
{
    t_list *node = malloc(sizeof(t_list));
    if (!node)
        return NULL;
    node->data = malloc(sizeof(int));
    *(int*)node->data = data;
    node->next = NULL;
    return node;
}

// Function to free the entire list
void free_list(t_list *list)
{
    t_list *tmp;
    while (list != NULL)
    {
        tmp = list;
        list = list->next;
        free(tmp->data);  // Free the data
        free(tmp);        // Free the node
    }
}

int main(void)
{
    // Create a linked list: 1 -> 2 -> 3 -> 2 -> 4
    t_list *head = create_node(1);
    head->next = create_node(2);
    head->next->next = create_node(3);
    head->next->next->next = create_node(2);
    head->next->next->next->next = create_node(4);

    // Print the original list
    printf("Original list:\n");
    print_list(head);

    // Remove nodes with data == 2
    int data_ref = 2;
    ft_list_remove_if(&head, &data_ref, cmp);

    // Print the modified list
    printf("\nList after removing nodes with data == %d:\n", data_ref);
    print_list(head);

    // Free the remaining nodes
    free_list(head);

    return 0;
}
