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

		/* listaslinkedlist */
		/*void Insert (Object&);
		Object& operator [] (unsigned int) const;
		bool IsMember (Object const&) const;
		Object& Find (Object const&) const;
		void Withdraw (Object&);
		Position& FindPosition (Object const&) const;
		Object& operator [] (Position const&) const;
		void InsertAfter (Position const&, Object&);
		void InsertBefore (Position const&, Object&);
		void Withdraw (Position const&);*/

		void Purge ();
		void Accept (Visitor&) const;

};

#endif /* SORTEDLISTASLINKEDLIST_H_ */
