/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:30:41 by jyap              #+#    #+#             */
/*   Updated: 2023/11/01 14:04:06 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, unsigned int start, size_t size)
{
	size_t	i;
	size_t	j;
	char	*output;

	if (!str)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(str))
		output = malloc(1);
	else if ((unsigned int)size >= (unsigned int)ft_strlen(str) - start)
		output = malloc(sizeof(*str) * (ft_strlen(str) - start + 1));
	else
		output = malloc(sizeof(*str) * (size + 1));
	if (output == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < (size_t)start)
		i++;
	while (j < size && i < (size_t)ft_strlen(str))
		output[j++] = str[i++];
	output[j] = '\0';
	return (output);
}
