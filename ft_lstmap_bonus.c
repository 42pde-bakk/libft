/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 15:24:16 by pde-bakk       #+#    #+#                */
/*   Updated: 2019/11/14 10:53:40 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*tmp;

	new_list = NULL;
	if (!(lst))
		return (0);
	while (lst && f)
	{
		tmp = ft_lstnew(f(lst->content));
		if (tmp == NULL)
			ft_lstclear(&new_list, del);
		ft_lstadd_back(&new_list, tmp);
		lst = lst->next;
	}
	return (new_list);
}
