/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassPoint.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rustam <super.rustamm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:14:24 by Rustam            #+#    #+#             */
/*   Updated: 2019/11/28 19:18:37 by Rustam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_POINT_HPP
# define CLASS_POINT_HPP

#include "main.hpp"

class Point
{
	private:
		double m_x;
		double m_y;

	public:
		Point(double x = 0.0, double y = 0.0) : m_x{x}, m_y{y} { }
		void print() { std::cout << "Point(" << m_x << ", " << m_y << ")\n"; }
		friend double distanceFrom(Point &first, Point &second);
};

double distanceFrom(Point &first, Point &second)
{
	return sqrt(((first.m_x - second.m_x) * (first.m_x - second.m_x)) + ((first.m_y - second.m_y) * (first.m_y - second.m_y)));
}

#endif