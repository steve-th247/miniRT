/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:57:24 by jyap              #+#    #+#             */
/*   Updated: 2024/09/16 17:04:20 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_STRUCTS_H
# define MLX_STRUCTS_H
# include "scene.h"

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_mlxs
{
	void	*mlx;
	void	*mlx_win;
	t_image	img;
	t_scene	*sc;
	t_obj	*new_obj;
}	t_mlxs;

#endif