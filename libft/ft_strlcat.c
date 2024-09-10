/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:32:52 by jyap              #+#    #+#             */
/*   Updated: 2023/11/01 16:43:48 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	i;

	if (!dest || !src)
		return (0);
	if (size <= (size_t)ft_strlen(dest))
		return (size + (size_t)ft_strlen(src));
	dest_len = (size_t)ft_strlen(dest);
	i = 0;
	while ((dest_len < size - 1) && src[i])
		dest[dest_len++] = src[i++];
	dest[dest_len] = '\0';
	return ((size_t)(ft_strlen(dest) + ft_strlen(&src[i])));
}
