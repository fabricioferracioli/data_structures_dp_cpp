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
		void Insert (Object&);
		Object& operator [] (unsigned int) const;
		bool IsMember (Object const&) const;
		Object& Find (Object const&) const;
		void Withdraw (Object&);
		Position& FindPosition (Object const&) const;
		Object& operator [] (Position const&) const;
		void InsertAfter (Position const&, Object&);
		void Withdraw (Position const&);

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

		virtual void Reset();
		virtual bool IsDone() const;
		virtual Object& operator*() const;
		virtual void operator++();
};

#endif /* LISTASARRAY_H_ */
