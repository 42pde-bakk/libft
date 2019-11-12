/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 14:22:40 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/11/08 14:53:16 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	substring = (char*)malloc(len + 1);
	if (substring == NULL)
		return (NULL);
	while ((i < len) && (s[i + (size_t)start] != '\0'))
	{
		substring[i] = s[i + (size_t)start];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
