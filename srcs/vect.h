/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:57:00 by tjien-ji          #+#    #+#             */
/*   Updated: 2024/09/08 18:32:41 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT_H
# define VECT_H

typedef struct s_vect
{
	double	x;
	double	y;
	double	z;
}	t_vect;

t_vect	vect(double x, double y, double z);
t_vect	*create_vect(double x, double y, double z);
void	delete_vect(t_vect *ptr_vect);

#endif
