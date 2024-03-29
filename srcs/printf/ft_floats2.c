/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_floats2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/09 18:16:32 by pde-bakk      #+#    #+#                 */
/*   Updated: 2021/03/29 13:09:39 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"
#include "libft.h"

char	*ft_floatjoin2(char *result, int i, char *ds, t_map *map)
{
	int	n;

	n = 0;
	if (map->prec != 0)
	{
		result[i] = '.';
		i++;
		while (map->typ != 'e' && map->typ != 'g'
			&& map->prec - ft_strlen(ds) > 0)
		{
			result[i] = '0';
			i++;
		}
		while (ds && ds[n])
		{
			result[i + n] = ds[n];
			n++;
		}
	}
	return (result);
}

char	*ft_floatjoin(char *s, char *ds, t_map *map)
{
	char	*result;
	int		i;
	int		length;

	i = 0;
	length = ft_strlen(s) + ft_strlen(ds);
	if (map->prec == 0)
		length = ft_strlen(s);
	if (map->typ == 'e' || map->typ == 'E')
		length = length + 4;
	result = ft_calloc(length + 3, sizeof(char));
	if (result == 0)
		return (NULL);
	while (s && s[i])
	{
		result[i] = s[i];
		i++;
	}
	result = ft_floatjoin2(result, i, ds, map);
	free(ds);
	free(s);
	return (result);
}

void	ft_putscience(t_map *map)
{
	char	*science;
	char	*power;
	int		count;

	count = 0;
	if (map->typ != 'e' && map->typ != 'E')
		return ;
	while (map->sci >= 10)
	{
		count++;
		map->sci = map->sci / 10;
	}
	if (map->typ == 'E')
		science = "E+";
	else
		science = "e+";
	ft_putstr_flags(science,  map, 0); // TODO check
	power = ft_itoa_base(count, 10, map, map->typ);
	if (count < 10)
		ft_putchar_flags('0',  map, 0); // TODO check
	ft_putstr_flags(power, map, 0); // TODO check
	free(power);
}

void	ft_floatflagger(char *s, t_map *map)
{
	if (map->width > (int)ft_strlen(s))
		map->pad = map->width - ft_strlen(s);
	if (map->typ == 'e' || map->typ == 'E')
		map->pad = map->pad - 4;
	if ((map->plus == 1 && map->nb >= 0) || map->nb < 0)
		map->pad--;
	while (map->pad > 0 && map->min == 0)
	{
		if (map->zero == 1)
			ft_putchar_flags('0', map, 0);
		else
			ft_putchar_flags(' ',  map, 0);
		map->pad--;
	}
	ft_putsign(map);
	ft_put0x(map);
	ft_putstr_flags(s, map, 0);
	ft_putscience(map);
	while (map->min == 1 && map->pad > 0)
	{
		ft_putchar_flags(' ', map, 0);
		map->pad--;
	}
}

void	ft_morebonusflags(const char *s, t_map *map)
{
	if (s[map->pos] == 'L')
	{
		map->bon = 5;
		map->pos++;
	}
	if (s[map->pos] == 39)
	{
		map->apos = 0;
		map->pos++;
	}
	while (ft_strchr("jzt", s[map->pos]))
		map->pos++;
}
