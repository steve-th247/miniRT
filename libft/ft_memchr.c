/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:43:32 by jyap              #+#    #+#             */
/*   Updated: 2023/10/17 16:53:06 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int i, size_t size)
{
	unsigned char	*str;
	size_t			j;

	j = 0;
	str = (unsigned char *)s;
	while (j < size)
	{
		if (str[j] == (unsigned char)i)
			return (&str[j]);
		j++;
	}
	return (NULL);
}
