/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfischer <cfischer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:37:55 by cfischer          #+#    #+#             */
/*   Updated: 2022/06/25 23:06:07 by cfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex(unsigned long int num, char hextype)
{
	int		i;
	char	*s;
	int		dex;

	i = 0;
	s = NULL;
	if (num == 0)
	{
		s = ft_itoa(num);
		i = 1;
	}
	while (num > 0)
	{
		dex = num % 16;
		num = num / 16;
		s = hex_char(dex, s, hextype);
		i++;
	}
	ft_putstr_fd(s, 1);
	free(s);
	return (i);
}

int	checker_str(int flag, va_list ap)
{
	int		i;
	char	a;

	i = 0;
	if (flag == 'c')
	{
		i = 1;
		a = va_arg(ap, int);
		write (1, &a, 1);
	}
	if (flag == 's')
		i = trans_string(va_arg(ap, char *));
	if (flag == '%')
	{
		i = 1;
		ft_putchar_fd('%', 1);
	}
	return (i);
}

int	checker_num(int flag, va_list ap)
{
	int		i;
	char	*s;

	i = 0;
	if (flag == 'd' || flag == 'i')
	{
		s = ft_itoa(va_arg(ap, int));
		i = ft_strlen(s);
		ft_putstr_fd(s, 1);
		free(s);
	}
	if (flag == 'u')
		i = trans_unsigned(va_arg(ap, int));
	if (flag == 'x')
		i = hex(va_arg(ap, unsigned int), 87);
	if (flag == 'X')
		i = hex(va_arg(ap, unsigned int), 55);
	if (flag == 'p')
		i = trans_adress(va_arg(ap, unsigned long int));
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	ap;

	va_start(ap, str);
	i = 0;
	while (*str != 0)
	{
		if (*str == '%')
		{
			str++;
			i += checker_str(*str, ap);
			i += checker_num(*str, ap);
			str++;
		}
		if (*str && *str != '%')
		{
			ft_putchar_fd(*str, 1);
			str++;
			i++;
		}
	}
	va_end(ap);
	return (i);
}
