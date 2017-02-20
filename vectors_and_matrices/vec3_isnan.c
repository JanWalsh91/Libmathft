/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_isnan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 14:16:54 by jwalsh            #+#    #+#             */
/*   Updated: 2017/02/13 14:23:29 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Checks if a vector's coordinates are numbers.
** Returns 1 if all coords are NAN.
*/

int vec3_isnan(t_vec3 v)
{
    return (isnan(v.x) && isnan(v.y) && isnan(v.z));
}