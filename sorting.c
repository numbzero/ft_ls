#include "ft_ls.h"

void	alphabetic_sort(t_file **list_ref)
{
	merge_sort(&(*list_ref));
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