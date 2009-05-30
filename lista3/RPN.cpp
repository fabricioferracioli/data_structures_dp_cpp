/*
 * RPN.cpp
 *
 *  Created on: 30/05/2009
 *      Author: fabricio
 */

#include "Stack.h"
#include "../lista2/Wrapper.h"
#include <iostream>

typedef Wrapper<int> Int;

void RPNCalculator (Stack& stack)
{
    char c;
    while (std::cin >> c, !std::cin.eof ())
    {
		if (std::isdigit (c))
			stack.Push (*new Int (c - '0'));
		else if (c == '+')
		{
			Int& arg2 = dynamic_cast<Int&> (stack.Pop ());
			Int& arg1 = dynamic_cast<Int&> (stack.Pop ());
			stack.Push (*new Int (arg1 + arg2));
			delete &arg1;
			delete &arg2;
		}
		else if (c == '*')
		{
			Int& arg2 = dynamic_cast<Int&> (stack.Pop ());
			Int& arg1 = dynamic_cast<Int&> (stack.Pop ());
			stack.Push (*new Int (arg1 * arg2));
			delete &arg1;
			delete &arg2;
		}
		else if (c == '=')
		{
			Int& arg = dynamic_cast<Int&> (stack.Pop ());
			std::cout << arg << std::endl;
			delete &arg;
		}
    }
}
