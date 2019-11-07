/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 16:39:06 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/11/04 11:31:48 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*sh;
	char	*sn;
	size_t	i;
	size_t	n;

	sh = (char*)haystack;
	sn = (char*)needle;
	i = 0;
	n = 0;
	if (sn[0] == '\0')
		return (sh);
	while ((sh[i]) && (sn[n]) && (i < len))
	{
		while (sh[i] == sn[n])
		{
			i++;
			n++;
			if (sn[n] == '\0')
				return (sh + i - n);
		}
		i++;
		n = 0;
	}
	return (0);
}
