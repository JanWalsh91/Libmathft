/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_inverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 14:17:03 by jwalsh            #+#    #+#             */
/*   Updated: 2017/02/15 15:43:23 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libmathft.h"
#include <stdio.h>

/*
** Returns the inverse of a matrix if it exists.
*/

static void	swap(double *a, double *b);

t_matrix	m_inverse(t_matrix m)
{
	t_matrix	mat;
	t_pt2		i;
	int			big;
	int			j;

	mat = m_new_identity();
	i.y = -1;
    while (++i.y < 4)
	{
        if (m[i.y][i.y] == 0)
		{ 
            big = i.y;
			i.x = -1;
            while (++i.x < 4)
                if (fabs(m[i.x][i.y]) > fabs(m[big][i.y]))
					big = i.x; 
            if (big == i.y)
				return (NULL);
            else
			{	
				j = -1;
				while (++j < 4)
				{
					swap(&m[i.y][j], &m[big][j]); 
               		swap(&mat[i.y][j], &mat[big][j]); 
				}
            } 
        } 
		int row = -1;
        while (++row < 4)
		{ 
            if (row != i.y)
			{ 
                double coeff = m[row][i.y] / m[i.y][i.y]; 
                if (coeff != 0)
				{
					j = -1; 
                    while (++j < 4)
					{ 
                        m[row][j] -= coeff * m[i.y][j]; 
                        mat[row][j] -= coeff * mat[i.y][j]; 
                    } 
                    m[row][i.y] = 0; 
                } 
            } 
        } 
    } 
	i.x = -1;
    while (++i.x < 4)
	{ 
		i.y = -1;
        while (++i.y < 4) 
            mat[i.x][i.y] /= m[i.x][i.x];
    }
	return (mat);
}

static void	swap(double *a, double *b)
{
	double	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}