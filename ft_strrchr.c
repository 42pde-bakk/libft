/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 15:51:28 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/11/14 12:15:50 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;
	int		count;

	str = 0;
	i = 0;
	count = ft_strlen(s);
	while (count >= i)
	{
		if (s[i] == (char)c)
			str = (char *)s + i;
		i++;
	}
	return (str);
}
