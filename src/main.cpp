/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rustam <super.rustamm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:09:24 by Rustam            #+#    #+#             */
/*   Updated: 2019/12/19 20:09:40 by Rustam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

#define SIZE 10000000

void	*checkX(void *ptr)
{
	if (((char *)ptr)[0] == 0)
	{
		((char *)ptr)[0] += 2;
		((char *)ptr)[0] -= 2;
	}
	return (NULL);
}

void	*checkY(void *ptr)
{
	if (((char *)ptr)[1] == 0)
	{
		((char *)ptr)[1] += 3;
		((char *)ptr)[1] -= 3;
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t		one, two;
	char			*test;

	test = (char *)malloc(SIZE);
	if (!test)
		return (0);
	memset(test, 0, SIZE);
	pthread_create(&one, NULL, checkX, (void *)test);
	pthread_create(&two, NULL, checkY, (void *)test);
	for (int i = 0; i < 10000000; ++i)
	{
		pthread_join(one, NULL);
		pthread_join(two, NULL);
	}
	//Vector one(3.0, 4.0, 5.0, 0.0);
	//Vector two(11.0, 14.5, 5.0, 0.0);
	//double res;
	//glm::vec4 one1(3.0, 4.0, 5.0, 0.0);
	//glm::vec4 two1(11.0, 14.5, 5.0, 0.0);

	//std::cout << Vector(1.0, 2.0, 3.0, 0.0) << std::endl;

	//for (int i = 0; i < 100000000; ++i)
	//	res = one(two);
	//std::cout << one(two) << std::endl;
	//for (int i = 0; i < 100000000; ++i)
	//	res = glm::dot(one1, two1);
	//std::cout << glm::dot(one1, two1) << std::endl;
    return (0);
}