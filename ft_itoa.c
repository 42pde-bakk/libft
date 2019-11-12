/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 15:11:23 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/11/12 15:36:22 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	amount(int n)
{
	int i;

	i = 1;
	if (n < 0)
		i++;
	while (n >= 10 || n <= -10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*edgecasecheck(int n)
{
	char	*str;
	int		i;

	i = 11;
	if (n == -2147483648)
	{
		str = (char*)malloc(sizeof(char) * 11 + 1);
		if (str == NULL)
			return (NULL);
		str = "-2147483648";
		str[11] = '\0';
		return (str);
	}
	else if (n == 0)
	{
		str = (char*)malloc(sizeof(char) * 1 + 1);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	else
		return (NULL);
}

char		*ft_itoa(int n)
{
	char	*ret;
	int		i;
	int		nb;

	if (n == -2147483648 || n == 0)
		return (edgecasecheck(n));
	i = amount(n);
	nb = n;
	if (n < 0)
		nb = -n;
	ret = (char*)malloc(sizeof(char) * (i + 1));
	if (ret == NULL)
		return (NULL);
	ret[i] = '\0';
	i--;
	while (i >= 0)
	{
		ret[i] = nb % 10 + '0';
		if (nb >= 10)
			nb = nb / 10;
		i--;
	}
	if (n < 0)
		ret[0] = '-';
	return (ret);
}
