/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4_scale.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:24:38 by jwalsh            #+#    #+#             */
/*   Updated: 2017/02/13 16:32:36 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Scales a matrix.
*/

t_matrix4   matrix4_scale(t_matrix4 m, double i)
{
    int  x;
    int  y;

    y = -1;
    while (++y < 4)
    {
        x = -1;
        while (++x < 4)
            m[y][x] *= i;
    }
    return (m);
}