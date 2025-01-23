/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodos-s <thodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:35:09 by thodos-s          #+#    #+#             */
/*   Updated: 2023/11/17 13:30:59 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp_list;
	t_list	*out_list;

	if (!f || !lst)
		return (NULL);
	out_list = NULL;
	while (lst)
	{
		tmp_list = ft_lstnew(f(lst->content));
		if (!tmp_list)
		{
			ft_lstclear(&tmp_list, (*del));
			return (NULL);
		}
		ft_lstadd_back(&out_list, tmp_list);
		lst = lst->next;
	}
	return (out_list);
}
