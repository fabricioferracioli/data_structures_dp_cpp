/*
 * Bag.h
 *
 *  Created on: May 19, 2009
 *      Author: fabricio
 */

#ifndef BAG_H_
#define BAG_H_

#include "SearchableContainer.h"
#include "lista1/Array.h"
#include "Object.h"

class Bag: public SearchableContainer {
public:
	Bag();
	Bag(int);
	void Insert(Object &);
	bool IsFull();
	bool IsEmpty();
	virtual ~Bag();
private:
	Array<Object> mBag;
	unsigned int mLastEmptyPosition;
};

#endif /* BAG_H_ */
