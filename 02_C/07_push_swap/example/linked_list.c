#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

int main(int ac, char **av)
{
    node    *list = NULL;

    for (int i = 1; i < ac; i++)
    {
        int number = atoi(av[i]);
        
        node *n = malloc(sizeof(node));
        if (!n)
        {
            free(n);
            return (1);
        }
        n->number = number;
        n->next = NULL;

        n->next = list;
        list = n;
    }

    // print the list
    node    *ptr = list;
    while (ptr)
    {
        printf("%d\n", ptr->number);
        ptr = ptr->next;
    }
}
