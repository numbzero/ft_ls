#include "ft_ls.h"

int		main(int argc, char const *argv[])
{
	t_file	*list;

	list = NULL;
	if (argc == 2)
	{
		list = get_one_dir(argv[1]);
		alphabetic_sort(&list);
		print_list(list);
		free_list(&list);
	}
	else
		printf("program_name: <directory_name>\n");
	return (0);
}