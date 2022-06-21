/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfischer <cfischer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:37:55 by cfischer          #+#    #+#             */
/*   Updated: 2022/06/21 03:35:05 by cfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdarg.h>
#include <unistd.h>

#include <stdio.h> 

int checker(int flag, va_list ap)
{
	int c;
	char* s;
	int i;

	if(flag == 'c')
	{
		i = 1;
		c = va_arg(ap, int);
		ft_putchar_fd(c, 1);
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
			i += checker(*str, ap);
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
	
	printf("%d \n", printf(elegosta, "paozin"));

	printf("%d \n", ft_printf(elegosta, "paozin"));
	//ft_printf(elegosta, 'a', 'd');

}
