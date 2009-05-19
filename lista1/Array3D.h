/*
 * Array3D.h
 *
 *  Created on: 05/04/2009
 *      Author: fabricio
 */

#ifndef ARRAY3D_H_
#define ARRAY3D_H_

#include "Array.h"
#include "Array2D.h"

template <class T>
class Array3D
{
	protected:
		unsigned int mX;
		unsigned int mY;
		unsigned int mZ;
		Array2D<T> array2d;
	public:
		class Column
		{
			Array3D& array3D;
			unsigned int const column;
			public:
				Column(Array3D& _array3D, unsigned int _column):array3D(_array3D), column(_column){}
				T& operator[] (unsigned int column) const
				{
					return array3D.Select (row, column);
				}
		};

		Array3D(unsigned int x, unsigned int y, unsigned int z):mX(x), mY(y), mZ(z), array(x * y * z) {}

		T& Select(unsigned int i, unsigned int j)
		{
			if (i - base >= numberOfRows)
				throw std::out_of_range ("invalid row");
			if (j - base >= numberOfColumns)
				throw std::out_of_range ("invalid column");

			return array [i * numberOfColumns + j - (numberOfColumns * base)];
		}

		Array2D<T> operator[](unsigned int row)
		{
			return Row (*this, row);
		}


};

#endif /* ARRAY3D_H_ */
