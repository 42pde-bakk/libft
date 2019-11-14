/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 15:11:23 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/11/14 09:34:38 by pde-bakk      ########   odam.nl         */
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

static int	edgecasecheck(int n, char *str)
{
	int		ii;
	char	*fstr;

	if (n == -2147483648)
	{
		ii = 0;
		fstr = "-2147483648";
		while (ii < 11)
		{
			str[ii] = fstr[ii];
			ii++;
		}
		str[11] = '\0';
		return (1);
	}
	else if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (1);
	}
	return (0);
}

char		*ft_itoa(int n)
{
	char	*ret;
	int		i;
	int		nb;

	i = amount(n);
	nb = n;
	if (n < 0)
		nb = -n;
	ret = (char*)malloc(i + 1);
	if (ret == NULL)
		return (NULL);
	if (edgecasecheck(n, ret) == 1)
		return (ret);
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
