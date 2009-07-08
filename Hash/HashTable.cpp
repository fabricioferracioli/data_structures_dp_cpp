/*
 * HashTable.cpp
 *
 *  Created on: 07/07/2009
 *      Author: fabricio
 */

#include "HashTable.h"

HashTable::HashTable (unsigned int _length) : length (_length)
{}

unsigned int HashTable::H (Object const& object) const
{
	return object.Hash () % length;
}

