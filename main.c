/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfischer <cfischer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:37:55 by cfischer          #+#    #+#             */
/*   Updated: 2022/06/22 23:38:57 by cfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h> 

long int inverter(long int num)
{
	long int res;
	
	res = 0;

	while(num / 10)
	{
		res += num % 10;
		res = res * 10;
		num = num / 10;
	}
	res += num;
	return res;
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

int hex(unsigned long int num, char hextype)
{
	int i;
	char* s;
	int dex;

	i = 0;

	s = NULL;
	while(num > 0)
	{
		dex = num % 16;
		num = num / 16;
		s = hex_char(dex, s, hextype);
		i++;
	}
	ft_putstr_fd(s, 1);
	free(s);
	return i;
}

int checker_str(int flag, va_list ap)
{
	char* s;
	int i;

	i = 0;
	
	if(flag == 'c')
	{
		i = 1;
		ft_putchar_fd(va_arg(ap, int), 1);
	}
	if(flag == 's')
	{
		s = va_arg(ap, char*);
		i = ft_strlen(s);
		ft_putstr_fd(s, 1);
	}
	if(flag == '%')
	{
		i = 1;
		ft_putchar_fd('%', 1);
	}
	return i;
}

int checker_num(int flag, va_list ap)
{
	int uepa;
	long int ui;
	int i;
	char* s;

	i = 0;
	
	if(flag == 'd' || flag == 'i')
	{
		s = ft_itoa(va_arg(ap, int));
		i = ft_strlen(s);
		ft_putstr_fd(s, 1);
	}
	if(flag == 'u')
	{
		ui = inverter(va_arg(ap, unsigned int));
		
		while (ui > 0)
		{
			uepa = ui % 10;
			ui = ui / 10;

			s = ft_itoa(uepa);
			i++;
			ft_putstr_fd(s, 1);
			free(s);
		}
		
	}
	if(flag == 'x')
	{
		i = hex(va_arg(ap, unsigned long int), 87);
	}
	if(flag == 'X')
	{
		i = hex(va_arg(ap, unsigned long int), 55);
	}
	if(flag == 'p')
	{
		ft_putstr_fd("0x", 1);
		i += 2;
		i += hex(va_arg(ap, unsigned long int), 87);
	}
	return i;
}

int ft_printf(const char* str, ...)
{
	int i; 

	va_list ap; 

	va_start(ap, str);

	i = 0;

	while(*str != 0)
	{
		if (*str == '%')
		{
			str++;
			i += checker_str(*str, ap);
			i += checker_num(*str, ap);
			str++;
		}
		if (*str != '%')
		{
			ft_putchar_fd(*str, 1);
			str++;
			i++;
		}
	}
	va_end(ap);

	return i;
}

int main()
{
	unsigned int ptr;
	unsigned int rtp;

	ft_printf("%d \n", ft_printf("Repolho: %p \t %p\n", &ptr, &rtp));
	  
	printf("%d \n", printf("Repolho: %p \t %p\n", &ptr, &rtp));
}
