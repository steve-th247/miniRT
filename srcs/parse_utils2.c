/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 18:44:49 by jyap              #+#    #+#             */
/*   Updated: 2024/09/15 16:36:29 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

bool	is_float(char *str)
{
	bool	dot_found;
	int		i;

	i = 0;
	dot_found = false;
	if (str[0] == '+' || str[0] == '-')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (false);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else if (str[i] == '.' && dot_found == false)
		{
			dot_found = true;
			i++;
			if (!(str[i] >= '0' && str[i] <= '9'))
				return (false);
		}
		else
			return (false);
	}
	return (true);
}

bool	is_range(double number)
{
	if (number >= -1 && number <= 1)
		return (true);
	return (false);
}

bool	is_color(char *str)
{
	int	i;
	int	color;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	color = ft_atoi(str);
	if (color >= 0 && color <= 255)
		return (true);
	return (false);
}

float	str_to_float(char *str)
{
	float	sum;
	float	prec;
	float	div;
	float	sign;

	prec = 0.0;
	div = 1.0;
	sign = 1.0;
	if (str && str[0] == '-')
		sign *= -1.0;
	sum = (float)ft_atoi(str);
	while (*str && *str != '.')
		str++;
	if (*str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9')
		{
			div *= 10.0;
			prec += (*str - '0') / div;
			str++;
		}
		sum += prec * sign;
	}
	return (sum);
}
