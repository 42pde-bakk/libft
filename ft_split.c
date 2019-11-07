/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/03 15:55:21 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/11/05 16:28:46 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c)
		{
			count++;
			while ((s[i]) && (s[i] != c))
				i++;
		}
	}
	return (count);
}

static int	ft_wordlength(const char *s, char c)
{
	int	i;

	i = 0;
	while ((s[i]) && (s[i] != c))
		i++;
	return (i);
}

static char	*ft_mallocword(const char *s, char c)
{
	int		i;
	char	*word;
	int		length;

	i = 0;
	length = 0;
	while ((s[i]) && (s[i] != c))
		i++;
	length = i;
	i = 0;
	word = (char *)malloc(sizeof(char) * (length + 1));
	if (word == NULL)
		return (NULL);
	while ((s[i]) && length > 0)
	{
		word[i] = s[i];
		i++;
		length--;
	}
	word[i] = '\0';
	return (word);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		n;
	char	**arr;

	if (s == 0)
		return (0);
	i = 0;
	n = 0;
	arr = (char **)malloc(sizeof(char*) * (ft_countwords(s, c) + 1));
	if (arr == NULL)
		return (NULL);
	while (s[i])
	{
		if ((s[i] != c) && (ft_countwords(s, c) > n))
		{
			arr[n] = ft_mallocword(s + i, c);
			i = i + ft_wordlength(s + i, c);
			n++;
		}
		while (s[i] == c)
			i++;
	}
	arr[n] = NULL;
	return (arr);
}
