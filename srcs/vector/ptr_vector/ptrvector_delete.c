//
// Created by Peer de Bakker on 7/27/22.
//

#include "vector.h"

void ptrvector_destroy(t_ptrvector *vec)
{
	if (vec->malloced) {
		for (size_t i = 0; i < vec->size; ++i) {
			free(vec->arr[i]);
		}
	}
	free(vec->arr);
	vec->arr = NULL;
	free(vec);
}

void ptrvector_delete_bypos(t_ptrvector *vec, size_t pos)
{
	if (pos >= vec->size)
		return ;

	if (vec->malloced) {
		free(vec->arr[pos]);
	}
	while (pos < vec->size)
	{
		vec->arr[pos] = vec->arr[pos + 1];
		++pos;
	}
	--vec->size;
}

// finds the first occurrence of item and deletes it
// right now only works for ints and chars, not strings

void ptrvector_delete_byval(t_ptrvector *vec, void *item)
{
	size_t	pos;

	pos = 0;
	while (pos < vec->size)
	{
		if (vec->arr[pos] == item)
		{
			ptrvector_delete_bypos(vec, pos);
			return ;
		}
		++pos;
	}
}
