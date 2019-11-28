/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rustam <super.rustamm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:09:24 by Rustam            #+#    #+#             */
/*   Updated: 2019/11/28 20:09:07 by Rustam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main(int argc, char **argv)
{
	Vector	vec(3.0, 1.0, 1.0, 1.0);
	const Vector const_vec;

	std::cout << vec << std::endl;
	std::cout << vec[0] << std::endl;
	vec[0] = 30.0;
	std::cout << "New: " << vec[0] << std::endl;
	std::cout << vec[1] << std::endl;
	std::cout << vec[2] << std::endl;
	std::cout << vec[3] << std::endl;
	std::cout << "Const: " << const_vec[0] << std::endl;
    return (0);
}