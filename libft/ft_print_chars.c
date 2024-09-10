/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:10:55 by jyap              #+#    #+#             */
/*   Updated: 2024/03/22 16:21:41 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_dupe_fd(char c, int n, int fd)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		count += write (fd, &c, 1);
		n--;
	}
	return (count);
}

int	print_stringn_fd(char *str, int n, int fd)
{
	int	count;

	count = 0;
	while (n > 0 && *str)
	{
		count += write(fd, str, 1);
		str++;
		n--;
	}
	return (count);
}

int	ft_print_c_pct(t_format f, va_list ap)
{
	char	c;
	int		count;

	count = 0;
	if (f.specifier == 'c')
		c = va_arg(ap, int);
	else
		c = '%';
	f.pcs = 1;
	if (!f.minus && f.zero)
		count += print_dupe_fd('0', f.width - f.pcs, 1);
	else if (!f.minus && f.width > f.pcs)
		count += print_dupe_fd(' ', f.width - f.pcs, 1);
	count += write(1, &c, 1);
	if (f.minus && f.width > f.pcs)
		count += print_dupe_fd(' ', f.width - f.pcs, 1);
	return (count);
}

int	ft_print_s(t_format f, va_list ap)
{
	char	*str;
	int		count;

	count = 0;
	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	if (!f.dot || f.pcs > (int)ft_strlen(str) || f.pcs < 0)
		f.pcs = (int)ft_strlen(str);
	if (!f.minus && f.width > f.pcs && f.zero && (!f.dot || f.neg_pcs))
		count += print_dupe_fd('0', f.width - f.pcs, 1);
	else if (!f.minus && f.width > f.pcs)
		count += print_dupe_fd(' ', f.width - f.pcs, 1);
	count += print_stringn_fd(str, f.pcs, 1);
	if (f.minus && f.width > f.pcs)
		count += print_dupe_fd(' ', f.width - f.pcs, 1);
	return (count);
}
