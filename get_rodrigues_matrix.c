/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rodrigues_matrix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:06:30 by jwalsh            #+#    #+#             */
/*   Updated: 2017/02/13 16:48:56 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

t_matrix4   get_rodrigues_matrix(t_vec3 a, t_vec3 b)
{
    t_matrix4   m;
    t_matrix4   n;
    t_vec3      v;  
    double      angle;
    int         i;

    //calculate the vector orthgonal to a and b around which id the rotation. 
    v = vec3_normalize(vec3_cross_product(a, b));
    angle = acos(vec3_dot(a, b) / ((vec3_length(a) * vec3_length(b))));
    n = new_identity_matrix4();
    n[1][0] = v.z;
    n[2][0] = -v.y;
    n[0][1] = -v.z;
    n[2][1] = v.x;
    n[0][2] = v.y;
    n[1][2] = -v.x;
    m = new_identity_matrix4();
    m = matrix4_add(matrix4_scale(n, sin(angle)), m);
    m = matrix4_add(m, matrix4_scale(matrix4_product(n, n), 1 - cos(angle)));
    i = -1;
    while (i < 3)
    {
        m[3][i] = 0;
        m[i][3] = 0;
    }
    m[3][3] = 1;
    return (m);
}