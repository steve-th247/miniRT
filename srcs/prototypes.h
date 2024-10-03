/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:09:38 by jyap              #+#    #+#             */
/*   Updated: 2024/09/24 09:33:03 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "mlx_structs.h"
# include "camera.h"
# include "color.h"
# include "cylinder.h"
# include "sphere.h"
# include "plane.h"
# include "light.h"
# include "ray.h"
# include "scene.h"
# include "vect.h"
# include "obj.h"
# include "intersect.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <stdbool.h>

# define WIN_W 500
# define WIN_H 500

# define LEFT_MOUSE_BUTTON 1
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

int				render(t_mlxs *mlxs);

void			print_err_exit(char *msg, t_mlxs **mlxs, char *ptr);
void			arr_exit(char *msg, t_mlxs **mlxs, char **ptr,
					char *ptr1);
void			print_err(char *msg, void *ptr);

void			parse(char *name, t_mlxs *mlxs);

void			free_scene(t_scene *sc);
void			free_str_arr(char **arr);

void			parse_amb(char *line, t_mlxs *mlxs);
void			parse_light(char *line, t_mlxs *mlxs);
void			parse_camera(char *line, t_mlxs *mlxs);

int				count_arr_elements(char **arr);

float			parse_ratio(char **str, int i, char *line, t_mlxs *mlxs);
t_color			parse_color(char **str, int i, char *line, t_mlxs *mlxs);
t_vect			parse_coord(char **str, int i, char *line, t_mlxs *mlxs);
t_vect			parse_vector(char **str, int i, char *line, t_mlxs *mlxs);
unsigned char	parse_camera_fov(char **str, int i, char *line, t_mlxs *mlxs);
double			parse_dia_height(char **str, int i, char *line, t_mlxs *mlxs);

bool			is_float(char *str);
bool			is_range(double number);
bool			is_color(char *str);
float			str_to_float(char *str);

void			parse_light(char *line, t_mlxs *mlxs);
void			parse_camera(char *line, t_mlxs *mlxs);
void			parse_amb(char *line, t_mlxs *mlxs);
void			parse_obj(char *line, t_mlxs *mlxs, t_obj_type type);
void			parse_obj_plane(t_obj *new_obj, char *line, t_mlxs *mlxs);
void			parse_obj_sphere(t_obj *new_obj, char *line, t_mlxs *mlxs);
void			parse_obj_cylinder(t_obj *new_obj, char *line, t_mlxs *mlxs);

void			free_two_str_arr(char **arr1, char **arr2);

void			free_all(t_mlxs *mlxs);

void			parse_plane(char *line, t_mlxs *mlxs, t_obj *new_obj);
void			parse_sphere(char *line, t_mlxs *mlxs, t_obj *new_obj);
void			parse_cylinder(char *line, t_mlxs *mlxs, t_obj *new_obj);

double			solve_quadratic(double a, double b, double c);

t_color			get_pixel_color(t_inter *inter);

void			launch_rays_from_camera(t_mlxs *mlxs);

bool			is_closest(t_inter *closest, t_inter temp);
void			closest_inter(t_mlxs *mlxs, t_ray *ray);

t_inter			intersect_plane(t_ray *ray, t_plane *plane);
t_inter			intersect_sphere(t_ray *ray, t_sphere *sphere);
t_inter			intersect_cylinder(t_ray *ray, t_cylinder *cylinder);

bool			is_intersection_valid(t_ray *ray, t_cylinder *cy, double t);
t_vect			cylinder_normal(t_vect P, t_cylinder *cylinder);
int				quad_cylinder(t_ray *ray, t_inter *inter,
					t_cylinder *cylinder, t_vect X);

void			object_add_end(t_obj **lst, t_obj *new);

t_vect			parse_vector_sub(char **arr, char **split, char *line,
					t_mlxs *mlxs);

t_color			color_ambient(const t_mlxs *mlxs);
t_color			color_diffuse(t_mlxs *mlxs, t_inter *inter);

void			init_mlx(t_mlxs *mlxs);
void			set_img_pixel_color(t_image img, int x, int y, int color);
void			init_mlx_hook(t_mlxs *mlxs);

int				mouse_hook_callback(int button, int x, int y, void *param);
int				kb_hook_callback(int keycode, void *param);

void			mouse_event_handler_resize_obj(int button, t_mlxs *mlxs);
void			kb_event_handler_transform_obj(int keycode, t_mlxs *mlxs);
void			kb_event_handler_rotate_obj(int keycode, t_mlxs *mlxs);
void			kb_event_handler_translate_obj(int keycode, t_mlxs *mlxs);
void			kb_event_handler_resize_obj(int keycode, t_mlxs *mlxs);

void			kb_event_handler_transform_cam(int keycode, t_mlxs *mlxs);
void			kb_event_handler_rotate_cam(int keycode, t_mlxs *mlxs);
void			kb_event_handler_translate_cam(int keycode, t_mlxs *mlxs);
void			kb_event_handler_zoom_cam(int keycode, t_mlxs *mlxs);

void			kb_event_handler_adjust_light(int keycode, t_mlxs *mlxs);
void			kb_event_handler_adjust_light_ratio(int keycode, t_mlxs *mlxs);
void			kb_event_handler_translate_light(int keycode, t_mlxs *mlxs);

#endif
