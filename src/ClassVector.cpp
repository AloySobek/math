/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassVector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rustam <super.rustamm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:00:50 by vrichese          #+#    #+#             */
/*   Updated: 2019/11/29 15:54:40 by Rustam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void Vector::print()
{
	std::cout << "Vector out: " << x << " " << y << " " << z << " " << w << "\n";
}

double &Vector::operator[](int index)
{
	if (index == 0)
		return (x);
	else if (index == 1)
		return (y);
	else if (index == 2)
		return (z);
	else if (index == 3)
		return (w);
	else
		throw std::runtime_error("Out of range");
}

const double &Vector::operator[](int index) const
{
	if (index == 0)
		return (x);
	else if (index == 1)
		return (y);
	else if (index == 2)
		return (z);
	else if (index == 3)
		return (w);
	else
		throw std::runtime_error("Out of range");
}

void Vector::copy(Vector copyVector)
{
	x = copyVector.x;
	y = copyVector.y;
	z = copyVector.z;
	w = copyVector.w;
}

void Vector::operator=(Vector copyVector)
{
	x = copyVector.x;
	y = copyVector.y;
	z = copyVector.z;
	w = copyVector.w;
}

Vector Vector::add(Vector addVector)
{
	Vector result;

	result.x = x + addVector.x;
	result.y = y + addVector.y;
	result.z = z + addVector.z;
	result.w = w + addVector.w;
	return (result);
}

Vector Vector::operator+(Vector addVector)
{
	Vector result;

	result.x = x + addVector.x;
	result.y = y + addVector.y;
	result.z = z + addVector.z;
	result.w = w + addVector.w;
	return (result);
}

Vector Vector::sub(Vector subVector)
{
	Vector result;

	result.x = x - subVector.x;
	result.y = y - subVector.y;
	result.z = z - subVector.z;
	result.w = w - subVector.w;
	return (result);
}

Vector Vector::operator-(Vector subVector)
{
	Vector result;

	result.x = x - subVector.x;
	result.y = y - subVector.y;
	result.z = z - subVector.z;
	result.w = w - subVector.w;
	return (result);
}

double Vector::getMagnitude(void)
{
	return (sqrt(pow(x, 2.0) + pow(y, 2.0) + pow(z, 2.0) + pow(w, 2.0)));
}

void Vector::normalize(void)
{
	double length;

	length = 1 / getMagnitude();
	x *= length;
	y *= length;
	z *= length;
	w *= length;
}

Vector Vector::getOpposite(void)
{
	Vector	res;

	res.x = -x;
	res.y = -y;
	res.z = -z;
	res.w = -w;
	return (res);
}

Vector Vector::operator-(void)
{
	Vector	res;

	res.x = -x;
	res.y = -y;
	res.z = -z;
	res.w = -w;
	return (res);
}

Vector Vector::scalarProduct(double scalar)
{
	Vector res;

	res.x = x * scalar;
	res.y = y * scalar;
	res.z = z * scalar;
	res.w = w * scalar;
	return (res);
}

Vector Vector::operator()(double scalar)
{
	Vector res;

	res.x = x * scalar;
	res.y = y * scalar;
	res.z = z * scalar;
	res.w = w * scalar;
	return (res);
}

double Vector::dotProduct(Vector mulVector)
{
	double res = 0.0;

	res += x * mulVector.x;
	res += y * mulVector.y;
	res += z * mulVector.z;
	res += w * mulVector.w;
	return (res);
}

double Vector::operator()(Vector mulVector)
{
	double res = 0.0;

	res += x * mulVector.x;
	res += y * mulVector.y;
	res += z * mulVector.z;
	res += w * mulVector.w;
	return (res);
}

Vector Vector::crossProduct(Vector mulVector)
{
	;
}

double Vector::operator*(Vector mulVector)
{
	double res = 0.0;

	res += x * mulVector.x;
	res += y * mulVector.y;
	res += z * mulVector.z;
	res += w * mulVector.w;
	return (res);
}

// /*
// ** Cosine vector ----------------------------------------------------------------------
// */

// float		laGetCosBetween2DVectors(vec2 *pLeftVector, vec2 *pRightVector, float *pResult)
// {
// 	float	rightVectorLength;
// 	float	leftVectorLength;
// 	float	dotProduct;
// 	float	res;

// 	res = 0.0f;
// 	if (!pLeftVector || !pRightVector)
// 		return (res);
// 	for (int i = 0; i < LA_2D; ++i)
// 		res += pLeftVector->data[i] * pRightVector->data[i];
// 	rightVectorLength	= sqrtf(powf(pRightVector->data[LA_X], 2.0f)
// 								+ powf(pRightVector->data[LA_Y], 2.0f));
// 	leftVectorLength	= sqrtf(powf(pLeftVector->data[LA_X], 2.0f)
// 								+ powf(pLeftVector->data[LA_Y], 2.0f));
// 	res = res / (leftVectorLength * rightVectorLength);
// 	if (pResult)
// 	{
// 		*pResult = res;
// 		return (*pResult);
// 	}
// 	return (res);
// }

