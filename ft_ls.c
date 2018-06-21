#include "ft_ls.h"

int		main(int argc, char *argv[])
{
	t_proc	var;

	var = process_args(argc, argv);
	ls(var);
	return (0);
 }