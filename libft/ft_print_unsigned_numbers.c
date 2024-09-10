/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_numbers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 07:51:14 by jyap              #+#    #+#             */
/*   Updated: 2024/03/22 16:21:58 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_uilen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*ft_uitoa(unsigned int n)
{
	char	*output;
	int		len;

	len = get_uilen(n);
	output = malloc(sizeof(char) * (len + 1));
	if (output == NULL)
		return (NULL);
	output[len] = '\0';
	if (n == 0)
		output[0] = '0';
	while (n != 0)
	{
		output[len - 1] = (n % 10) + '0';
		n /= 10;
		len --;
	}
	return (output);
}

static t_format	reformat_unsigned_number(t_format f, int *len, char *nbr)
{
	if (f.plus && f.space)
		f.space = 0;
	if (f.dot)
		f.zero = 0;
	if (nbr[0] == '0' && f.dot && f.pcs == 0)
		*len = 0;
	if (*len > f.pcs)
		f.pcs = *len;
	if (f.pcs >= f.width || f.width == 0)
		f.width = f.pcs + f.plus + f.space;
	return (f);
}

static int	ft_print_unsigned_number(t_format f, char *nbr)
{
	int	count;
	int	len;

	count = 0;
	len = (int)ft_strlen(nbr);
	f = reformat_unsigned_number(f, &len, nbr);
	if (!f.minus && !f.zero)
		count += print_dupe_fd(' ', f.width - f.pcs - f.plus - f.space, 1);
	if (f.space)
		count += write(1, " ", 1);
	if (f.plus)
		count += write(1, "+", 1);
	if (!f.minus && f.zero && f.dot == 0)
		count += print_dupe_fd('0', f.width - f.pcs - f.plus - f.space, 1);
	count += print_dupe_fd('0', f.pcs - len, 1);
	count += write(1, nbr, len);
	if (f.minus)
		count += print_dupe_fd(' ', f.width - f.pcs - f.plus - f.space, 1);
	return (count);
}

int	ft_print_u(t_format f, va_list ap)
{
	char	*nbr;
	int		n;
	int		count;

	count = 0;
	n = va_arg(ap, unsigned int);
	nbr = ft_uitoa(n);
	if (nbr == NULL)
		return (0);
	count += ft_print_unsigned_number(f, nbr);
	free(nbr);
	return (count);
}
