#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*current;	

	// check if the input is null or if pointer is null
	if (!*begin_list || !begin_list)
		return;
	// cmp data in the list with data_ref
	current = *begin_list;
	if (cmp(current->data, data_ref) == 0)
	{
		// if the item == data_ref, then remove the current node
		// recursively call the function to check the new head
		*begin_list = current->next;
		free(current);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	else // if not equal
	{
		// move to the next node and recursively check the rest of the list
		current = *begin_list;
		ft_list_remove_if(&current->next, data_ref, cmp);
	}
}


