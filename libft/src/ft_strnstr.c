/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:08:42 by dwuthric          #+#    #+#             */
/*   Updated: 2022/10/29 13:52:24 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	if (!needle)
		return ((char *)haystack);
	i = -1;
	while (haystack[++i])
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j] && (i + j) < n)
			j++;
		if (needle[j] == 0)
			return ((char *)haystack + i);
	}
	if (haystack[i] == needle[0])
		return ((char *)haystack + i);
	return (NULL);
}
