/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4_inverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 14:17:03 by jwalsh            #+#    #+#             */
/*   Updated: 2017/02/15 15:43:23 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"
#include <stdio.h>

/*
** Returns the inverse of a matrix if it exists.
*/
// static void	print_matrix(t_matrix4 m);
static void	swap(float *a, float *b);

t_matrix4	matrix4_inverse(t_matrix4 m)
{
	t_matrix4 mat;
	t_pt2 i;
	int big;
	int j;
	// column: y;
	// row: x;
	mat = new_identity_matrix4();
	// printf("new mat:");
	// print_matrix(mat);
	i.y = -1;
    while (++i.y < 4)
	{
        // Swap row in case our pivot point is not working
        if (m[i.y][i.y] == 0)
		{ 
            big = i.y;
			i.x = -1;
            while (++i.x < 4)
                if (fabs(m[i.x][i.y]) > fabs(m[big][i.y]))
					big = i.x; 
            // Print this is a singular matrix, return identity ?
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
        // Set each row in the column to 0 
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
                    // Set the element to 0 for safety
                    m[row][i.y] = 0; 
                } 
				// print_matrix(mat);
            } 
        } 
    } 
	// print_matrix(mat);
    // Set each element of the diagonal to 1
	i.x = -1;
    while (++i.x < 4)
	{ 
		i.y = -1;
        while (++i.y < 4) 
            mat[i.x][i.y] /= m[i.x][i.x];
		// printf("[%f]\n", m[i.x][i.x]);
    }
	// print_matrix(mat);
	return (mat);
}

static void	swap(float *a, float *b)
{
	float tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

// static void	print_matrix(t_matrix4 m)
// {
// 	int i;
// 	int	y;

// 	y = -1;
// 	while (++y < 4)
// 	{
// 		i = -1;
// 		while (++i < 4)
// 			printf("[%f]", m[y][i]);
// 		printf("\n");
// 	}
// 	printf("\n");
// }