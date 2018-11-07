
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdio.h> //to remove

# define BUFF_SIZE 10

typedef struct		s_gnl
{
	int				fd;
	char			*str;
	struct s_gnl	*next;
}					t_gnl;

int get_next_line(const int fd, char **line);

#endif
