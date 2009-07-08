/*
 * HashingVisitor.h
 *
 *  Created on: 07/07/2009
 *      Author: fabricio
 */

#ifndef HASHINGVISITOR_H_
#define HASHINGVISITOR_H_

#include "../lista2/Visitor.h"

class HashingVisitor : public Visitor
{
    HashValue value;
public:
    HashingVisitor (HashValue _value) : value (_value)
	{}

    void Visit (Object& object)
	{ value += object.Hash (); }

    HashValue Value () const
	{ return value; }
};

#endif /* HASHINGVISITOR_H_ */
