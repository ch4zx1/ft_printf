/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfischer <cfischer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:43:52 by cfischer          #+#    #+#             */
/*   Updated: 2022/06/23 01:46:17 by cfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int hex(unsigned long int num, char hextype);
int checker_str(int flag, va_list ap);
int checker_num(int flag, va_list ap);
int ft_printf(const char* str, ...);
int trans_unsigned(int num);
char* hex_char(int nh, char* s, char hextype);
char* long_itoa(long int n);

#endif 