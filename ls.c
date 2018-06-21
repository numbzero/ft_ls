#include "ft_ls.h"

void	ls(t_proc var)
{
	t_file	*list;

	list = NULL;
	if (var.files == NULL && var.dirs == NULL)
	{
		if (var.a_opt) list = get_one_dir(".", 1);
		else list = get_one_dir(".", 0);
		sorting(&list , var.r_opt, var.t_opt);
		if (var.l_opt) long_output(list, var.t_opt);
		else default_output(list);
		free_list(&list);		
	}
	if (var.files != NULL)
	{
		sorting(&(var).files, var.r_opt, var.t_opt);
		if (var.l_opt) long_output(var.files, var.t_opt);
		else default_output(var.files);
		free_list(&(var.files));
	}
	if (var.dirs != NULL)
	{
		while (var.dirs != NULL)
		{
			if (!var.R_opt)
			{
				if (var.a_opt) list = get_one_dir(var.dirs->name, 1);
				else list = get_one_dir(var.dirs->name, 0);
				sorting(&list, var.r_opt, var.t_opt);
				if (var.l_opt) long_output(list, var.t_opt);
				else default_output(list);
				free_list(&list);
			}
			else
				recursive(var.dirs->name, var.a_opt, var.l_opt, var.r_opt, var.t_opt);
			var.dirs = var.dirs->next;
		}
		delete_dirs(&(var.dirs));
	}
}