/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:22:05 by jyap              #+#    #+#             */
/*   Updated: 2023/11/01 17:03:57 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *str, int i)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if ((unsigned char)str[j] == (unsigned char)i)
			return ((char *)&str[j]);
		j++;
	}
	if (i == '\0')
		return ((char *)&str[j]);
	return (NULL);
}
