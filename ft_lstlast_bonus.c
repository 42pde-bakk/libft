/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 11:38:37 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/11/10 12:47:33 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	len;

	if (lst == NULL)
		return (NULL);
	len = ft_lstsize(lst);
	while (len - 1 > 0)
	{
		lst = lst->next;
		len--;
	}
	return (lst);
}
