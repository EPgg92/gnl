/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line2.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: SUPER epoggio <epoggio@student.le-101.fr>  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 09:03:26 by epoggio      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 12:21:10 by epoggio     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(const int fd, char **line)
{
	static t_list *multi_fd;
	t_dict *f;
	char buf[BUFF_SIZE + 1];
	int ret;
	//char *to_clean;

	ret = 1;
	*line = "";
	f = ft_dictaddkey(fd, &multi_fd);
	while (!(ft_strchr(f->value, '\n')) && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
	}
	if (*line == NULL || ret <= 0)
		multi_fd = ft_dictremovekey(multi_fd, fd, ft_delkintvchar);
	return (((ret != 0) ? ret / ft_abs(ret) : ret));
}
