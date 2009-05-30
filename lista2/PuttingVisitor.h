/*
 * PuttingVisitor.h
 *
 *  Created on: 18/05/2009
 *      Author: fabricio
 */

#ifndef PUTTINGVISITOR_H_
#define PUTTINGVISITOR_H_

#include "Visitor.h"

class PuttingVisitor : public Visitor
{
    std::ostream& stream;
    bool comma;
public:
    PuttingVisitor (std::ostream& s) : stream (s), comma (false)
	{}
    void Visit (Object& object)
    {
		if (comma)
			stream << ", ";
		stream << object;
		comma = true;
    }
};

#endif /* PUTTINGVISITOR_H_ */
