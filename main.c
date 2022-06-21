/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfischer <cfischer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:37:55 by cfischer          #+#    #+#             */
/*   Updated: 2022/06/22 00:53:42 by cfischer         ###   ########.fr       */
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
	char* elegosta = "pao de queijo %s  \n"; 
	
	//printf("%d \n", printf(elegosta, "paozin"));
	
	//ft_printf(elegosta, 'a', 'd');

	printf("%d \n", ft_printf("Repolho: %u \n", -2));
	printf("%d \n", printf("Repolho: %u \n", -2));
	
	//ft_printf("%u \n", -2);
	  // printf("Repolho: %c %d %i \n", 'a', 295, 2);
}
