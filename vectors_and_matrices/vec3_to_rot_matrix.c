/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_to_rot_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 13:47:18 by jwalsh            #+#    #+#             */
/*   Updated: 2017/02/18 12:03:48 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Calculates a rotation matrix to transform vector v1 into vector v2.
*/

t_matrix4 vec3_to_rot_matrix(t_vec3 v1, t_vec3 v2)
{
    t_vec3      xaxis;
    t_vec3      yaxis;
    t_matrix4   m;
    
	xaxis = vec3_cross_product(v1, v2);
	xaxis = vec3_normalize(xaxis);

	yaxis = vec3_cross_product(v2, xaxis);
	yaxis = vec3_normalize(yaxis);
	m = new_identity_matrix4();

	m[0][0] = xaxis.x;
	m[1][0] = yaxis.x;
	m[2][0] = v1.x;
	m[0][1] = xaxis.y;
	m[1][1] = yaxis.y;
	m[2][1] = v1.y;
	m[0][2] = xaxis.z;
	m[1][2] = yaxis.z;
	m[2][2] = v1.z;
    return (m);
}