/*
 * Stack.h
 *
 *  Created on: 30/05/2009
 *      Author: fabricio
 */

#ifndef STACK_H_
#define STACK_H_

#include "../lista2/Container.h"

class Stack : public virtual Container
{
	public:
		virtual Object& Top () const = 0;
		virtual void Push (Object&) = 0;
		virtual Object& Pop () = 0;
};

#endif /* STACK_H_ */
