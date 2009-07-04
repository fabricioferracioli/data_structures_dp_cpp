/*
 * SortedListAsLinkedList.h
 *
 *  Created on: 26/06/2009
 *      Author: fabricio
 */

#ifndef SORTEDLISTASLINKEDLIST_H_
#define SORTEDLISTASLINKEDLIST_H_

#include "SortedList.h"
#include "ListAsLinkedList.h"

class SortedListAsLinkedList : public virtual SortedList, public virtual ListAsLinkedList
{
	public:
		SortedListAsLinkedList ();
		void Insert (Object&);

};

#endif /* SORTEDLISTASLINKEDLIST_H_ */
