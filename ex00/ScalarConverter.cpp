/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:06:13 by tspoof            #+#    #+#             */
/*   Updated: 2024/01/05 15:39:08 by tspoof           ###   ########.fr       */
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
	bool impossible = false;

	if (n.compare("nan") == 0 || n.compare("nanf") == 0)
	{
		d = std::numeric_limits<double>::quiet_NaN();
		f = std::numeric_limits<float>::quiet_NaN();
		impossible = true;
		// char impossible
		// int impossible
	}

	else if (n.compare("inf") == 0 || n.compare("inff") == 0)
	{
		d = std::numeric_limits<double>::infinity();
		f = std::numeric_limits<float>::infinity();
		impossible = true;
		// char impossible
		// int imppossible
	}

	else if (n.compare("-inf") == 0 || n.compare("-inff") == 0)
	{
		d = -std::numeric_limits<double>::infinity();
		f = -std::numeric_limits<float>::infinity();
		impossible = true;
		// char impossible
		// int impossible
	}

	// if has . and f is float
	else if (n.find(".") != std::string::npos && n.find("f") != std::string::npos)
	{
		n.erase(std::remove(n.begin(), n.end(), 'f'), n.end());
		stream.str(n);
		stream >> f;
		if (stream.fail())
		{
			std::cout << "error" << std::endl;
			return;
		}
		c = static_cast<char>(f);
		i = static_cast<int>(f);
		d = static_cast<double>(f);
	}

	// if has . and no f is double
	else if (n.find(".") != std::string::npos)
	{
		stream.str(n);
		stream >> d;
		if (stream.fail())
		{
			std::cout << "error" << std::endl;
			return;
		}
		c = static_cast<char>(d);
		i = static_cast<int>(d);
		f = static_cast<float>(d);
	}

	// if it's a char
	// else if (n.length() == 1 && isprint(n[0]))
	else if (n.length() == 1)
	{
		stream.str(n);
		stream >> c;
		if (stream.fail())
		{
			std::cout << "error" << std::endl;
			return;
		}
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
	}

	// if number is int
	else
	{
		stream.str(n);
		stream >> i;
		if (stream.fail())
		{
			std::cout << "error" << std::endl;
			return;
		}
		c = static_cast<char>(i);
		f = static_cast<float>(i);
		d = static_cast<double>(i);
	}

	// print stuff
	if (impossible)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		if (isprint(c))
			std::cout << "char: " << c << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << i << std::endl;
	}
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}
