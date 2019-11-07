/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 14:22:40 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/11/04 14:05:09 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ss;
	size_t	i;

	i = 0;
	if (s == 0)
		return (0);
	ss = (char*)malloc(len + 1);
	if (ss == NULL)
		return (NULL);
	while ((i < len) && (s[i + (size_t)start] != '\0'))
	{
		ss[i] = s[i + (size_t)start];
		i++;
	}
	ss[i] = '\0';
	return (ss);
}
