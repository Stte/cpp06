/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:06:13 by tspoof            #+#    #+#             */
/*   Updated: 2023/12/27 16:34:04 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string n)
{
	std::istringstream stream;

	char c = '\0';
	int i = 0;
	float f = 0.0f;
	double d = 0.0;


	std::cout << "ehhehe " << n.compare(".") << std::endl;

	if (n.compare("nan") == 0 || n.compare("nanf") == 0)
	{
		d = std::numeric_limits<double>::quiet_NaN();
		f = std::numeric_limits<float>::quiet_NaN();

		// char impossible
		// int impossible
	}

	else if (n.compare("inf") == 0 || n.compare("inff") == 0)
	{
		d = std::numeric_limits<double>::infinity();
		f = std::numeric_limits<float>::infinity();

		// char impossible
		// int imppossible
	}

	else if (n.compare("-inf") == 0 || n.compare("-inff") == 0)
	{
		d = -std::numeric_limits<double>::infinity();
		f = -std::numeric_limits<float>::infinity();

		// char impossible
		// int impossible
	}

	// if has . and f is float
	else if (n.find(".") != string::npos && n.find("f") != string::npos)
	{
		std::cout << "float" << std::endl;
		n.erase(std::remove(n.begin(), n.end(), 'f'), n.end());
		stream.str(n);
		stream >> f;
		if (stream.fail())
			std::cout << "error" << std::endl;
		c = static_cast<char>(f);
		i = static_cast<int>(f);
		d = static_cast<double>(f);
	}


	// if has . and no f is double
	else if (n.compare(".") == 0)
	{
		std::cout << "double" << std::endl;
		stream.str(n);
		stream >> d;
		if (stream.fail())
			std::cout << "error" << std::endl;
		c = static_cast<char>(d);
		i = static_cast<int>(d);
		f = static_cast<float>(d);
	}

	// if it's printable is char
	else if (n.length() == 1 && isprint(n[0]))
	{
		std::cout << "char" << std::endl;
		stream.str(n);
		stream >> c;
		if (stream.fail())
			std::cout << "error" << std::endl;
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
	}

	// if number is int


	std::cout << "i: " << i << std::endl;
	std::cout << "f: " << f << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "c: " << c << std::endl;


	// print stuff

	// stream.str(n);
	// stream >> i;
	// if (stream.fail())
	// 	std::cout << "error" << std::endl;
	// std::cout << i << std::endl;

	// stream.clear();
	// stream.str(n);
	// stream >> f;
	// if (stream.fail())
	// 	std::cout << "error2" << std::endl;
	// std::cout << f << std::endl;


}
