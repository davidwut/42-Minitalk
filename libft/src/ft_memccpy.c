/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 04:42:22 by dwuthric          #+#    #+#             */
/*   Updated: 2022/10/29 13:52:23 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*dest_ptr;
	const unsigned char	*src_ptr;
	size_t				i;

	dest_ptr = dest;
	src_ptr = src;
	i = -1;
	while (++i < n)
	{
		dest_ptr[i] = src_ptr[i];
		if (src_ptr[i] == (unsigned char)c)
			return (dest + i + 1);
	}
	if (src_ptr[i - 1] == (unsigned char)c)
		return (dest + i);
	return (NULL);
}
