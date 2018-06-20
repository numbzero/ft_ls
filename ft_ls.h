#ifndef FT_LS_H
# define FT_LS_H

# include <sys/stat.h>
# include <sys/types.h>

# include <uuid/uuid.h>

# include <dirent.h>
# include <unistd.h>

# include <stdlib.h>
# include <string.h>
# include <stdio.h>

# include <grp.h>
# include <pwd.h>

# include <time.h>

# define	MAJOR(x)	((unsigned int)(((u_int32_t)(x) >> 24) & 0xff))
# define	MINOR(x)	((unsigned int)((x) & 0xffffff))

typedef struct 		s_time
{
	char			*atime;
	char			*ctime;
	char			*mtime;
}					t_time;

typedef struct 		s_file
{
	char			*full_name;
	char			*name;
	char			*file_permissions;
	char			*owner;
	char			*group;
	unsigned int 	n_link;
	unsigned int 	size;
	unsigned int	major;
	unsigned int	minor;
	struct s_time	time;
	struct s_file	*next;
}					t_file;

typedef struct 		s_recur
{
	char			*name;
	struct s_recur	*next;
}					t_recur;

t_file				*get_one_dir(char const *dir_name);
void				list_add(t_file **list, char *name, char const *dir_name);
t_file				*new_node(char *name, char const *dir_name);
void				free_list(t_file **list);

void				alphabetic_sort(t_file **list_ref);
void				merge_sort(t_file **list_ref);
t_file				*sorted_merge(t_file *a, t_file *b);
void				front_back_split(t_file *source,t_file **front_ref, t_file **back_ref);

char 				*concatenate1(char const *a, char *b);
char 				*concatenate2(char const *a, char *b, char *c);

char				*file_type_permissions(struct stat f_stat);
char				*get_owner(struct stat f_stat);
char				*get_group(struct stat f_stat);
t_time				get_time(struct stat f_stat);
char				*ft_ldate(char *long_time);
char				*get_link(char *full_path, char c);

void				default_output(t_file *list);
void				long_output(t_file *list);

void	recursive(char const *dir_name);


#endif