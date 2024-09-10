/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 08:49:40 by jyap              #+#    #+#             */
/*   Updated: 2023/11/01 13:48:08 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int i, int fd)
{
	if (i == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (i < 0)
	{
		ft_putchar_fd('-', fd);
		i = -i;
		ft_putnbr_fd(i, fd);
	}
	else if (i >= 10)
	{
		ft_putnbr_fd(i / 10, fd);
		ft_putnbr_fd(i % 10, fd);
	}
	else
		ft_putchar_fd((i + '0'), fd);
}
