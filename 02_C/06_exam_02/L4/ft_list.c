#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	// input validation
	if (!begin_list || !f)
		return;
	// apply function f to each item in the list
	while (begin_list)
	{
		(*f)(begin_list ->data);
		begin_list = begin_list -> next;
	}
}


