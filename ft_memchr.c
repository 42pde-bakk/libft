/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 11:25:10 by pde-bakk       #+#    #+#                */
/*   Updated: 2019/11/11 17:59:10 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*var;

	i = 0;
	var = (char*)s;
	while ((i < n))
	{
		if (var[i] == c)
			return (var + i);
		i++;
	}
	return (0);
}
