/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfischer <cfischer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:50:26 by cfischer          #+#    #+#             */
/*   Updated: 2021/09/13 11:58:01 by cfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	size;

	size = ft_strlen(s1) + 1;
	p = ft_calloc(size, sizeof(char));
	if (p == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(p, s1, size);
	return (p);
}
