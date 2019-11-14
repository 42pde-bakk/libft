/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 14:51:25 by pde-bakk       #+#    #+#                */
/*   Updated: 2019/11/14 12:27:55 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				n;
	int				sign;
	unsigned long	result;

	n = 0;
	result = 0;
	sign = 1;
	while (str[n] == ' ' || (str[n] >= 9 && str[n] <= 13))
		n++;
	if (str[n] == '-')
		sign = sign * -1;
	if (str[n] == '-' || str[n] == '+')
		n++;
	while ((str[n] >= '0') && (str[n] <= '9'))
	{
		if ((result > 9223372036854775807) && (sign == -1))
			return (0);
		if ((result >= 9223372036854775807) && (sign == 1))
			return (-1);
		result = result * 10 + str[n] - '0';
		n++;
	}
	return (sign * result);
}
