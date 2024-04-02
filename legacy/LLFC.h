/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LLFC.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:50:45 by vrichese          #+#    #+#             */
/*   Updated: 2019/10/20 20:25:23 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LLFC_H
# define LLFC_H

#include "linearTypes.h"

vec2	laInit2DVector(vec2 *pSourceVector, float x, float y, float *pInitArray);
vec3	laInit3DVector(vec3 *pSourceVector, float x, float y, float z, float *pInitArray);
vec4	laInit4DVector(vec4 *pSourceVector, float x, float y, float z, float w, float *pInitArray);

vec2	laAdd2DVectors(vec2 *leftOperand, vec2 *rightOperand, vec2 *resultVector);
vec3	laAdd3DVectors(vec3 *leftOperand, vec3 *rightOperand, vec3 *resultVector);
vec4	laAdd4DVectors(vec4 *leftOperand, vec4 *rightOperand, vec4 *resultVector);

vec2	laSub2DVectors(vec2 *leftOperand, vec2 *rightOperand, vec2 *resultVector);
vec3	laSub3DVectors(vec3 *leftOperand, vec3 *rightOperand, vec3 *resultVector);
vec4	laSub4DVectors(vec4 *leftOperand, vec4 *rightOperand, vec4 *resultVector);

float	laGetMagnitude2DVector(vec2 *pSourceVector, float *pResult);
float	laGetMagnitude3DVector(vec3 *pSourceVector, float *pResult);
float	laGetMagnitude4DVector(vec4 *pSourceVector, float *pResult);

vec2	laNormalize2DVector(vec2 *pSourceVector, vec2 *pResultVector);
vec3	laNormalize3DVector(vec3 *pSourceVector, vec3 *pResultVector);
vec4	laNormalize4DVector(vec4 *pSourceVector, vec4 *pResultVector);

vec2	laOpposite2DVector(vec2 *pSourceVector, vec2 *pResultVector);
vec3	laOpposite3DVector(vec3 *pSourceVector, vec3 *pResultVector);
vec4	laOpposite4DVector(vec4 *pSourceVector, vec4 *pResultVector);

vec2	laScalarProduct2DVector(vec2 *pSourceVector, float scalar, vec2 *pResultVector);
vec3	laScalarProduct3DVector(vec3 *pSourceVector, float scalar, vec3 *pResultVector);
vec4	laScalarProduct4DVector(vec4 *pSourceVector, float scalar, vec4 *pResultVector);

float	laDotProduct2DVectors(vec2 *pLeftVector, vec2 *pRightVector, float *pResult);
float	laDotProduct3DVectors(vec3 *pLeftVector, vec3 *pRightVector, float *pResult);
float	laDotProduct4DVectors(vec4 *pLeftVector, vec4 *pRightVector, float *pResult);

float	laGetCosBetween2DVectors(vec2 *pLeftVector, vec2 *pRightVector, float *pResult);
float	laGetCosBetween3DVectors(vec3 *pLeftVector, vec3 *pRightVector, float *pResult);
float	laGetCosBetween4DVectors(vec4 *pLeftVector, vec4 *pRightVector, float *pResult);

void	laCrossProduct3DVectors(vec3 *pBasisVector, vec3 *pLeftVector, vec3 *pRightVector, vec3 *pResultVector);

mat2	laInit2DMatrix(mat2 *pSourceMatrix, vec2 *pFirstVector, vec2 *pSecondVector, float *pInitArray, float *pOnevalue);
mat3	laInit3DMatrix(mat3 *pSourceMatrix, vec3 *pFirstVector, vec3 *pSecondVector, vec3 *pThirdVector, float *pInitArray, float *pOneValue);
mat4	laInit4DMatrix(mat4 *pSourceMatrix, vec4 *pFirstVector, vec4 *pSecondVector, vec4 *pThirdVector, vec4 *pFourthVector, float *pInitArray, float *pOneValue);

void	laAdd2DMatrix(mat2 *pLeftOperand, mat2 *pRightOperand, mat2 *pResultMatrix);
void	laAdd3DMatrix(mat3 *pLeftOperand, mat3 *pRightOperand, mat3 *pResultMatrix);
void	laAdd4DMatrix(mat4 *pLeftOperand, mat4 *pRightOperand, mat4 *pResultMatrix);

void	laSub2DMatrix(mat2 *pLeftOperand, mat2 *pRightOperand, mat2 *pResultMatrix);
void	laSub3DMatrix(mat3 *pLeftOperand, mat3 *pRightOperand, mat3 *pResultMatrix);
void	laSub4DMatrix(mat4 *pLeftOperand, mat4 *pRightOperand, mat4 *pResultMatrix);

float	laGetDeterminant2DMatrix(mat2 *pSourceMatrix, float *pResult);
float	laGetDeterminant3DMatrix(mat3 *pSourceMatrix, float *pResult, float *pSubMatrixArray);
float	laGetDeterminant4DMatrix(mat4 *pSourceMatrix, float *pResult, float *pSubMatrixArray);

mat2	laScale2DMatrix(mat2 *pSourceMatrix, vec2 *pScaleVector, mat2 *pResultMatrix, float *pScale);
mat3	laScale3DMatrix(mat3 *pSourceMatrix, vec3 *pScaleVector, mat3 *pResultMatrix, float *pScale);
mat4	laScale4DMatrix(mat4 *pSourceMatrix, vec4 *pScaleVector, mat4 *pResultMatrix, float *pScale);

vec3	laMul3DVectorByMatrix(vec3 *pSourceVector, mat3 *pSourceMatrix, vec3 *pResultVector);

#endif