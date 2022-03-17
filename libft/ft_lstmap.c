/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:50:18 by lpfleide          #+#    #+#             */
/*   Updated: 2021/06/30 13:32:19 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;

	new = 0;
	while (lst != 0)
	{
		temp = ft_lstnew((*f)(lst -> content));
		if (temp == 0)
		{
			ft_lstclear(&new, del);
			ft_lstclear(&temp, del);
			return (0);
		}
		else
			ft_lstadd_back(&new, temp);
		lst = lst->next;
	}
	return (new);
}
