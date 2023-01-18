/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 17:02:56 by pde-bakk      #+#    #+#                 */
/*   Updated: 2021/03/29 11:37:11 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	setcheck(char const *set, char a) {
	int	i = 0;

	while (set[i]) {
		if (set[i] == a)
			return (1);
		i++;
	}
	return (0);
}

static int	lengthchecker(char const *s1, char const *set) {
	int	i = 0;
	int	end = 0;

	while (s1[i] != '\0') {
		if (setcheck(set, s1[i]) == 0)
			end = i;
		i++;
	}
	return (end + 1);
}

char	*ft_strtrim(char const *s1, char const *set) {
	int		start;
	int		len;
	char	*trim;
	int		i = 0;

	if (s1 == 0 || set == 0)
		return (NULL);
	while ((s1[i]) && (setcheck(set, s1[i]) == 1))
		i++;
	start = i;
	len = lengthchecker(s1, set) - start;
	if (len <= 0)
		len = 0;
	trim = malloc(sizeof(char) * (len) + 1);
	if (trim == NULL)
		return (NULL);
	i = 0;
	while (i < len) {
		trim[i] = s1[start + i];
		i++;
	}
	trim[i] = '\0';
	return (trim);
}
