/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dictaddkey.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: SUPER epoggio <epoggio@student.le-101.fr>  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 09:03:00 by epoggio      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 15:59:12 by epoggio     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_dict *ft_dictaddkey(int key, t_list **dict)
{
	t_dict *f;
	t_dict *d;
	t_list *tmp;

	tmp = *dict;
	while (tmp)
	{
		d = (t_dict *)tmp->content;
		if (d->key == key)
			return (d);
		tmp = tmp->next;
	}
	f = ft_memalloc(sizeof(t_dict));
	f->key = key;
	f->value = ft_memalloc(1);
	f->size_value = 0;
	if (!(*dict))
		*dict = ft_lstnew(f, sizeof(t_dict));
	else
		ft_lstadd(dict, ft_lstnew(f, sizeof(t_dict)));
	return (f);
}
