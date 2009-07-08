/*
 * Counter.h
 *
 *  Created on: 08/07/2009
 *      Author: fabricio
 */

#ifndef COUNTER_H_
#define COUNTER_H_

#include "../lista2/Wrapper.h"
typedef Wrapper<int> Int;

class Counter : public Int
{
public:
    Counter (int i) : Int (i)
	{}
    void operator ++ ()
	{ ++datum; }
};

#endif /* COUNTER_H_ */
