/*
 * SortedListAsArray.h
 *
 *  Created on: 26/06/2009
 *      Author: fabricio
 */

#ifndef SORTEDLISTASARRAY_H_
#define SORTEDLISTASARRAY_H_

#include "SortedList.h"
#include "ListAsArray.h"

class SortedListAsArray : public virtual SortedList, public virtual ListAsArray
{
    unsigned int FindOffset (Object const&) const;
	public:
		SortedListAsArray (unsigned int);
		void Insert (Object&);
		Object& Find (Object const&) const;
		Position& FindPosition (Object const&) const;
		void Withdraw (Object&);

};

#endif /* SORTEDLISTASARRAY_H_ */
