#ifndef MULTIPLESTACK_H_
#define MULTIPLESTACK_H_

#include "StackAsLinkedList.h"
#include "../lista2/Container.h"
#include "../lista1/Array.h"

class MultipleStack : public Container
{
	private:
		Array<StackAsLinkedList*> array;
	public:
        MultipleStack (unsigned int);
        virtual ~MultipleStack();
        void Push (Object&, unsigned int);
        Object& Pop (unsigned int);
        Object& Top (unsigned int) const;
        unsigned int SizeOfStack (unsigned int) const;
        void Purge ();
        void Accept (Visitor&) const;
};

#endif /*MULTIPLESTACK_H_*/
