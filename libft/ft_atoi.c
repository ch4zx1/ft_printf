/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfischer <cfischer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:01:47 by cfischer          #+#    #+#             */
/*   Updated: 2021/09/19 16:43:58 by cfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	num;

	while (*str <= 32)
	{
		str++;
	}
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			sign = -sign;
		}
		++str;
	}
	num = 0;
	while (*str <= '9' && *str >= '0')
	{
		num *= 10;
		num += *str - 48;
		str++;
	}
	return (num * sign);
}
