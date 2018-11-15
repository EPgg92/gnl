/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dictremovekey.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: epoggio <epoggio@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/06 15:39:43 by epoggio      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 01:24:25 by epoggio     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_dictremovekey(t_list *d, t_key k, void (*del)(void *, size_t))
{
	t_list *curr;
	t_list *to_clean;

	curr = d;
	if (((t_dict *)curr->content)->key == k)
	{
		to_clean = curr;
		d = curr->next;
		ft_lstdelone(&to_clean, del);
	}
	else
		while (curr)
		{
			if (curr->next && ((t_dict *)curr->next->content)->key == k)
			{
				to_clean = curr->next;
				curr->next = curr->next->next;
				ft_lstdelone(&to_clean, del);
				break ;
			}
			curr = curr->next;
		}
	return (d);
}
