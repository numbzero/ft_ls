#include "ft_ls.h"

char	*get_owner(struct stat f_stat)
{
	struct passwd	*pwd;

	if ((pwd = getpwuid(f_stat.st_uid)) == NULL)
	{
		exit(1);
	}
	return (strdup(pwd->pw_name));
}

char	*get_group(struct stat f_stat)
{
	struct group	*grp;

	if ((grp = getgrgid(f_stat.st_gid)) == NULL)
	{
		exit(1);
	}
	return (strdup(grp->gr_name));
}

char	*file_type_permissions(struct stat f_stat)
{
	char	*str;

	str = NULL;
	str = (char *)malloc(11 * sizeof(char));
	if (!str)
		exit(1);
	if (S_ISDIR(f_stat.st_mode))
		str[0] = 'd';
	else if (S_ISBLK(f_stat.st_mode))
		str[0] = 'b';
	else if (S_ISCHR(f_stat.st_mode))
		str[0] = 'c';
	else if (S_ISREG(f_stat.st_mode))
		str[0] = '-';
	else if (S_ISFIFO(f_stat.st_mode))
		str[0] = 'p';
	else if (S_ISLNK(f_stat.st_mode))
		str[0] = 'l';
	else if (S_ISSOCK(f_stat.st_mode))
		str[0] = 's';
	str[1] = (f_stat.st_mode & S_IRUSR) ? 'r' : '-'; 
	str[2] = (f_stat.st_mode & S_IWUSR) ? 'w' : '-';
	str[3] = (f_stat.st_mode & S_IXUSR) ? 'x' : '-';
	str[4] = (f_stat.st_mode & S_IRGRP) ? 'r' : '-';
	str[5] = (f_stat.st_mode & S_IWGRP) ? 'w' : '-';
	str[6] = (f_stat.st_mode & S_IXGRP) ? 'x' : '-';
	str[7] = (f_stat.st_mode & S_IROTH) ? 'r' : '-';
	str[8] = (f_stat.st_mode & S_IWOTH) ? 'w' : '-';
	str[9] = (f_stat.st_mode & S_IXOTH) ? 'x' : '-';
	str[10] = '\0';
	return (str);		
}

t_time	get_time(struct stat f_stat)
{
	t_time time;

	time.atime = strdup(ft_ldate(ctime(&f_stat.st_atime)));
	time.ctime = strdup(ft_ldate(ctime(&f_stat.st_ctime)));
	time.mtime = strdup(ft_ldate(ctime(&f_stat.st_mtime)));
	time.t_atime = f_stat.st_atime;
	time.t_ctime = f_stat.st_ctime;
	time.t_mtime = f_stat.st_mtime;
	return (time);	
}

char	*ft_ldate(char *long_time)
{
	char	*str;
	int		i;
	int		j;

	str = NULL;
	str = (char *)malloc(sizeof(char) * 12);
	i = 4;
	j = 0;
	while (i <= 15)
		str[j++] = long_time[i++];
	str[j] = '\0';
	return (str);
}