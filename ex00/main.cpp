/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:38:10 by tspoof            #+#    #+#             */
/*   Updated: 2023/12/27 16:25:41 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <string>
#include <sstream>
#include <iostream>

int main()
{
	// ScalarConverter::convert("42.22");
	ScalarConverter::convert("K");
	ScalarConverter::convert("42.22");
	ScalarConverter::convert("22.11f");
	return (0);
}
