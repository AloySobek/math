/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linearTypes.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:33:32 by vrichese          #+#    #+#             */
/*   Updated: 2019/10/18 20:18:50 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAFLOAT_H
# define LAFLOAT_H

# include <stdlib.h>
# include <math.h>
# include <stdio.h>

typedef enum	basis_e
{
	LA_X,
	LA_Y,
	LA_Z,
	LA_W,
	LA_MAX_DIMENSION,
	LA_2D		= 2,
	LA_3D		= 3,
	LA_4D		= 4
}				basis_t;

typedef	struct	s_vec2
{
	float		data[LA_2D];
}				vec2;

typedef struct	s_vec3
{
	float		data[LA_3D];
}				vec3;

typedef struct	s_fvec4
{
	float		data[LA_4D];
}				vec4;

typedef struct	s_fmat2
{
	float		data[LA_2D][LA_2D];
}				mat2;

typedef struct	s_fmat3
{
	float		data[LA_3D][LA_3D];
}				mat3;

typedef struct	s_fmat4
{
	float		data[LA_4D][LA_4D];
}				mat4;

#endif