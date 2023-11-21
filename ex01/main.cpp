/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:19:29 by tspoof            #+#    #+#             */
/*   Updated: 2023/11/21 19:26:32 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	Data *data = new Data;
	data->s1 = "Hello";
	data->n = 42;

	uintptr_t raw = Serializer::serialize(data);
	std::cout << raw << std::endl;
	Data *data2 = Serializer::deserialize(raw);

	std::cout << data2->s1 << std::endl;
	std::cout << data2->n << std::endl;

	std::cout << "Address of data: " << data << std::endl;
	std::cout << "Address of data2: " << data2 << std::endl;

	delete data;
	return 0;
}
