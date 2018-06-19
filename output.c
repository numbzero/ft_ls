#include "ft_ls.h"

void	print_list(t_file *list)
{
	while (list != NULL)
	{
		printf("name - %s\n", list->name);
		printf("full_name - %s\n", list->full_name);
		printf("file_permissions - %s\n", list->file_permissions);
		printf("owner - %s\n", list->owner);
		printf("group - %s\n", list->group);
		printf("links - %d\n", list->n_link);
		printf("size - %d\n", list->size);
		printf("atime - %s\n", list->time.atime);
		printf("ctime - %s\n", list->time.ctime);
		printf("mtime - %s\n\n", list->time.mtime);
		list = list->next;
	}
}