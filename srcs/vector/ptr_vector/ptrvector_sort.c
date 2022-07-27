//
// Created by Peer de Bakker on 7/27/22.
//

#include "vector.h"

static size_t	find_desired_position(t_ptrvector *vec, const void *ptr)
{
	size_t	i;

	i = 0;
	while (vec->arr[i] < ptr)
	{
		++i;
	}
	return (i);
}

static void	reinsert(t_ptrvector *vec, size_t index)
{
	void	*const value = vec->arr[index];
	size_t			desired_pos;

	desired_pos = find_desired_position(vec, value);
	while (index > desired_pos)
	{
		vec->arr[index] = vec->arr[index - 1];
		--index;
	}
	vec->arr[desired_pos] = value;
}

void	ptrvector_sort(t_ptrvector *vec)
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
