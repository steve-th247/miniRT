/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:10:48 by jyap              #+#    #+#             */
/*   Updated: 2024/03/22 16:21:17 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_format	ft_newformat(void)
{
	t_format	new_format;

	new_format.minus = 0;
	new_format.plus = 0;
	new_format.width = 0;
	new_format.pcs = 0;
	new_format.specifier = 0;
	new_format.zero = 0;
	new_format.dot = 0;
	new_format.space = 0;
	new_format.sharp = 0;
	new_format.neg_pcs = 0;
	return (new_format);
}
