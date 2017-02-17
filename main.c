/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 14:56:42 by jwalsh            #+#    #+#             */
/*   Updated: 2017/02/15 15:52:30 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"
#include <stdio.h>

static void	print_matrix(t_matrix4 m);
static void	print_vec(t_vec3 v);

int main(void)
{
	t_matrix4 m1;
	t_matrix4 m2;
	t_vec3		v;

	v.x = 10;
	v.y = 20;
	v.z = 30;

	m1 = new_identity_matrix4();
	m1[0][0] = 10;
	m1[0][1] = 0;
	m1[0][2] = -0;
	m1[0][3] = 5;
	m1[1][0] = 6;
	m1[1][1] = -5;
	m1[1][2] = -4;
	m1[1][3] = 8;
	m1[2][0] = 2;
	m1[2][1] = 6;
	m1[2][2] = 1;
	m1[2][3] = -55;
	m1[3][0] = -9;
	m1[3][1] = 9;
	m1[3][2] = 0;
	m1[3][3] = 8;
	print_vec(v);
	v = vec3_matrix4_product(v, m1);
	m2 = matrix4_inverse(m1);
	print_vec(v);
	v = vec3_matrix4_product(v, m2);
	print_vec(v);
	print_matrix(m2);
	return (0);
}

static void	print_matrix(t_matrix4 m)
{
	int i;
	int	y;

	y = -1;
	while (++y < 4)
	{
		i = -1;
		while (++i < 4)
			printf("[%f]", m[y][i]);
		printf("\n");
	}
}

static void	print_vec(t_vec3 v)
{
	printf("[%f][%f][%f]\n", v.x, v.y, v.z);
}