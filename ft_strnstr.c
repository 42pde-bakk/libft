/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 16:39:06 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/11/14 12:08:30 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	if (needle[n] == '\0')
		return ((char*)haystack);
	while (haystack[i] && needle[n] && i < len && len != 0)
	{
		while (haystack[i] && haystack[i] == needle[n] && (i < len))
		{
			i++;
			n++;
			if (needle[n] == '\0')
				return ((char*)haystack + i - n);
		}
		i++;
		n = 0;
	}
	return (0);
}
