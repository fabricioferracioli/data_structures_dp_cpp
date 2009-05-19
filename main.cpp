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
	std::cout << "Testando para Int" << std::endl;
	Int a(1);
	Int b(2);
	if(a == b)
		std::cout << "a = b" << std::endl;
	else
		std::cout << "a != b" << std::endl;

	a = 2;
	if(a == b)
			std::cout << "a = b" << std::endl;
		else
			std::cout << "a != b" << std::endl;

	std::cout << std::endl << "Testando para Char" << std::endl;
	Char c('s');
	Char d('k');
	if (c == d)
		std::cout << "c = d" << std::endl;
	else
		std::cout << "c != d" << std::endl;

	d = 's';
	if (c == d)
		std::cout << "c = d" << std::endl;
	else
		std::cout << "c != d" << std::endl;

	std::cout << std::endl << "Testando para Double" << std::endl;
	Double e(1.234);
	Double f(2.652);
	if (e == f)
		std::cout << "e = f" << std::endl;
	else
		std::cout << "e != f" << std::endl;

	f = 1.234;
	if (e == f)
		std::cout << "e = f" << std::endl;
	else
		std::cout << "e != f" << std::endl;

	std::cout << std::endl << "Testando para String" << std::endl;
	String g("teste");
	String h("testando");
	if (g == h)
		std::cout << "g = h" << std::endl;
	else
		std::cout << "g != h" << std::endl;

	h = "teste";
	if (e == f)
		std::cout << "g = h" << std::endl;
	else
		std::cout << "g != h" << std::endl;

	std::cout << std::endl;
}

void ex2()
{
	std::cout << "Exercicio 01" << std::endl;
}

int main()
{
	ex1();
	ex2();
	return 0;
}
