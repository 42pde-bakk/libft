/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 11:52:41 by pde-bakk       #+#    #+#                */
/*   Updated: 2019/11/14 10:59:57 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned const char	*var1;
	unsigned const char	*var2;

	i = 0;
	var1 = (unsigned char*)s1;
	var2 = (unsigned char*)s2;
	if (s1 == 0 && s2 == 0)
		return (0);
	while (i < n)
	{
		if (var1[i] != var2[i])
			return ((unsigned char)(var1[i]) - (unsigned char)(var2[i]));
		i++;
	}
	return (0);
}
