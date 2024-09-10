/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:16:20 by jyap              #+#    #+#             */
/*   Updated: 2024/03/18 12:11:24 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t	i;

	i = 0;
	if (dest == src)
		return (NULL);
	if (dest < src)
	{
		while (i < size)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		while (size > 0)
		{
			size--;
			((unsigned char *)dest)[size] = ((unsigned char *)src)[size];
		}
	}
	return (dest);
}
