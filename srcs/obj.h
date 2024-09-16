/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:44:40 by jyap              #+#    #+#             */
/*   Updated: 2024/09/16 17:08:55 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_H
# define OBJ_H

typedef enum e_obj_type
{
	PLANE = 1,
	SPHERE = 2,
	CYLINDER = 3
}	t_obj_type;

typedef struct s_obj
{
	int					i;
	t_obj_type			type;
	void				*obj_ptr;
	struct s_obj		*next;
}	t_obj;

#endif
