/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 08:20:03 by jyap              #+#    #+#             */
/*   Updated: 2023/10/19 08:34:53 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned int	ft_number_size(int number)
{
	unsigned int	len;

	len = 0;
	if (number == 0)
		return (1);
	if (number < 0)
	{
		len++;
	}
	while (number != 0)
	{
		number /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int i)
{
	char			*str;
	unsigned int	number;
	unsigned int	len;

	len = ft_number_size(i);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (i < 0)
	{
		str[0] = '-';
		number = -i;
	}
	else
		number = i;
	if (i == 0)
		str[0] = '0';
	str[len] = '\0';
	while (number != 0)
	{
		str[len - 1] = (number % 10) + '0';
		number /= 10;
		len--;
	}
	return (str);
}
