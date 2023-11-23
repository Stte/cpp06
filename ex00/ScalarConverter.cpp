/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:06:13 by tspoof            #+#    #+#             */
/*   Updated: 2023/11/17 13:52:32 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string n)
{
	std::istringstream stream;

	int i;
	float f;

	if (n.compare("nan") == 0 || n.compare("nanf") == 0)
	{
		double d = std::numeric_limits<double>::quiet_NaN();
		float f = std::numeric_limits<float>::quiet_NaN();

		// char impossible
		// int impossible
	}

	if (n.compare("inf") == 0 || n.compare("inff") == 0)
	{
		double d = std::numeric_limits<double>::infinity();
		float f = std::numeric_limits<float>::infinity();

		// char impossible
		// int imppossible
	}

	if (n.compare("-inf") == 0 || n.compare("-inff") == 0)
	{
		double d = -std::numeric_limits<double>::infinity();
		float f = -std::numeric_limits<float>::infinity();

		// char impossible
		// int impossible
	}

	// if has . and f is float
	if (n.compare(".") == 0 && n.compare("f") == 0)
	{
		float f;

		n.erase(std::remove(n.begin(), n.end(), 'f'), n.end());
		stream.str(n);
		stream >> f;
		if (stream.fail())
			std::cout << "error" << std::endl;
	}

	// if has . and no f is double
	// if it's printable is char
	// if number is int

	stream.str(n);
	stream >> i;
	if (stream.fail())
		std::cout << "error" << std::endl;
	std::cout << i << std::endl;

	stream.clear();
	stream.str(n);
	stream >> f;
	if (stream.fail())
		std::cout << "error2" << std::endl;
	std::cout << f << std::endl;
}
