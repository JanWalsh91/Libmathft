/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_to_rot_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 13:47:18 by jwalsh            #+#    #+#             */
/*   Updated: 2017/02/10 14:03:28 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Calculates a rotation matrix based on two vectors.
*/

t_matrix4 vec3_to_rot_matrix(t_vec3 v1, t_vec3 v2)
{
    t_matrix4    new_matrix;
    t_vec3      tmp;

    new_matrix = new_identity_matrix4();
    tmp = vec3_normalize(v1);
    new_matrix[0][0] = tmp.x;
    new_matrix[0][1] = tmp.y;
    new_matrix[0][2] = tmp.z;
    tmp = vec3_normalize(vec3_cross_product(v1, v2));
    new_matrix[2][0] = tmp.x;
    new_matrix[2][1] = tmp.y;
    new_matrix[2][2] = tmp.z;
    tmp = vec3_normalize(vec3_cross_product(tmp, v1));
    new_matrix[1][0] = tmp.x;
    new_matrix[1][1] = tmp.y;
    new_matrix[1][2] = tmp.z;
    return (new_matrix);
}