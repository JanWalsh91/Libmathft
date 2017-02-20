/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4_inverse3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 15:32:40 by jwalsh            #+#    #+#             */
/*   Updated: 2017/02/15 15:51:07 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

t_matrix4	matrix4_inverse(t_matrix4 t)
{
	int i, j, k; 
    t_matrix4 s;  
 
	s = new_identity_matrix4();
        // Forward elimination
        for (i = 0; i < 3 ; i++) { 
            int pivot = i; 
 
            float pivotsize = t[i][i]; 
 
            if (pivotsize < 0) 
                pivotsize = -pivotsize; 
 
                for (j = i + 1; j < 4; j++) { 
                    float tmp = t[j][i]; 
 
                    if (tmp < 0) 
                        tmp = -tmp; 
 
                        if (tmp > pivotsize) { 
                            pivot = j; 
                            pivotsize = tmp; 
                        } 
                } 
 
            if (pivotsize == 0) { 
                // Cannot invert singular matrix
                return (NULL); 
            } 
 
            if (pivot != i) { 
                for (j = 0; j < 4; j++) { 
                    float tmp; 
 
                    tmp = t[i][j]; 
                    t[i][j] = t[pivot][j]; 
                    t[pivot][j] = tmp; 
 
                    tmp = s[i][j]; 
                    s[i][j] = s[pivot][j]; 
                    s[pivot][j] = tmp; 
                } 
            } 
 
            for (j = i + 1; j < 4; j++) { 
                float f = t[j][i] / t[i][i]; 
 
                for (k = 0; k < 4; k++) { 
                    t[j][k] -= f * t[i][k]; 
                    s[j][k] -= f * s[i][k]; 
                } 
            } 
        } 
 
        // Backward substitution
        for (i = 3; i >= 0; --i) { 
            float f; 
 
            if ((f = t[i][i]) == 0) { 
                // Cannot invert singular matrix
                return (NULL); 
            } 
 
            for (j = 0; j < 4; j++) { 
                t[i][j] /= f; 
                s[i][j] /= f; 
            } 
 
            for (j = 0; j < i; j++) { 
                f = t[j][i]; 
 
                for (k = 0; k < 4; k++) { 
                    t[j][k] -= f * t[i][k]; 
                    s[j][k] -= f * s[i][k]; 
                } 
            } 
        } 
 
        return s; 
    } 