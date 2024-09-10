/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:10:51 by jyap              #+#    #+#             */
/*   Updated: 2024/03/22 16:21:32 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_format	ft_parse_bonus(char *str, t_format f)
{
	while (*str != '.' && !ft_strchr(SPECIFIERS, *str))
	{
		if (*str == '+')
			f.plus = 1;
		if (*str == ' ')
			f.space = 1;
		if (*str == '#')
			f.sharp = 1;
		str++;
	}
	return (f);
}

static t_format	ft_parse_width(char *str, t_format f)
{
	int	got_width;

	got_width = 0;
	while (*str != '.' && !ft_strchr(SPECIFIERS, *str))
	{
		if (*str == '-')
			f.minus = 1;
		if (*str == '0' && !ft_isdigit(*(str - 1)))
			f.zero = 1;
		if ((*str > '0' && *str <= '9') && !got_width)
		{
			f.width = ft_atoi(str);
			got_width = 1;
		}
		str++;
	}
	return (f);
}

static t_format	ft_parse_precision(char *str, t_format f)
{
	int	got_precision;

	got_precision = 0;
	while (!ft_strchr(SPECIFIERS, *str))
	{
		if (ft_isdigit(*str) && !got_precision)
		{
			f.pcs = ft_atoi(str);
			got_precision = 1;
		}
		str++;
	}
	return (f);
}

int	ft_parse(char *str, va_list ap)
{
	t_format	new_format;

	new_format = ft_parse_width(str, ft_newformat());
	new_format = ft_parse_bonus(str, new_format);
	while (!ft_strchr(SPECIFIERS, *str) && *str != '.')
		str++;
	if (*str == '.' && !new_format.specifier)
	{
		new_format.dot = 1;
		new_format = ft_parse_precision(str++, new_format);
		while (!ft_strchr(SPECIFIERS, *str))
			str++;
	}
	new_format.specifier = *str;
	new_format.neg_pcs = new_format.pcs < 0;
	return (ft_print_format(new_format, ap));
}
