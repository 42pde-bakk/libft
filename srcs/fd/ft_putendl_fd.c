/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 17:47:03 by pde-bakk      #+#    #+#                 */
/*   Updated: 2021/03/29 16:56:49 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

ssize_t	ft_putendl_fd(const char *s, int fd)
{
	ssize_t	ret = 0;

	if (s)
		ret = write(fd, s, ft_strlen(s));
	ret += write(fd, "\n", sizeof(char));
	return (ret);
}
