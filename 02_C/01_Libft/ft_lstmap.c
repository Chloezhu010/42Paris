#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		// apply f function to the current node's content
		new_node = ft_lstnew(f(lst->content));
		// handle malloc fail case
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		// add the new node to the new lsit
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
/*
#include <stdio.h>
#include <string.h>
void *to_uppercase(void *content)
{
	char	*str, *new_str;
	int		i;

	str = (char *)content;
	new_str = strdup(str);
	i = 0;
	if (!new_str)
		return (NULL);
	while (new_str[i])
	{
		if (new_str[i] >= 'a' && new_str[i] <= 'z')
			new_str[i] -= 32;
		i++;
	}
	return (new_str);
}

int	main()
{
	t_list *list = ft_lstnew("hello");
	ft_lstadd_back(&list, ft_lstnew("world"));
	ft_lstadd_back(&list, ft_lstnew("libft"));

	t_list *new_list = ft_lstmap(list, to_uppercase, free);

	// Print the new list
	t_list	*current = new_list;
	while (current)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
}*/
