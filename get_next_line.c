/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: SUPER epoggio <epoggio@student.le-101.fr>  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 09:03:26 by epoggio      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 19:51:17 by epoggio     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl *ft_getfd(int fd, t_gnl **files)
{
	t_gnl	*curr;

	curr = *files;
	while (curr)
	{
		if (curr->fd == fd)
			return (curr);
		curr = curr->next;
	}
	if (!(curr = ft_memalloc(sizeof(*curr))))
		return (NULL);
	curr->fd = fd;
	curr->str = NULL;
	curr->next = *files;
	return (*files = curr);
}

static void ft_freefd(t_gnl **f)
{
	ft_strdel(&(*f)->str);
	ft_memdel((void **)f);
}


static t_gnl *ft_cleanfd(int fd, t_gnl **files)
{
	t_gnl *curr;
	t_gnl *to_clean;

	curr = *files;
	if (curr->fd == fd)
	{
		to_clean = curr;
		*files = curr->next;
		ft_freefd(&curr);
	}
	else
		while (curr)
		{
			if (curr->fd == fd)
			{
				to_clean = curr->next;
				curr->next = curr->next->next;
				ft_freefd(&curr);
				break ;
			}
			curr = curr->next;
		}
	return(*files);
}

int get_next_line(const int fd, char **line)
{
	static t_gnl *multi_fd;
	t_gnl *f;
	char buf[BUFF_SIZE + 1];
	int ret;
	char *to_clean;


	if(!(f = ft_getfd(fd, &multi_fd)) && !(*line = NULL))
		return(-1);
	if (!f->str)
		f->str = ft_strnew(0);
	while (!(ft_strchr(f->str, '\n')) && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		to_clean = f->str;
		buf[ret] = '\0';
		f->str = ft_strjoin(f->str, buf);
		ft_strdel(&to_clean);
	}
	if (ret > 0)
	{
		to_clean = f->str;
		*line = ft_strdup(ft_strsep(&f->str, "\n"));
		f->str = ft_strdup(f->str);
		ft_strdel(&to_clean);
	}
	multi_fd = ((ret <= 0) ? ft_cleanfd(fd, &multi_fd) : multi_fd);
	return (((ret != 0) ? ret / ft_abs(ret) : ret) || (fd == 0));
}
