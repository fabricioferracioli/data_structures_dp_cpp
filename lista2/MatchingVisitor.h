/*
 * MatchingVisitor.h
 *
 *  Created on: 29/05/2009
 *      Author: fabricio
 */

#ifndef MATCHINGVISITOR_H_
#define MATCHINGVISITOR_H_

#include "Visitor.h"

class MatchingVisitor : public Visitor
{
    private:
        Object const& target;
        Object* found;

    public:
        MatchingVisitor (Object const& object) : target (object), found (0) {}
        void Visit (Object& object) {
            if (found == 0 && object == target)
                found = &object;
        }

        bool IsDone () const { return found != 0; }
        Object* Found(){ return found; }
};

#endif /* MATCHINGVISITOR_H_ */
