// #define _CRTDBG_MAP_ALLOC
// #include <crtdbg.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct node 
{
    int x;
    struct node *next;
} node;

// add element into the list at the end
void    insert_end(node **root, int value)
{
    node    *new_node = malloc(sizeof(node));
    node    *curr = *root;

    if (!new_node)
        exit(1);
    new_node->next = NULL;
    new_node->x = value;

    if (*root == NULL)
    {
        *root = new_node;
        return;
    }

    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new_node;
}

// add element into the beginning
void    insert_begin(node **root, int value)
{
    node *new_node = malloc(sizeof(node));
    if (!new_node)
        exit(1);
    new_node->x = value;
    new_node->next = *root;
    *root = new_node;
}

// add element inbetween
void    insert_after(node *target_node, int value)
{
    node *new_node = malloc(sizeof(node));
    if (!new_node)
        exit(1);
    new_node->x = value;
    new_node->next = target_node->next;
    target_node->next = new_node;
}

// deallocate the list， from left to right
void    deallocate(node **root)
{
    node *curr = *root;
    node *aux;

    while (curr != NULL)
    {
        aux = curr;
        curr = curr->next;
        free(aux);
    }
    *root = NULL;
}

// sort the list
void    insert_sorted(node **root, int value)
{
    // handle edge cases
    if (*root == NULL || (*root)->x >= value)
    {
        insert_begin(root, value);
        return;
    }

    node *curr = *root;
    while (curr->next != NULL && curr->next->x < value)
    {
        curr = curr->next;
    }
    insert_after(curr, value);
}

// remove an element from a linked list
void    remove_element(node **root, int value)
{
    if (*root == NULL)
        return;

    // handle the edge case at the root
    if ((*root)->x == value)
    {
        node *to_remove = *root;
        *root = (*root)->next;
        free(to_remove);
        return;
    }

    // handle the normal case
    node *curr = *root;
    while (curr->next != NULL)
    {
        if (curr->next->x == value)
        {
            node *to_remove = curr->next;
            curr->next = curr->next->next;
            free(to_remove);
            return;
        }
        curr = curr->next;
    }
}

// reverse a list
void    reverse(node **root)
{
    node *prev = NULL;
    node *curr = *root;
    
    while (curr != NULL)
    {
        node *next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    *root = prev;
}

// find loops in a list
int     has_loop(node *root)
{
    node *slow = root;
    node *fast = root;

    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return (1);
    }
    return (0);
}

// count number of elements
int     count(node *root)
{
    node *curr = root;
    int count = 0;

    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    return (count);
}

// count recursively
int     count_list(node *node)
{
    if (node == NULL)
        return (0);
    
   return (1 + count_list(node->next));
}

int main(int ac, char **av)
{
    // node *root = malloc(sizeof(node));
    node *root = NULL;
    
    (void)ac;
    (void)av;

    insert_sorted(&root, 5);
    insert_sorted(&root, 2);
    insert_sorted(&root, 78);
    insert_sorted(&root, 24);

    reverse(&root);
    // remove_element(&root, 78);

    if (has_loop(root) == 1)
    {
        printf("the list has a loop\n");
        return (1);
    }

    printf("# of elements %d\n", count_list(root));
    
    node *curr = root;
    while (curr != NULL)
    {
        printf("%d\n", curr->x);
        curr = curr->next;
    }

    deallocate(&root);
    //_CrtDumpMemoryLeaks();
    return (0);

    // insert_begin(&root, 30);
    // insert_begin(&root, -42);

    // if (!root)
    //     exit(2);

    // intro of the linked list
    // root->x = 15;
    // root->next = NULL;

    // add element into the list
    // insert_end(&root, -2);
    // insert_end(&root, 42);
    // insert_after(root->next->next, 7);
}