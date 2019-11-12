/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 11:52:41 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/11/11 17:08:05 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*var1;
	const unsigned char	*var2;

	i = 0;
	var1 = (unsigned char*)s1;
	var2 = (unsigned char*)s2;
	while (i < n)
	{
		if (var1[i] != var2[i])
			return ((unsigned char)(var1[i]) - (unsigned char)(var2[i]));
		i++;
	}
	return (0);
}
