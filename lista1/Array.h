/*
 * Array.h
 *
 *  Created on: 04/04/2009
 *      Author: fabricio
 */

#ifndef ARRAY_H_
#define ARRAY_H_
#include <stdexcept>
#include <iostream>

template <class T>
class Array
{
	protected:
		T* data;
		unsigned int base;
		unsigned int length;
	public:
		Array () : data (new T [0]), base (0), length (0){}

		Array (unsigned int n, unsigned int m = 0) : data (new T [n]), base (m), length (n) {}

		Array (Array<T> const& array) : data (new T [array.length]), base (array.base), length (array.length)
		{
		    for (unsigned int i = 0; i < length; ++i)
		    	data [i] = array.data [i];
		}
		~Array ()
		{
			delete [] data;
		}

		Array<T>& operator=(Array const& array)
		{
		    length = array.Length();
		    base = array.Base();
		    data = new T [length];

		    for(unsigned int i = 0; i < length; i++)
		    {
		        data[i] = array.data[i];
		    }
		}

		T const* Data () const
	    {
			return data;
		}

		unsigned int Base () const
		{
			return base;
		}
		unsigned int Length () const
		{
			return length;
		}

		T const& operator [] (unsigned int position) const
		{
			unsigned int const offset = position - base;

			if (offset >= length)
				throw std::out_of_range ("invalid position");

			return data [offset];
		}

		T& operator [] (unsigned int position)
		{
			unsigned int const offset = position - base;

			if (offset >= length)
				throw std::out_of_range ("invalid position");

			return data [offset];
		}

		void SetBase (unsigned int newBase)
		{
			base = newBase;
		}

		void SetLength (unsigned int newLength)
		{
		    T* const newData = new T [newLength];
		    unsigned int const min = length < newLength ? length : newLength;

		    for (unsigned int i = 0; i < min; ++i)
		    	newData [i] = data [i];

		    delete [] data;
		    data = newData;
		    length = newLength;
		}
};

#endif /* ARRAY_H_ */
