#include "ft_ls.h"

void	default_output(t_file *list)
{
	while (list != NULL)
	{
		printf("%s\n", list->name);
		list = list->next;
	}
}

void	long_output(t_file *list, int x)
{
	while (list != NULL)
	{
		if (list->file_permissions[0] == 'b' || list->file_permissions[0] == 'c')
			printf("%s %3d\t%s\t%s\t%d, %d\t%s %s\n",list->file_permissions, list->n_link,
				list->owner, list->group, list->major, list->minor, list->time.mtime, list->name);
		else if ((list->file_permissions[0] == 'b' || list->file_permissions[0] == 'c') && x == 1)
			printf("%s %3d\t%s\t%s\t%d, %d\t%s %s\n",list->file_permissions, list->n_link,
				list->owner, list->group, list->major, list->minor, list->time.ctime, list->name);			
		else if (x == 1)
			printf("%s %3d\t%s\t%s\t%d\t%s %s\n", list->file_permissions, list->n_link, 
				list->owner, list->group, list->size, list->time.ctime, list->name);
		else
			printf("%s %3d\t%s\t%s\t%d\t%s %s\n", list->file_permissions, list->n_link, 
				list->owner, list->group, list->size, list->time.mtime, list->name);
		list = list->next;
	}
}