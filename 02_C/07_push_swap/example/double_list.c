#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int x;
    struct node *next;
    struct node *prev;
} node;

int main()
{
    node *tail = malloc(sizeof(node));
    if (!tail)
        return (1);
    tail->x = 1;
    tail->prev = NULL;

    tail->next = malloc(sizeof(node));
    if (!tail->next)
        return (1);
    tail->next->x = 3;
    tail->next->prev = tail;

    tail->next->next = malloc(sizeof(node));
     if (!tail->next->next)
        return (1);
    tail->next->next->x = 7;
    tail->next->next->prev = tail->next;
    tail->next->next->next = NULL;
    // node *head = tail->next->next;

    node *curr = tail;
    while (curr != NULL)
    {
        printf("%d\n", curr->x);
        curr = curr->next;
    }

    return (0);
}