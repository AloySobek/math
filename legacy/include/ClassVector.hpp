/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassVector.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rustam <super.rustamm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 16:31:03 by Rustam            #+#    #+#             */
/*   Updated: 2020/01/05 20:16:27 by Rustam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_VECTOR_HPP
# define CLASS_VECTOR_HPP

# include "astra.hpp"

class Vector
{
	public:
		double coordinates[4];

	Vector(double x = 0.0, double y = 0.0, double z = 0.0, double w = 0.0) : coordinates[0]{x}

	void print();
	friend std::ostream &operator<<(std::ostream &out, Vector outVector)
	{
		out << "(" << outVector.x << " " << outVector.y << " " << outVector.z << " " << outVector.w << ")";
		return (out);
	}
	friend std::istream &operator>>(std::istream &in, Vector inVector)
	{
		in >> inVector.x;
		in >> inVector.y;
		in >> inVector.z;
		in >> inVector.w;
		return (in);
	}

	double &operator[](int index);
	const double &operator[](int index) const;

	void copy(Vector copyVector);
	void operator=(Vector copyVector);

	Vector add(Vector addVector);
	Vector operator+(Vector addVector);

	Vector sub(Vector subVector);
	Vector operator-(Vector subVector);

	double	getMagnitude(void);

	void	normalize(void);

	Vector	getOpposite(void);
	Vector	operator-(void);

	Vector	scalarProduct(double scalar);
	Vector	operator()(double scalar);

	double dotProduct(Vector mulVector);
	double operator()(Vector mulVector);

	Vector crossProduct(Vector mulVector);
	double operator*(Vector mulVector);
};

#endif