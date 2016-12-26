/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmathft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 15:36:18 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/26 14:03:52 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMATHFT_H
# define LIBMATHFT_H

# include <math.h>
# include <stdlib.h>

typedef struct	s_pt2
{
	int			x;
	int			y;
}				t_pt2;

typedef struct	s_vec2
{
	float		x;
	float		y;
}				t_vec2;

typedef struct	s_vec3
{
	float		x;
	float		y;
	float		z;
}				t_vec3;

typedef float	**t_matrix4;

double			to_radian(double a);
int				ft_round(float i);
int				ft_rgb_mix(int *colors, int n);

/*
** 3 x 3 Vector functions
*/

float			vec3_dot(t_vec3 vec1, t_vec3 vec2);
float			vec3_length(t_vec3 vec);
t_vec3			vec3_normalize(t_vec3 vec);
t_vec3			vec3_cross_product(t_vec3 vec1, t_vec3 vec2);
t_vec3			vec3_add(t_vec3 vec1, t_vec3 vec2);
t_vec3			vec3_subtract(t_vec3 vec1, t_vec3 vec2);
t_vec3			vec3_product(t_vec3 vec1, float i);
t_vec3			vec3_translate(t_vec2 vec, t_vec3 i);
t_vec3			vec3_scale(t_vec3 vec, t_vec3 i);
t_vec3			vec3_matrix4_product(t_vec3 p, t_matrix4 m);

/*
** 4 x 4 Matrix functions
*/

t_matrix4		new_matrix4(void);
t_matrix4		new_identity_matrix4(void);
t_matrix4		new_scaling_matrix4(float i);
t_matrix4		matrix4_product(t_matrix4 m1, t_matrix4 m2);
t_matrix4		new_rotation_matrix4(float angle, char axis);
t_matrix4		matrix4_translation(t_matrix4 m, t_vec3 v);

#endif
