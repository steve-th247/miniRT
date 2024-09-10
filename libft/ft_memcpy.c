/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:06:06 by jyap              #+#    #+#             */
/*   Updated: 2023/11/01 09:42:14 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t	i;
	char	*d;
	char	*s;

	i = 0;
	if (dest == src)
		return (NULL);
	d = (char *)dest;
	s = (char *)src;
	while (i < size)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
