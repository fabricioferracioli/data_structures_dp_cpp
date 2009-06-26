/*
 * OrderedList.h
 *
 *  Created on: 26/06/2009
 *      Author: fabricio
 */

#ifndef ORDEREDLIST_H_
#define ORDEREDLIST_H_

#include "List.h"

class OrderedList : public virtual List
{
	public:
	    virtual void InsertAfter (Position const&, Object&) = 0;
	    virtual void InsertBefore (Position const&, Object&) = 0;
};

#endif /* ORDEREDLIST_H_ */
