//
// Created by Peer de Bakker on 7/27/22.
//

#include "vector.h"
#include <stdio.h>

int	fakemain(void)
{
	static char *const	strs[] = {
			"RA", "RB", "SA", "SB", "SSA", "SSB"
	};
	t_ptrvector			*vec;
	int					i;

	i = 0;
	vec = ptrvector_init(0, false);
	while (i < 30)
	{
		ptrvector_pushback(vec, strs[rand() % 6]);
		++i;
	}
	printf("Capacity is %zu\n", vec->capacity);
	ptrvector_delete_byval(vec, "RA");
	ptrvector_delete_bypos(vec, 4);
	i = 0;
	while ((size_t)i < vec->size)
	{
		printf("vec[%d]: {%s}\n", i, (char *)vec->arr[i]);
		++i;
	}
	ptrvector_destroy(vec);
	return (0);
}

int	main(void)
{
	fakemain();
	return (0);
}
