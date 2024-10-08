/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:55:45 by jyap              #+#    #+#             */
/*   Updated: 2024/09/16 17:04:41 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "light.h"
# include "camera.h"
# include "obj.h"

typedef struct s_scene
{
	t_amb		amb;
	t_camera	cam;
	t_light		light;
	t_obj		*obj;
}	t_scene;

#endif