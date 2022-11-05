/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:02:47 by dwuthric          #+#    #+#             */
/*   Updated: 2022/10/29 13:52:24 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	next_token(const char *str, int last, char c)
{
	int	i;

	i = -1;
	while (str[last + (++i)])
	{
		if (c == str[last + i])
			return (last + i);
	}
	return (last + i);
}

static char	**append_str(const char *str, int from, int to, char **list)
{
	char	**res;
	int		i;
	int		j;
	int		len;

	if (to - from < 1)
		return (list);
	len = ft_strlen_2((const char **)list);
	res = malloc(sizeof(*res) * (len + 2));
	i = -1;
	while (++i < len)
		res[i] = list[i];
	res[i + 1] = 0;
	res[i] = malloc(sizeof(*res[i]) * (to - from + 1));
	j = -1;
	while (++j < to - from)
		res[i][j] = str[from + j];
	res[i][j] = 0;
	free(list);
	return (res);
}

char	**ft_split(const char *str, char c)
{
	char	**res;
	int		last;
	int		next;
	int		len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	res = malloc(sizeof(*res));
	if (!res)
		return (NULL);
	res[0] = 0;
	last = 0;
	while (1)
	{
		next = next_token(str, last, c);
		res = append_str(str, last, next, res);
		last = next + 1;
		if (next >= len)
			break ;
	}
	return (res);
}
