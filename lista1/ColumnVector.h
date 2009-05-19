/*
 * ColumnVector.h
 *
 *  Created on: 05/04/2009
 *      Author: fabricio
 */

#ifndef COLUMNVECTOR_H_
#define COLUMNVECTOR_H_

#include "Array2D.h"

template <class T>
class ColumnVector : public Array2D<T>
{
	public:
		ColumnVector(unsigned int size) : Array2D<T>(size, 1){}
		T& operator[] (unsigned int i)
		{
			return Array2D<T>::Select(i, 0);
		}
};

#endif /* COLUMNVECTOR_H_ */
