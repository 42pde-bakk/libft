/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 13:43:03 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/11/04 11:32:14 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *ret;

	ret = malloc(count * size);
	if (ret == 0)
		return (0);
	ft_bzero(ret, count * size);
	return (ret);
}
