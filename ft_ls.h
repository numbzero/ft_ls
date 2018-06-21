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
	time_t			t_atime;
	time_t			t_ctime;
	time_t			t_mtime;
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

typedef struct 		s_dir
{
	char			*name;
	struct s_dir	*next;
}					t_dir;

typedef struct		s_proc
{
	int				a_opt;
	int				l_opt;
	int				r_opt;
	int				t_opt;
	int				R_opt;
	struct s_dir	*dirs;
	struct s_file	*files;
}					t_proc;


void				ls(t_proc var);
t_file				*get_one_dir(char *dir_name, int i);
void				list_add(t_file **list, char *name, char *dir_name);
t_file				*new_node(char *name, char *dir_name);
void				free_list(t_file **list);

void				sorting(t_file **list_ref, int j, int i);
void				reverse_list(t_file **list_ref);
void				merge_sort(t_file **list_ref);
t_file				*sorted_merge(t_file *a, t_file *b);
void				front_back_split(t_file *source,t_file **front_ref, t_file **back_ref);
void				time_merge_sort(t_file **list_ref);
t_file				*time_sorted_merge(t_file *a, t_file *b);

char 				*concatenate1(char *a, char *b);
char 				*concatenate2(char *a, char *b, char *c);

char				*file_type_permissions(struct stat f_stat);
char				*get_owner(struct stat f_stat);
char				*get_group(struct stat f_stat);
t_time				get_time(struct stat f_stat);
char				*ft_ldate(char *long_time);
char				*get_link(char *full_path, char c);

void				default_output(t_file *list);
void				long_output(t_file *list, int x);

void    			recursive(char *dir_name, int a, int b, int c, int d);

t_proc				process_args(int ac, char **av);
void				simple_opt(t_proc *var, char *str);
void				combined_opt(t_proc *var, char *str);
void				dir_file_arg(t_proc *var, char *str);
int					is_dir(char *str);
int					is_file(char *str);
t_dir* 				dir_list_new(char *str);
void				dir_list_add(t_dir **head, char *str);
void   				delete_dirs(t_dir **list);
void				free_memory(t_proc *var);

#endif