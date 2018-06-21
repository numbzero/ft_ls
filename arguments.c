#include "ft_ls.h"

t_proc	process_args(int ac, char **av)
{
	int		i;
	t_proc	var;

	var.files = NULL;
	var.dirs = NULL;
	i = 1;
	while (i < ac)
	{

		if (strlen(av[i]) == 2 && av[i][0] == '-')
			simple_opt(&var, av[i]);
		else if (av[i][0] == '-' && strlen(av[i]) > 2)
			combined_opt(&var, av[i]);
		else 
			dir_file_arg(&var, av[i]);
		i++;
	}
	return var;
}

void	simple_opt(t_proc *var, char *str)
{
	if (strcmp(str, "-l") == 0)
		var->l_opt = 1;
	else if (strcmp(str, "-a") == 0)
		var->a_opt = 1;
	else if (strcmp(str, "-r") == 0)
		var->r_opt = 1;
	else if (strcmp(str, "-R") == 0)
		var->R_opt = 1;
	else if (strcmp(str, "-t") == 0)
		var->t_opt = 1;
	else {
		printf("ft_ls: illegal option -- %c\n", str[1]);
		exit(1);
	}
}

void	combined_opt(t_proc *var, char *str)
{
	int		i;

	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] == 'l') 
			var->l_opt = 1;
		else if (str[i] == 'a') 
			var->a_opt = 1;
		else if (str[i] == 'r') 
			var->r_opt = 1;
		else if (str[i] == 't') 
			var->t_opt = 1;
		else if (str[i] == 'R') 
			var->R_opt = 1;
		else {
			printf("ft_ls: illegal option -- %c\n", str[i]);
			exit(1);
		}
		i++;
	}
}

void	dir_file_arg(t_proc *var, char *str)
{
	if (is_dir(str))
		dir_list_add(&var->dirs, str);
	else if (is_file(str)) {
		list_add(&var->files, str, NULL);
	}
	else  {
		printf("ft_ls: %s: No such file or directory\n", str);
		exit(1);
	}
}

int		is_dir(char *str)
{
	struct stat sb;

	if (stat(str, &sb) < 0)
		return (0);
	return (S_ISDIR(sb.st_mode));
}

int		is_file(char *str)
{
	struct stat sb;

	if (stat(str, &sb) < 0)
		return (0);
	if (S_ISREG(sb.st_mode) || S_ISCHR(sb.st_mode) || S_ISBLK(sb.st_mode) ||
		S_ISFIFO(sb.st_mode) || S_ISLNK(sb.st_mode) || S_ISSOCK(sb.st_mode))
		return (1);
	else
		return (0);
}

t_dir* dir_list_new(char *str)
{
	t_dir *lst = (t_dir *)malloc(sizeof(t_dir));
 	lst->name = strdup(str);
 	lst->next = NULL;
 	return (lst);
}
  
void	dir_list_add(t_dir **head, char *str)
{
	while (*head != NULL) 
  		head = &(*head)->next;
 	*head = dir_list_new(str);
}

void    delete_dirs(t_dir **list)
{
        t_dir  *tmp;
        t_dir  *next;

        tmp = *list;
        while (tmp != NULL)
        {
                next = tmp->next;
                free(tmp->name);
                tmp = next;
        }
        *list = NULL;
}