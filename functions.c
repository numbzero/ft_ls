#include "ft_ls.h"

t_file	*get_one_dir(char const *dir_name)
{
	DIR 			*dr;
	struct dirent 	*de;
	t_file			*list;

	list = NULL;
	dr = opendir(dir_name);
	if (dr == NULL)
	{
		printf("Could not open current directory!\n");
		exit(1);
	}
	while ((de = readdir(dr)) != NULL)
		list_add(&list, de->d_name, dir_name);
	closedir(dr);
	return (list);
}

void	list_add(t_file **list_ref, char *name, char const *dir_name)
{
	while (*list_ref != NULL)
		list_ref = &(*list_ref)->next;
	*list_ref = new_node(name, dir_name);
}

t_file	*new_node(char *name, char const *dir_name)
{
	t_file		*new;
	struct stat	f_stat;

	new = (t_file *)malloc(sizeof(t_file));
	if (new == NULL)
		exit(1);
	if (strcmp(dir_name, "/") == 0)
		new->full_name = concatenate1(dir_name, name);
	else
		new->full_name = concatenate2(dir_name, "/", name);
	new->name = strdup(name);
	if (lstat(new->full_name, &f_stat) < 0)
		exit(1);
	new->file_permissions = file_type_permissions(f_stat);
	new->owner = get_owner(f_stat);
	new->group = get_group(f_stat);
	new->n_link = f_stat.st_nlink;
	new->size = f_stat.st_size;
	new->time = get_time(f_stat);
	/* ... */
	new->next = NULL;
	return (new);
}

void	free_list(t_file **list_ref)
{
	t_file	*tmp;
	t_file	*next;

	tmp = *list_ref;
	while (tmp != NULL)
	{
		next = tmp->next;
		free(tmp->full_name);
		free(tmp->name);
		free(tmp->file_permissions);
		free(tmp->owner);
		free(tmp->group);
		free(tmp->time.atime);
		free(tmp->time.ctime);
		free(tmp->time.mtime);
		tmp = next;
	}
	*list_ref = NULL;
}