/*
 * ListAsArray.h
 *
 *  Created on: 26/06/2009
 *      Author: fabricio
 */

#ifndef LISTASARRAY_H_
#define LISTASARRAY_H_

#include "OrderedList.h"
#include "../lista1/Array.h"
#include "../Iterator/Position.h"

class ListAsArray : public virtual OrderedList
{
	protected:
		Array<Object*> array;

		class Pos;
	public:
		ListAsArray (unsigned int);

		friend class Pos;
};

class ListAsArray::Pos : public Position
{
	protected:
		ListAsArray const& list;
		unsigned int offset;
	public:
		friend class ListAsArray;
		friend class SortedListAsArray;
};

#endif /* LISTASARRAY_H_ */
