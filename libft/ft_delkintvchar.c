/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_delkintvchar.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: SUPER epoggio <epoggio@student.le-101.fr>  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/06 15:52:23 by epoggio      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/06 16:49:21 by epoggio     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void ft_delkintvchar(void *content, size_t size)
{
	t_dict *this;
	this = (t_dict *)content;
	ft_strdel(&this->value);
	ft_bzero(content, size);
	ft_memdel(content);
}
