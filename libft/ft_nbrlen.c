/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_nbrlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: epoggio <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 18:24:09 by epoggio      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 18:24:09 by epoggio     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

long		ft_nbrlen(int input)
{
	long	i;

	i = 1;
	if (input < 0)
		++i;
	while ((input /= 10))
		++i;
	return (i);
}