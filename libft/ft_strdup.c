/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:18:18 by jyap              #+#    #+#             */
/*   Updated: 2023/11/01 11:15:47 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	int		j;
	char	*str1;

	if (!str)
		return (NULL);
	i = 0;
	j = ft_strlen(str);
	str1 = malloc(sizeof(*str1) * (j + 1));
	if (!str1)
		return (NULL);
	while (i < j)
	{
		str1[i] = str[i];
		i++;
	}
	str1[i] = '\0';
	return (str1);
}
