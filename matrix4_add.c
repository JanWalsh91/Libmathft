/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:31:16 by jwalsh            #+#    #+#             */
/*   Updated: 2017/02/13 16:34:15 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
**
*/

t_matrix4   matrix4_add(t_matrix4 m1, t_matrix4 m2)
{ 
    int y;
    int x;
    t_matrix4 m;

    m = new_identity_matrix4();
    y = -1;
    while (++y < 3)
    {
        x = -1;
        while (++x < 3)
            m[y][x] = m1[y][x] + m2[y][x];
    }
    return (m);
}