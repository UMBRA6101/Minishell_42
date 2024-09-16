/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststiter_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodos-s <thodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:11:01 by thodos-s          #+#    #+#             */
/*   Updated: 2023/11/17 13:39:23 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp_list;

	if (!lst)
		return ;
	tmp_list = lst;
	while (tmp_list != NULL)
	{
		(*f)(tmp_list->content);
		tmp_list = tmp_list->next;
	}
}
