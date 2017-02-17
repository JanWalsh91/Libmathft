/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pvec3_matrix4_product.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 11:29:03 by jwalsh            #+#    #+#             */
/*   Updated: 2017/02/17 12:00:31 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Returns the product of matrix m and vector v, with vector v treated as as
** point.
*/

t_vec3	pvec3_matrix4_product(t_vec3 p, t_matrix4 m)
{
	t_vec3	new;

	new.x = (p.x * m[0][0] + p.y * m[1][0] + p.z * m[2][0] + m[0][3]);
	new.y = (p.x * m[0][1] + p.y * m[1][1] + p.z * m[2][1] + m[1][3]);
	new.z = (p.x * m[0][2] + p.y * m[1][2] + p.z * m[2][2] + m[2][3]);
	return (new);
}