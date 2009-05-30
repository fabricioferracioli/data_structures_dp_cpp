/*
 * Queue.h
 *
 *  Created on: 30/05/2009
 *      Author: fabricio
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "../lista2/Container.h"

class Queue : public virtual Container
{
	public:
		virtual Object& Head () const = 0;
		virtual void Enqueue (Object&) = 0;
		virtual Object& Dequeue () = 0;
};

#endif /* QUEUE_H_ */
