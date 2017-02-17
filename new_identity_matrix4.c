/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_identity_matrix4.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 17:09:44 by jwalsh            #+#    #+#             */
/*   Updated: 2017/02/17 12:01:24 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Creates a new 4 by 4 identity matrix.
** Mulpitplying a matrix by an identity matrix does not modify it.
*/

t_matrix4	new_identity_matrix4(void)
{
	t_matrix4	m;

	m = new_matrix4();
	m[0][0] = 1;
	m[1][1] = 1;
	m[2][2] = 1;
	m[3][3] = 1;
	return (m);
}
