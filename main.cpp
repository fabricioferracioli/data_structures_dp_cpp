/*
 * main.cpp
 *
 *  Created on: 16/05/2009
 *      Author: fabricio
 */

#include <iostream>
#include "Wrapper.h"

typedef Wrapper<int> Int;
typedef Wrapper<char> Char;
typedef Wrapper<double> Double;
typedef Wrapper<std::string> String;

void ex1()
{
	std::cout << "Exercicio 01" << std::endl;
	Int a(1);
	Int b(2);
	if((a == b) == 0)
		std::cout << "a = b" << std::endl;
	else
		std::cout << "a != b" << std::endl;

	b = 2;
	if((a == b) == 0)
			std::cout << "a = b" << std::endl;
		else
			std::cout << "a != b" << std::endl;


}

int main()
{
	ex1();
	return 0;
}
