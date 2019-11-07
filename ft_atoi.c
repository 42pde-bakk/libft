/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 14:51:25 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/11/06 13:54:37 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int				n;
	int				sign;
	unsigned long	result;

	n = 0;
	result = 0;
	sign = 1;
	while (str[n] == 32 || str[n] == '\t' || str[n] == '\n' ||
	str[n] == '\v' || str[n] == '\f' || str[n] == '\r')
		n++;
	if (str[n] == '-')
		sign = sign * -1;
	if (str[n] == '-' || str[n] == '+')
		n++;
	while ((str[n] >= 48) && (str[n] <= 57))
	{
		if ((result >= 922337203685477580) && (str[n] > 56) && (sign == -1))
			return (0);
		if ((result >= 922337203685477580) && (str[n] > 55) && (sign == 1))
			return (-1);
		result = result * 10 + str[n] - 48;
		n++;
	}
	return (sign * result);
}
