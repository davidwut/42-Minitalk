/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 08:30:52 by dwuthric          #+#    #+#             */
/*   Updated: 2022/10/29 13:52:24 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	if (!needle)
		return ((char *)haystack);
	i = -1;
	while (haystack[++i])
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j])
			j++;
		if (needle[j] == 0)
			return ((char *)haystack + i);
	}
	if (haystack[i] == needle[0])
		return ((char *)haystack + i);
	return (NULL);
}
