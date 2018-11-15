/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: epoggio <epoggio@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 13:40:52 by epoggio      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 01:30:35 by epoggio     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl	*ft_getfd(int fd, t_gnl **files)
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

static int	ft_readfd(const char *buf, int fd, t_gnl *f)
{
	int		ret;
	char	*to_clean;
	char	*unconst;

	unconst = (char *)buf;
	ret = read(fd, unconst, BUFF_SIZE);
	unconst[ret] = '\0';
	to_clean = f->str;
	if (!(f->str = ft_strjoin(f->str, buf)))
		return (-1);
	ft_strdel(&to_clean);
	return (ret);
}

static int	ft_seponfd(char **line, t_gnl *f, int ret)
{
	char	*to_clean;
	char	*tmp;

	to_clean = f->str;
	tmp = ft_strsep(&f->str, "\n");
	!(f->str) ? f->str = "\0" : 0;
	if (!(*line = ft_strdup(tmp)))
		ret = -1;
	if (!(f->str = ft_strdup(f->str)))
		ret = -1;
	ft_strdel(&to_clean);
	if (ret == 0 && **line)
		ret = 1;
	return (ret);
}

int	get_next_line(const int fd, char **line)
{
	static t_gnl	*multi_fd;
	t_gnl			*f;
	char			buf[BUFF_SIZE + 1];
	int				ret;

	if (!(ret = !(read(fd, buf, 0) < 0 || BUFF_SIZE < 1)))
		return (-1);
	if (!(f = ft_getfd(fd, &multi_fd)) || fd < 0 || !line)
		ret = -1;
	if (ret && !f->str && !(f->str = ft_strnew(0)))
		ret = -1;
	while (ret && !(ft_strchr(f->str, '\n')))
		ret = ft_readfd(buf, fd, f);
	if (ret > 0 || (ret == 0 && !(ft_strchr(f->str, '\n'))))
		ret = ft_seponfd(line, f, ret);
	return (((ret != 0) ? ret / ft_abs(ret) : ret));
}

/*
** static t_gnl *ft_cleanfd(int fd, t_gnl **files)
** {
** 	t_gnl *curr;
** 	t_gnl *to_clean;
**
** 	curr = *files;
** 	if (curr->fd == fd)
** 	{
** 		to_clean = curr;
** 		*files = curr->next;
** 		ft_strdel(&to_clean->str);
** 		free(to_clean);
** 	}
** 	else
** 		while (curr)
** 		{
** 			if (curr->fd == fd)
** 			{
** 				to_clean = curr->next;
** 				curr->next = curr->next->next;
** 				ft_strdel(&to_clean->str);
** 				free(to_clean);
** 				break ;
** 			}
** 			curr = curr->next;
** 		}
** 	return(*files);
** }
**
** multi_fd = ((ret <= 0) ? ft_cleanfd(fd, &multi_fd) : multi_fd);
*/
