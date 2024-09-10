/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:10:58 by jyap              #+#    #+#             */
/*   Updated: 2024/03/22 16:21:45 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_uilen_base16(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

char	*ft_uitoa_base(unsigned int n, char *base)
{
	char	*output;
	int		len;

	len = get_uilen_base16(n);
	output = malloc(sizeof(char) * (len + 1));
	if (output == NULL)
		return (NULL);
	output[len] = '\0';
	if (n == 0)
		output[0] = '0';
	while (n != 0)
	{
		output[len - 1] = base[(n % 16)];
		n /= 16;
		len --;
	}
	return (output);
}

static t_format	reformat_hexa(t_format f, int *len, char *nbr)
{
	if (f.plus && f.space)
		f.space = 0;
	if (f.dot)
		f.zero = 0;
	if (nbr[0] == '0' && f.dot && f.pcs == 0)
		*len = 0;
	if (nbr[0] == '0')
		f.sharp = 0;
	if (*len > f.pcs)
		f.pcs = *len;
	if (f.pcs >= f.width || f.width == 0)
		f.width = f.pcs + f.plus + f.space + 2 * f.sharp;
	return (f);
}

int	ft_print_hexa(t_format f, char *nbr)
{
	int	count;
	int	len;

	count = 0;
	len = (int)ft_strlen(nbr);
	f = reformat_hexa(f, &len, nbr);
	if (!f.minus && !f.zero)
		count += print_dupe_fd(' ', f.width - f.sharp * 2 - f.pcs, 1);
	if (f.sharp && f.specifier == 'X')
		count += write(1, "0X", 2);
	else if (f.sharp && f.specifier == 'x')
		count += write(1, "0x", 2);
	if (!f.minus && f.zero && f.dot == 0)
		count += print_dupe_fd('0', f.width - f.sharp * 2 - f.pcs, 1);
	count += print_dupe_fd('0', f.pcs - len, 1);
	count += write(1, nbr, len);
	if (f.minus)
		count += print_dupe_fd(' ', f.width - f. sharp * 2 - f.pcs, 1);
	return (count);
}

int	ft_print_x(t_format f, va_list ap)
{
	char				*nbr;
	unsigned int		n;
	int					count;
	char				*base;

	count = 0;
	n = va_arg(ap, unsigned int);
	base = NULL;
	if (f.specifier == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	nbr = ft_uitoa_base(n, base);
	if (nbr == NULL)
		return (0);
	count += ft_print_hexa(f, nbr);
	free(nbr);
	return (count);
}
