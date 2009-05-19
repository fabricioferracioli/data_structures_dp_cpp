/*
 * Bag.cpp
 *
 *  Created on: May 19, 2009
 *      Author: fabricio
 */

#include "Bag.h"

Bag::Bag() {

}

Bag::Bag(int sizeOfBag) : SearchableContainer(sizeOfBag)
{
	mBag = new Array(Count());
	mLastEmptyPosition = 0;
}

void Bag::Insert(Object& obj)
{
	if (!IsFull())
	{
		mBag[mLastEmptyPosition++] = obj;
	}

}

bool Bag::IsFull()
{
	return count - 1 == mLastEmptyPosition;
}

bool Bag::IsEmpty()
{
	return mLastEmptyPosition == 0;
}

Bag::~Bag() {
	// TODO Auto-generated destructor stub
}
