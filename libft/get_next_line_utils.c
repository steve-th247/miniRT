/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:11:46 by jyap              #+#    #+#             */
/*   Updated: 2024/03/22 16:25:54 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	checkend(char c)
{
	return (c != '\n' && c != '\0');
}

char	*ft_strcomb(char *dst, char *src)
{
	int		i;
	int		j;
	char	*output;

	if (dst == NULL)
	{
		dst = malloc(sizeof(char));
		if (!dst || !src)
			return (NULL);
		dst[0] = '\0';
	}
	output = malloc (sizeof(*output) * (ft_strlen(dst) + ft_strlen(src) + 1));
	if (!output)
		return (NULL);
	i = -1;
	while (dst[++i])
		output[i] = dst[i];
	j = 0;
	while (src[j])
		output[i++] = src[j++];
	output[ft_strlen(dst) + ft_strlen(src)] = '\0';
	free(dst);
	return (output);
}
