/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:04:58 by jyap              #+#    #+#             */
/*   Updated: 2023/11/01 17:13:27 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *str, int i)
{
	int	j;

	j = 0;
	while (str[j])
		j++;
	while (j >= 0)
	{
		if ((unsigned char)str[j] == (unsigned char)i)
			return ((char *)&str[j]);
		j--;
	}
	return ((char *) NULL);
}
