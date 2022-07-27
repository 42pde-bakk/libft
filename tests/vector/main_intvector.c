//
// Created by Peer de Bakker on 7/27/22.
//

#include "vector.h"
#include <stdio.h>

int	fakemain(void)
{
	t_intvector	*vec;
	int			i;

	i = 0;
	vec = intvector_init(0);
	while (i < 30)
	{
		intvector_pushback(vec, i);
		++i;
	}
	printf("Capacity is %zu\n", vec->capacity);
	i = 0;
	intvector_delete_byval(vec, 10);
	intvector_delete_bypos(vec, 10);
	intvector_delete_bypos(vec, 13);
	while ((size_t)i < vec->size)
	{
		printf("vec[%d]: {%d}\n", i, vec->arr[i]);
		++i;
	}
	printf("vector has item %d at index %zd\n", 20, \
		intvector_find_by_value(vec, 20));
	intvector_destroy(vec);
	return (0);
}

int	main(void)
{
	fakemain();
	return (0);
}
