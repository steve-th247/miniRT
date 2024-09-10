/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 08:36:41 by jyap              #+#    #+#             */
/*   Updated: 2023/11/01 13:50:39 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *str, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*string;

	i = 0;
	if (!str)
		return (NULL);
	string = malloc(sizeof(*string) * (ft_strlen(str) + 1));
	if (!string)
		return (NULL);
	while (str[i])
	{
		string[i] = f(i, str[i]);
		i++;
	}
	string[i] = '\0';
	return (string);
}
