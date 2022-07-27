/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-bakk <pde-bakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:47:09 by pde-bakk          #+#    #+#             */
/*   Updated: 2022/03/01 14:47:10 by pde-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	intvector_destroy(t_intvector *vec)
{
	free(vec->arr);
	vec->arr = NULL;
	free(vec);
}

void	intvector_delete_bypos(t_intvector *vec, size_t pos)
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

// finds the first occurence of item and deletes it
// right now only works for ints and chars, not strings

void	intvector_delete_byval(t_intvector *vec, CONTENT item)
{
	size_t	pos;

	pos = 0;
	while (pos < vec->size)
	{
		if (vec->arr[pos] == item)
		{
			intvector_delete_bypos(vec, pos);
			return ;
		}
		++pos;
	}
}
