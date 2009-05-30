/*
 * StackAsArray.h
 *
 *  Created on: 30/05/2009
 *      Author: fabricio
 */

#ifndef STACKASARRAY_H_
#define STACKASARRAY_H_

#include "Stack.h"
#include "../lista1/Array.h"
#include "../lista2/NullObject.h"

class StackAsArray : public Stack
{
    Array<Object*> array;

    class Iter;
	public:
		StackAsArray (unsigned int);
		void Purge ();
		void Push (Object&);
		Object& Pop ();
		Object& Top () const;
		void Accept (Visitor&) const;
		~StackAsArray ();
		friend class Iter;
};

class StackAsArray::Iter : public Iterator
{
		StackAsArray const& stack;
		unsigned int position;
	public:
		Iter (StackAsArray const&);
		bool IsDone () const;
		Object& operator * () const;
		void operator ++ ();
		void Reset ();
};
#endif /* STACKASARRAY_H_ */
