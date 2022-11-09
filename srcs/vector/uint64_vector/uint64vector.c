//
// Created by Peer de Bakker on 7/27/22.
//

#include "vector.h"
#include <stdlib.h>

static int uint64vector_realloc(t_uint64vector *vec, size_t newsize)
{
	size_t		i = 0;
	uint64_t*	new_arr;

	new_arr = calloc(newsize + 1, sizeof(uint64_t));
	if (!new_arr) {
		return (EXIT_FAILURE);
	}
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

t_uint64vector *uint64vector_init(size_t init_size)
{
	t_uint64vector	*vec;

	if (init_size == 0)
		init_size = 1;
	vec = calloc(1, sizeof(t_uint64vector));
	if (!vec) {
		return (NULL);
	}
	vec->capacity = init_size;
	vec->arr = calloc(init_size + 1, sizeof(uint64_t));
	if (!vec->arr) {
		uint64vector_destroy(vec);
		return (NULL);
	}
	return (vec);
}

int	uint64vector_pushback(t_uint64vector *vec, uint64_t item)
{
	if (vec->size == vec->capacity)
	{
		if (uint64vector_realloc(vec, vec->capacity * 2)) {
			return (EXIT_FAILURE);
		}
	}
	vec->arr[vec->size] = item;
	++vec->size;
	return (EXIT_SUCCESS);
}

ssize_t	uint64vector_find_by_value(t_uint64vector *vec, uint64_t to_find)
{
	size_t	i = 0;

	while (i < vec->size)
	{
		if (vec->arr[i] == to_find)
			return ((ssize_t)i);
		++i;
	}
	return (-1);
}
