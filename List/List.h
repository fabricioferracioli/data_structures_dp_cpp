/*
 * List.h
 *
 *  Created on: 26/06/2009
 *      Author: fabricio
 */

#ifndef LIST_H_
#define LIST_H_

#include "../lista2/SearchableContainer.h"
#include "../Iterator/Position.h"

class List : public virtual SearchableContainer
{
	public:
		virtual Object& operator [] (unsigned int) const = 0;
		virtual Object& operator [] (Position const&) const = 0;
		virtual Position& FindPosition (Object const&) const = 0;
		virtual void Withdraw (Position const&) = 0;
};

#endif /* LIST_H_ */
