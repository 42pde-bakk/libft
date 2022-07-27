/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-bakk <pde-bakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:48:33 by pde-bakk          #+#    #+#             */
/*   Updated: 2022/03/01 14:48:34 by pde-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include <stdlib.h>
# include <sys/types.h>
# include <stdbool.h>

# ifndef CONTENT
#  define CONTENT int
# endif

typedef struct s_intvector
{
	CONTENT		*arr;
	size_t		size;
	size_t		capacity;
}t_intvector;

t_intvector	*intvector_init(size_t init_size);
void		intvector_destroy(t_intvector *vec);

int intvector_pushback(t_intvector *vec, CONTENT item);
void		intvector_delete_bypos(t_intvector *vec, size_t pos);
void		intvector_delete_byval(t_intvector *vec, CONTENT item);

ssize_t		intvector_find_by_value(t_intvector *vec, CONTENT to_find);
void		intvector_sort(t_intvector *vec);

//void		fatal_error(const char *s);
//void	*calloc_wrapper(size_t nmemb, size_t size);

typedef struct s_ptrvector
{
	void	**arr;
	bool	malloced;
	size_t	size;
	size_t	capacity;
}	t_ptrvector;

t_ptrvector* ptrvector_init(size_t init_size, bool malloced);
void ptrvector_destroy(t_ptrvector *vec);

int 		ptrvector_pushback(t_ptrvector *vec, void *item);
void ptrvector_delete_bypos(t_ptrvector *vec, size_t pos);
void ptrvector_delete_byval(t_ptrvector *vec, void *item);

ssize_t		ptrvector_find_by_value(t_ptrvector *vec, void *to_find);
void			ptrvector_sort(t_ptrvector *vec);

//VECTOR_H
#endif
