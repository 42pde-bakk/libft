/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 18:33:47 by pde-bakk      #+#    #+#                 */
/*   Updated: 2021/03/29 11:36:14 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strcmp(const char* const s1, const char* const s2) {
	size_t	i = 0;

	while (s1[i] && s2[i]) {
		if (s1[i] != s2[i]) {
			break;
		}
		++i;
	}
	return (s1[i] - s2[i]);
}
