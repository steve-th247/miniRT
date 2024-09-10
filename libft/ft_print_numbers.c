/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:11:01 by jyap              #+#    #+#             */
/*   Updated: 2024/03/22 16:21:49 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_format	reformat(t_format f, int *len, int neg, char *nbr)
{
	if ((f.plus || neg) && f.space)
		f.space = 0;
	if (f.dot)
		f.zero = 0;
	if (nbr[0] == '0' && f.dot && f.pcs == 0)
		*len = 0;
	if (*len > f.pcs)
		f.pcs = *len;
	if (f.pcs >= f.width || f.width == 0)
		f.width = f.pcs + neg + f.plus + f.space;
	return (f);
}

static int	ft_print_number(t_format f, char *nbr, int neg)
{
	int	count;
	int	len;
	int	sign_space;

	count = 0;
	len = (int)ft_strlen(nbr);
	f = reformat(f, &len, neg, nbr);
	sign_space = neg + f.plus + f.space;
	if (!f.minus && !f.zero)
		count += print_dupe_fd(' ', f.width - f.pcs - sign_space, 1);
	if (f.space)
		count += write(1, " ", 1);
	if (f.plus && !neg)
		count += write(1, "+", 1);
	if (neg)
		count += write(1, "-", 1);
	if (!f.minus && f.zero && f.dot == 0)
		count += print_dupe_fd('0', f.width - f.pcs - sign_space, 1);
	count += print_dupe_fd('0', f.pcs - len, 1);
	count += write(1, nbr, len);
	if (f.minus)
		count += print_dupe_fd(' ', f.width - f.pcs - sign_space, 1);
	return (count);
}

char	*ft_itoa_min(int n, int *has_malloc)
{
	char	*output;

	if (n != -2147483648)
	{
		output = ft_itoa(n);
		*has_malloc = 1;
	}
	else
		output = "2147483648";
	return (output);
}

int	ft_print_d_i(t_format f, va_list ap, int *count)
{
	char	*nbr;
	int		n;
	int		has_malloc;
	int		neg;

	neg = 0;
	has_malloc = 0;
	n = va_arg(ap, int);
	if (n < 0)
	{
		f.plus = 0;
		if (n != -2147483648)
			n *= -1;
		neg = 1;
	}
	nbr = ft_itoa_min(n, &has_malloc);
	*count += ft_print_number(f, nbr, neg);
	if (has_malloc)
		free(nbr);
	return (*count);
}
