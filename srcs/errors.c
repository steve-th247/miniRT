/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:09:42 by jyap              #+#    #+#             */
/*   Updated: 2024/09/15 13:40:00 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	print_err(char *msg, void *ptr)
{
	ft_putstr_fd(msg, 2);
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	print_err_exit(char *msg, t_mlxs **mlxs, char *ptr)
{
	ft_putstr_fd(msg, 2);
	if (mlxs == NULL || *mlxs == NULL)
		exit(1);
	free_all(*mlxs);
	*mlxs = NULL;
	if (ptr != NULL)
		free(ptr);
	exit (1);
}

