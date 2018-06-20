#include "ft_ls.h"

int		main(int argc, char const *argv[])
{
	t_file	*list;

	list = NULL;
	if (argc == 2)
	{
		list = get_one_dir(argv[1]);
		alphabetic_sort(&list);
		long_output(list);
		free_list(&list);
	}
	else if (argc == 3)
	{
		recursive(argv[1]);	
	}
	else
		printf("program_name: <directory_name>\n");
	return (0);
 }

