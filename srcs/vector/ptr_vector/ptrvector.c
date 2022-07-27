//
// Created by Peer de Bakker on 7/27/22.
//

#include "vector.h"
#include <stdlib.h>

static int ptrvector_realloc(t_ptrvector *vec, size_t newsize)
{
	size_t	i;
	void	**new_arr;

	new_arr = calloc(newsize + 1, sizeof(void *));
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

t_ptrvector* ptrvector_init(size_t init_size, bool malloced)
{
	t_ptrvector	*vec;

	if (init_size == 0)
		init_size = 1;
	vec = calloc(1, sizeof(t_ptrvector));
	if (!vec) {
		return (NULL);
	}
	vec->capacity = init_size;
	vec->malloced = malloced;
	vec->arr = calloc(init_size + 1, sizeof(void *));
	if (!vec->arr) {
		ptrvector_destroy(vec);
		return (NULL);
	}
	return (vec);
}

int	ptrvector_pushback(t_ptrvector *vec, void *item)
{
	if (vec->size == vec->capacity)
	{
		if (ptrvector_realloc(vec, vec->capacity * 2)) {
			return (EXIT_FAILURE);
		}
	}
	vec->arr[vec->size] = item;
	++vec->size;
	return (EXIT_SUCCESS);
}

ssize_t	ptrvector_find_by_value(t_ptrvector *vec, void *to_find)
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
