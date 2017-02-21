/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_to_rot_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 13:47:18 by jwalsh            #+#    #+#             */
/*   Updated: 2017/02/21 12:02:55 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

static void	print_vec(t_vec3 vec);


/*
** Calculates a rotation matrix to transform vector v1 into vector v2.
*/

t_matrix4 vec3_to_rot_matrix(t_vec3 v1, t_vec3 v2)
{
    t_vec3      xaxis;
    t_vec3      yaxis;
    t_matrix4   m;
    
	m = new_identity_matrix4();
	xaxis = vec3_cross_product(v1, v2);
	xaxis = vec3_normalize(xaxis);
	yaxis = vec3_cross_product(v2, xaxis);
	yaxis = vec3_normalize(yaxis);
	if (!xaxis.x && !xaxis.y && !xaxis.z &&
		!yaxis.x && !yaxis.y && !yaxis.z)
		return (m);
	m[0][0] = yaxis.x;
	m[0][1] = xaxis.x;
	m[0][2] = v1.x;
	m[1][0] = -yaxis.y;
	m[1][1] = -xaxis.y;
	m[1][2] = v1.y;
	m[2][0] = yaxis.z;
	m[2][1] = xaxis.z;
	m[2][2] = v1.z;
    return (m);
}