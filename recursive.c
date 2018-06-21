#include "ft_ls.h"

void    recursive(char *dir_name, int a, int b, int c, int d)
{
    t_file  *list;

    if (a) list = get_one_dir(dir_name, 1);
    else list = get_one_dir(dir_name, 0);
    sorting(&list, c, d);
    printf("\n%s:\n", dir_name);
    if (b) long_output(list, d);
    else default_output(list);
    while (list != NULL)
    {
        if (list->file_permissions[0] == 'd')
            if (strcmp(list->name, ".") != 0 && strcmp(list->name, "..") != 0)
                recursive(concatenate2(dir_name, "/", list->name), a, b, c, d);
        list = list->next;
    }
    free_list(&list);
}