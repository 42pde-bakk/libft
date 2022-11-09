//
// Created by Peer de Bakker on 7/27/22.
//

#include "vector.h"

static size_t	find_desired_position(t_uint64vector *vec, const uint64_t ptr)
{
	size_t	i;

	i = 0;
	while (vec->arr[i] < ptr)
	{
		++i;
	}
	return (i);
}

static void	reinsert(t_uint64vector *vec, size_t index)
{
	uint64_t	value = vec->arr[index];
	size_t		desired_pos;

	desired_pos = find_desired_position(vec, value);
	while (index > desired_pos)
	{
		vec->arr[index] = vec->arr[index - 1];
		--index;
	}
	vec->arr[desired_pos] = value;
}

void	uint64vector_sort(t_uint64vector *vec)
{
	size_t	i;

	i = 1;
	while (i < vec->size)
	{
		if (vec->arr[i] < vec->arr[i - 1])
		{
			reinsert(vec, i);
		}
		++i;
	}
}
