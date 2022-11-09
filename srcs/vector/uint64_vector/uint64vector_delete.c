//
// Created by Peer de Bakker on 7/27/22.
//

#include "vector.h"

void uint64vector_destroy(t_uint64vector *vec)
{
	free(vec->arr);
	vec->arr = NULL;
	free(vec);
}

void uint64vector_delete_bypos(t_uint64vector *vec, size_t pos)
{
	if (pos >= vec->size)
		return ;

	while (pos < vec->size)
	{
		vec->arr[pos] = vec->arr[pos + 1];
		++pos;
	}
	--vec->size;
}

void uint64vector_delete_byval(t_uint64vector *vec, uint64_t item)
{
	size_t	pos;

	pos = 0;
	while (pos < vec->size)
	{
		if (vec->arr[pos] == item)
		{
			uint64vector_delete_bypos(vec, pos);
			return ;
		}
		++pos;
	}
}
