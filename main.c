#include "get_next_line.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int i;
	int fd;
	char *line;

	if (argc == 1)
	{
		return (0);
	}
	argv++;
	while (*argv)
	{
		fd = open(*argv++, O_RDONLY);
		while ((i = get_next_line(fd, &line)) > 0)
		{
			printf("->:%s\n", line);
			ft_strdel(&line);
		}
		printf("%d\n", i);
	}
	return (0);
}

//
// int main(int argc, char **argv)
// {
// 	int i;
// 	int fd;
// 	char *line;
//
//
// 	if (argc != 4)
// 		return (0);
//
// 		fd = open(argv[i], O_RDONLY);
// 		while ((i = get_next_line(fd, &line)) > 0)
// 			printf("->:%s\n", line);
// 		//printf("%d\n", i);
// 	return (0);
// }


// int main()
// {
// 	t_list *lol = NULL;
// 	t_dict *f;
// 	ft_ddnew(1, &lol);
// 	ft_ddnew(25, &lol);
// 	ft_ddnew(24, &lol);
// 	ft_ddnew(6, &lol);
// 	//int i = 0;
// 	f = ft_ddnew(25, &lol);
// 	f->value[0] = '1';
// 	while (lol)
// 	{
// 		f = lol->content;
// 		printf("%d\t%s\n", f->key, f->value);
// 		lol = lol->next;
// 	}
// 	ft_ddnew(24, &lol);
// 	ft_ddnew(25, &lol);
// 	ft_ddnew(24, &lol);
// 	ft_ddnew(24, &lol);
// 	ft_ddnew(24, &lol);
// 	ft_ddnew(24, &lol);
//
// 	while (lol)
// 	{
// 		f = lol->content;
// 		printf("%d\t%s\n", f->key, f->value);
// 		lol = lol->next;
// 	}
// 	return (0);
// }
