/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 07:51:23 by jyap              #+#    #+#             */
/*   Updated: 2024/03/22 16:21:53 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_ullen(unsigned long n)
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

char	*ft_ultoa(unsigned long n)
{
	char	*output;
	int		len;

	len = get_ullen(n);
	output = malloc(sizeof(char) * (len + 1));
	if (output == NULL)
		return (NULL);
	output[len] = '\0';
	if (n == 0)
		output[0] = '0';
	while (n != 0)
	{
		output[len - 1] = "0123456789abcdef"[n % 16];
		n /= 16;
		len --;
	}
	return (output);
}

static t_format	reformat_pointer(t_format f, int len)
{
	if (len > f.pcs)
		f.pcs = len;
	if (f.pcs >= f.width || f.width == 0)
		f.width = f.pcs + 2;
	return (f);
}

static int	ft_print_pointer(t_format f, char *nbr)
{
	int	count;
	int	len;

	count = 0;
	len = (int)ft_strlen(nbr);
	f = reformat_pointer(f, len);
	if (!f.minus && !f.zero)
		count += print_dupe_fd(' ', f.width - 2 - f.pcs, 1);
	count += write(1, "0x", 2);
	if (!f.minus && f.zero && f.dot == 0)
		count += print_dupe_fd('0', f.width - 2 - f.pcs, 1);
	count += print_dupe_fd('0', f.pcs - len, 1);
	count += write(1, nbr, len);
	if (f.minus)
		count += print_dupe_fd(' ', f.width - 2 - f.pcs, 1);
	return (count);
}

int	ft_print_p(t_format f, va_list ap)
{
	char			*nbr;
	unsigned long	n;
	int				count;

	count = 0;
	n = va_arg(ap, unsigned long);
	nbr = ft_ultoa(n);
	if (nbr == NULL)
		return (0);
	count += ft_print_pointer(f, nbr);
	free(nbr);
	return (count);
}
