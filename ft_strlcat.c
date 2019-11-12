/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 10:53:26 by pde-bakk       #+#    #+#                */
/*   Updated: 2019/11/12 15:59:01 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d;
	size_t	i;
	size_t	size;

	d = 0;
	size = 0;
	i = 0;
	while (dst[d] && d < dstsize)
		d++;
	while (src[size] != '\0')
		size++;
	if (d == dstsize || dstsize == 0)
		return (size + dstsize);
	if (size <= dstsize - d)
		ft_memcpy(dst + d, src, size + 1);
	else
		ft_memcpy(dst + d, src, dstsize - 1);
	dst[dstsize - 1] = '\0';
	return (size + d);
}
