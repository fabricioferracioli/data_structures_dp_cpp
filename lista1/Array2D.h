#ifndef ARRAY2D_H_
#define ARRAY2D_H_

#include "Array.h"
#include <stdexcept>

template <class T>
class Array2D
{
	protected:
		unsigned int numberOfRows;
		unsigned int numberOfColumns;
		unsigned int base;
		Array<T> array;
	public:
		class Row
		{
			Array2D& array2D;
			unsigned int const row;
			public:
				Row(Array2D& _array2D, unsigned int _row):array2D(_array2D), row(_row){}
				T& operator[] (unsigned int column) const
				{
					return array2D.Select (row, column);
				}
		};

		Array2D(unsigned int m, unsigned int n, unsigned int b = 0):numberOfRows(m), numberOfColumns(n), base(b), array(m * n, b){}

		T& Select(unsigned int i, unsigned int j)
		{
			if (i - base >= numberOfRows)
				throw std::out_of_range ("invalid row");
			if (j - base >= numberOfColumns)
				throw std::out_of_range ("invalid column");

			return array [i * numberOfColumns + j - (numberOfColumns * base)];
		}

		Row operator[](unsigned int row)
		{
			return Row (*this, row);
		}
};
#endif
