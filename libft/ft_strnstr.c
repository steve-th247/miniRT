/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:43:38 by jyap              #+#    #+#             */
/*   Updated: 2024/03/18 12:11:51 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (s2[0] == 0)
		return ((char *)s1);
	while (s1[i] && i < size)
	{
		while (s1[i + j] && s2[j] && s1[i + j] == s2[j] && (i + j < size))
			j++;
		if (s2[j] == '\0')
			return ((char *)&s1[i]);
		i++;
		j = 0;
	}
	return (0);
}
