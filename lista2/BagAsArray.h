/*
 * BagAsArray.h
 *
 *  Created on: 29/05/2009
 *      Author: fabricio
 */

#ifndef BAGASARRAY_H_
#define BAGASARRAY_H_

#include "SearchableContainer.h"
#include "NullObject.h"
#include "../lista1/Array.h"

class BagAsArray : public virtual SearchableContainer
{
private:

	Array<Object*> array;
	class Iter;
public:

	BagAsArray(unsigned int=10);
	virtual ~BagAsArray();
	bool IsFull () const;
	Iterator& NewIterator () const;
	int CompareTo(const Object&)const;
	void Purge ();
	void Accept (Visitor&) const;
	bool IsMember (Object const&) const;
	void Insert (Object&);
	void Withdraw (Object&);
	Object& Find (Object const&) const;

	friend class Iter;
};

class BagAsArray::Iter : public Iterator
{

    private:
    	BagAsArray const& bag;
		unsigned int position;

    public:
		Iter(BagAsArray const&);
		bool IsDone()const;
		Object& operator*()const;
		void operator++();
		void Reset();
};

#endif /* BAGASARRAY_H_ */
