/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 12:27:06 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/05/13 12:27:08 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_buf;

	if (lst == NULL)
		return ;
	while ((*lst) != NULL)
	{
		del((*lst)->content);
		lst_buf = (*lst);
		(*lst) = lst_buf->next;
		free(lst_buf);
	}
	(*lst) = NULL;
}
