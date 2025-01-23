/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodos-s <thodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:48:28 by thodos-s          #+#    #+#             */
/*   Updated: 2023/11/17 11:28:34 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp_list;
	t_list	*next_list;

	if (lst)
	{
		tmp_list = *lst;
		while (tmp_list)
		{
			next_list = tmp_list->next;
			ft_lstdelone(tmp_list, (del));
			tmp_list = next_list;
		}
		*lst = NULL;
	}
}
