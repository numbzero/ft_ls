#include "ft_ls.h"

void	sorting(t_file **list_ref, int j, int i)
{
	merge_sort(&(*list_ref));
	if (i)
		time_merge_sort(&(*list_ref));
	if (j)
		reverse_list(&(*list_ref));
}

void	time_merge_sort(t_file **list_ref)
{
	t_file *list;
	t_file *a;
	t_file *b;

	list = *list_ref;
	if ((list == NULL) || (list->next == NULL))
		return ;
	front_back_split(list, &a, &b);
	time_merge_sort(&a);
	time_merge_sort(&b);
	*list_ref = time_sorted_merge(a, b);
}

t_file	*time_sorted_merge(t_file *a, t_file *b)
{
	t_file *result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (a->time.t_ctime > b->time.t_ctime)
	{
		result = a;
		result->next = time_sorted_merge(a->next, b);
	}
	else
	{
		result = b;
		result->next = time_sorted_merge(a, b->next);
	}
	return (result);
}

void	reverse_list(t_file **list_ref)
{
	t_file	*current;
	t_file	*prev; 
	t_file	*next;
 
 	current  = *list_ref;
 	prev = NULL;
 	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*list_ref = prev;
}

void	merge_sort(t_file **list_ref)
{
	t_file *list;
	t_file *a;
	t_file *b;

	list = *list_ref;
	if ((list == NULL) || (list->next == NULL))
		return ;
	front_back_split(list, &a, &b);
	merge_sort(&a);
	merge_sort(&b);
	*list_ref = sorted_merge(a, b);
}

t_file	*sorted_merge(t_file *a, t_file *b)
{
	t_file *result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (strcmp(a->name, b->name) < 0)
	{
		result = a;
		result->next = sorted_merge(a->next, b);
	}
	else
	{
		result = b;
		result->next = sorted_merge(a, b->next);
	}
	return (result);
}

void		front_back_split(t_file *source,t_file **front_ref, t_file **back_ref)
{
	t_file	*fast;
	t_file	*slow;

	slow = source;
	fast = source->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front_ref = source;
	*back_ref = slow->next;
	slow->next = NULL;
}