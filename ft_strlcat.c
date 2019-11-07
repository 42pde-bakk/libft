/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 10:53:26 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/11/05 12:52:27 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d;
	size_t	i;
	size_t	size;

	d = 0;
	while (dst[d] != '\0')
		d++;
	size = 0;
	while (src[size] != '\0')
		size++;
	if (dstsize <= d)
		size = dstsize + size;
	else
		size = d + size;
	i = 0;
	while ((src[i] != '\0') && (d + 1 < dstsize))
	{
		dst[d] = src[i];
		d++;
		i++;
	}
	dst[d] = '\0';
	return (size);
}
