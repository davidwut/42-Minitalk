/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:02:59 by dwuthric          #+#    #+#             */
/*   Updated: 2022/10/29 13:52:23 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_atoi(const char *str)
{
	int	total;
	int	sign;

	total = 0;
	sign = 1;
	while (*str == ' ' || *str == '\f' || *str == '\n' \
		|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while ('0' <= *str && *str <= '9')
		total = total * 10 + (*str++) - '0';
	return (total * sign);
}
