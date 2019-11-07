/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 15:10:18 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/11/04 11:32:30 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	void	*new;
	size_t	n;

	n = ft_strlen(s1) + 1;
	new = malloc(n);
	if (new == NULL)
		return (NULL);
	return ((char*)ft_memcpy(new, s1, n));
}
