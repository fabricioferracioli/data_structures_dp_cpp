/*
 * RowVector.h
 *
 *  Created on: 05/04/2009
 *      Author: fabricio
 */

#ifndef ROWVECTOR_H_
#define ROWVECTOR_H_

#include "Array2D.h"

template <class T>
class RowVector : public Array2D<T>
{
	public:
		RowVector(unsigned int size) : Array2D<T>(1, size){}
		T& operator[] (unsigned int i)
		{
			return Array2D<T>::Select(0, i);
		}

};

#endif /* ROWVECTOR_H_ */
