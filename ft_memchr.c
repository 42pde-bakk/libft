/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 11:25:10 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/11/04 11:28:39 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*var;

	i = 0;
	var = (char*)s;
	if (var[0] == '\0')
		ft_strlen(var);
	while ((var) && (i < n))
	{
		if (var[i] == c)
		{
			return (var + i);
		}
		if (var[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
