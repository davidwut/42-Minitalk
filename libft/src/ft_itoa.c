/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:26:58 by dwuthric          #+#    #+#             */
/*   Updated: 2022/10/29 13:52:23 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	i_len(long long n)
{
	int	c;

	if (n == 0)
		return (1);
	c = 0;
	while (n)
	{
		c++;
		n /= 10;
	}
	return (c);
}

static void	_set(int nb, long long *n, int *sign, int *len)
{
	*n = nb;
	if (nb < 0)
	{
		*sign = 1;
		*n *= -1;
	}
	else
		*sign = 0;
	*len = i_len(*n);
}

char	*ft_itoa(int nb)
{
	char		*res;
	int			sign;
	int			len;
	long long	n;

	_set(nb, &n, &sign, &len);
	res = malloc(len + sign + 1);
	if (!res)
		return (NULL);
	res[len + sign] = 0;
	if (n == 0)
	{
		res[0] = '0';
		return (res);
	}
	if (sign)
		res[0] = '-';
	while (n)
	{
		res[len-- + sign - 1] = (n % 10) + '0';
		n /= 10;
	}
	return (res);
}
