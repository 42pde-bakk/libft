/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 12:30:13 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/11/07 17:34:59 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *list;

	list = *alst;
	if (list && new)
	{
		while (list->next)
			list = list->next;
		list->next = new;
	}
	if (((*alst) == NULL) && (new != NULL))
		(*alst) = new;
}
