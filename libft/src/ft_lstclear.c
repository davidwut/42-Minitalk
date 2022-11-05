/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:59:49 by dwuthric          #+#    #+#             */
/*   Updated: 2022/10/29 13:52:23 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstclear(t_list **list, void (*del)(void *))
{
	t_list	*current;
	t_list	*temp;

	if (!list)
		return ;
	current = *list;
	while (current)
	{
		temp = current;
		current = current->next;
		ft_lstdelone(temp, del);
	}
	*list = NULL;
}
