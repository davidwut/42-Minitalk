/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:36:42 by dwuthric          #+#    #+#             */
/*   Updated: 2022/10/29 13:52:23 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstnew(void	*content)
{
	t_list	*head;

	head = malloc(sizeof(*head));
	if (!head)
		return (NULL);
	head->content = content;
	head->next = NULL;
	return (head);
}
