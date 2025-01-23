/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodos-s <thodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:31:36 by thodos-s          #+#    #+#             */
/*   Updated: 2023/11/17 13:25:33 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp_list;

	if (!lst)
		return (NULL);
	tmp_list = lst;
	while (tmp_list->next)
		tmp_list = tmp_list->next;
	return (tmp_list);
}
