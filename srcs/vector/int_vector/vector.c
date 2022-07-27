/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-bakk <pde-bakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:47:05 by pde-bakk          #+#    #+#             */
/*   Updated: 2022/03/01 14:47:07 by pde-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdlib.h>

static int	vector_realloc(t_intvector *vec, size_t newsize)
{
	size_t	i;
	CONTENT	*new_arr;

	new_arr = calloc(newsize + 1, sizeof(CONTENT));
	if (!new_arr) {
		return (EXIT_FAILURE);
	}
	i = 0;
	while (i < vec->size)
	{
		new_arr[i] = vec->arr[i];
		++i;
	}
	free(vec->arr);
	vec->arr = new_arr;
	vec->capacity = newsize;
	return (EXIT_SUCCESS);
}

t_intvector	*intvector_init(size_t init_size)
{
	t_intvector	*vec;

	if (init_size == 0)
		init_size = 1;
	vec = calloc(1, sizeof(t_intvector));
	if (!vec) {
		return (NULL);
	}
	vec->capacity = init_size;
	vec->arr = calloc(init_size + 1, sizeof(CONTENT));
	if (!vec->arr) {
		intvector_destroy(vec);
		return (NULL);
	}
	return (vec);
}

int intvector_pushback(t_intvector *vec, CONTENT item)
{
	if (vec->size == vec->capacity)
	{
		if (vector_realloc(vec, vec->capacity * 2)) {
			return (EXIT_FAILURE);
		}
	}
	vec->arr[vec->size] = item;
	++vec->size;
	return (EXIT_SUCCESS);
}

ssize_t	intvector_find_by_value(t_intvector *vec, CONTENT to_find)
{
	size_t	i;

	i = 0;
	while (i < vec->size)
	{
		if (vec->arr[i] == to_find)
			return ((ssize_t)i);
		++i;
	}
	return (-1);
}
