/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfischer <cfischer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:37:55 by cfischer          #+#    #+#             */
/*   Updated: 2022/06/21 01:55:14 by cfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdarg.h>
#include <unistd.h>

#include <stdio.h> 

int ft_printf(const char* str, ...)
{
	int ar;
	char* ae; 
	
	va_list ap; 

	va_start(ap, str);

	while(*str != 0)
	{
		if (*str == '%')
		{
			str++;
			if(*str == 'c')
			{
				str++;
				ar = va_arg(ap, int);
				ft_putchar_fd(ar, 1);
			}
			if(*str == 's')
			{
				str++;
				ae = va_arg(ap, char*);
				ft_putstr_fd(ae, 1);

			}
		}
		ft_putchar_fd(*str, 1);
		str++;
	}
	va_end(ap);

}

int main()
{
	char* elegosta = "pao de queijo %d \n"; 
	
	printf(elegosta, "dsadds");
	ft_printf(elegosta, "dsadds");

}
