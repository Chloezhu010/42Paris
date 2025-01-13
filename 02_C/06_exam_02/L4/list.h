#ifndef LIST_H
# define LIST_H

typedef struct s_list t_list;

typedef struct	s_list
{
	int	data;
	t_list	*next;
}		t_list;

#endif
