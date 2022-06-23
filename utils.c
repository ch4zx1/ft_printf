/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfischer <cfischer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:43:11 by cfischer          #+#    #+#             */
/*   Updated: 2022/06/23 02:03:22 by cfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int trans_unsigned(int num)
{
	long int res;
	char* s;
	int i;
	
	if(num < 0)
	{
		res = INT_MAX + num;
		res += INT_MAX;
		res += 2;
		s = ft_itoa(res);
		
	}
	else 
		s = ft_itoa(num);
	ft_putstr_fd(s, 1);
	i = ft_strlen(s);
	free(s);
	return i;
}

char* hex_char(int nh, char* s, char hextype)
{
	char* res;
	char ada;
	char* number;

	
	number = (char*)malloc(sizeof(char)*2);
	number[1] = 0;

	if (nh >= 0 && nh <= 9)
		ada = '0';
	else 
		ada = hextype;

	number[0] = ada + nh;
	res = number;
	if (s)
	{
		res = ft_strjoin(number, s);
		free(s);
		free(number);
	}
	
	return res;
}