/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 15:52:20 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/11/04 14:05:37 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	n;
	char	*join;

	i = 0;
	n = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	join = (char*)malloc(ft_strlen(s1) + ft_strlen(s2));
	if (join == NULL)
		return (NULL);
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[n])
	{
		join[i] = s2[n];
		i++;
		n++;
	}
	join[i] = '\0';
	return (join);
}