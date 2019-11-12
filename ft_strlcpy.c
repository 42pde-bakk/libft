/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 10:44:29 by pde-bakk       #+#    #+#                */
/*   Updated: 2019/11/12 15:08:02 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	i;
	size_t	d;

	count = 0;
	d = 0;
	i = 0;
	if (dst == NULL || src == NULL)
		return (0);
	while (src[count] != '\0')
		count++;
	while (dst[d] != '\0')
		d++;
	if (count + 1 < dstsize)
		ft_memcpy(dst, src, count + 1);
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (count);
}
