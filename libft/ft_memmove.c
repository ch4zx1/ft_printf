/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfischer <cfischer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 15:46:24 by cfischer          #+#    #+#             */
/*   Updated: 2021/09/07 14:48:51 by cfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t n)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)source;
	if (s < d)
	{
		while (n--)
		{
			d[n] = s[n];
		}
		return (dest);
	}
	else
	{
		ft_memcpy(d, s, n);
	}
	return (dest);
}
