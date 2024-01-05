/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:38:10 by tspoof            #+#    #+#             */
/*   Updated: 2024/01/05 15:41:30 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: ./scalar char | int | float | double" << std::endl;
		return 1;
	}
	std::string input(argv[1]);
	ScalarConverter::convert(input);
	return (0);
}
