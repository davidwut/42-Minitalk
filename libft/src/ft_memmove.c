/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 23:16:20 by dwuthric          #+#    #+#             */
/*   Updated: 2022/07/07 00:12:27 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_ptr;
	const unsigned char	*src_ptr;
	size_t				i;

	dest_ptr = dest;
	src_ptr = src;
	if (!dest_ptr || !src_ptr)
		return (dest);
	i = -1;
	if (dest_ptr <= src_ptr)
		while (++i < n)
			dest_ptr[i] = src_ptr[i];
	else
		while (++i < n)
			dest_ptr[n - i - 1] = src_ptr[n - i - 1];
	return (dest);
}
