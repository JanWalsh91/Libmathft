/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_abs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 16:56:06 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/31 16:57:17 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Gets the absolute value of complex number x and returns the result.
*/

t_complex	c_abs(t_complex x)
{
	x.r = ft_abs(x.r);
	x.i = ft_abs(x.i);
	return (x);
}