// float		laGetCosBetween3DVectors(vec3 *pLeftVector, vec3 *pRightVector, float *pResult)
// {
// 	float	rightVectorLength;
// 	float	leftVectorLength;
// 	float	dotProduct;
// 	float	res;

// 	res = 0.0f;
// 	if (!pLeftVector || !pRightVector)
// 		return (res);
// 	for (int i = 0; i < LA_3D; ++i)
// 		res += pLeftVector->data[i] * pRightVector->data[i];
// 	rightVectorLength	= sqrtf(powf(pRightVector->data[LA_X], 2.0f)
// 									+ powf(pRightVector->data[LA_Y], 2.0f)
// 										+ powf(pRightVector->data[LA_Z], 2.0f));
// 	leftVectorLength	= sqrtf(powf(pLeftVector->data[LA_X], 2.0f)
// 									+ powf(pLeftVector->data[LA_Y], 2.0f)
// 										+ powf(pLeftVector->data[LA_Z], 2.0f));
// 	res = res / (leftVectorLength * rightVectorLength);
// 	if (pResult)
// 	{
// 		*pResult = res;
// 		return (*pResult);
// 	}
// 	return (res);
// }

// float	laGetCosBetween4DVectors(vec4 *pLeftVector, vec4 *pRightVector, float *pResult)
// {
// 	float	rightVectorLength;
// 	float	leftVectorLength;
// 	float	dotProduct;
// 	float	res;

// 	res = 0.0f;
// 	if (!pLeftVector || !pRightVector)
// 		return (res);
// 	for (int i = 0; i < LA_4D; ++i)
// 		res += pLeftVector->data[i] * pRightVector->data[i];
// 	leftVectorLength	= sqrtf(powf(pLeftVector->data[LA_X], 2.0f)
// 								+ powf(pLeftVector->data[LA_Y], 2.0f)
// 									+ powf(pLeftVector->data[LA_Z], 2.0f)
// 										+ powf(pLeftVector->data[LA_W], 2.0f));
// 	rightVectorLength	= sqrtf(powf(pRightVector->data[LA_X], 2.0f)
// 								+ powf(pRightVector->data[LA_Y], 2.0f)
// 									+ powf(pRightVector->data[LA_Z], 2.0f)
// 										+ powf(pRightVector->data[LA_W], 2.0f));
// 	res = dotProduct / (leftVectorLength * rightVectorLength);
// 	if (pResult)
// 	{
// 		*pResult = res;
// 		return (*pResult);
// 	}
// 	return (res);
// }

// /*
// ** Cross Product vector ---------------------------------------------------------------
// */

// void		laCrossProduct3DVectors(vec3 *pBasisVector, vec3 *pLeftVector, vec3 *pRightVector, vec3 *pResultVector)
// {
// 	mat3	matrix;
// 	vec3	basisVec;
// 	float	det;
// 	float	subMatrix[3];

// 	if (!pLeftVector || !pRightVector)
// 		return ;
// 	if (!pBasisVector)
// 		laInit3DVector(&basisVec, 1.0f, 1.0f, 1.0f, NULL);
// 	else
// 		basisVec = *pBasisVector;
// 	laInit3DMatrix(&matrix, &basisVec, pLeftVector, pRightVector, (void *)0, (void *)0);
// 	laGetDeterminant3DMatrix(&matrix, &det, subMatrix);
// 	pResultVector->data[LA_X] = subMatrix[0];
// 	pResultVector->data[LA_Y] = -subMatrix[1];
// 	pResultVector->data[LA_Z] = subMatrix[2];

// }

// /*
// ** Multiply vector by matrix
// */

// vec3		laMul3DVectorByMatrix(vec3 *pSourceVector, mat3 *pSourceMatrix, vec3 *pResultVector)
// {
// 	vec3	newVector;

// 	if (!pSourceVector || !pSourceMatrix)
// 		return (newVector);
// 	for (int i = 0; i < LA_3D; ++i)
// 		newVector.data[i] = pSourceVector->data[LA_X] * pSourceMatrix->data[i][LA_X]
// 								+ pSourceVector->data[LA_Y] * pSourceMatrix->data[i][LA_Y]
// 									+ pSourceVector->data[LA_Z] * pSourceMatrix->data[i][LA_Z];
// 	if (pResultVector)
// 	{
// 		*pResultVector = newVector;
// 		return (*pResultVector);
// 	}
// 	return (newVector);
// }
