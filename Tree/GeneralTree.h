/*
 * GeneralTree.h
 *
 *  Created on: 10/07/2009
 *      Author: fabricio
 */
/*
#ifndef GENERALTREE_H_
#define GENERALTREE_H_

#include "Tree.h"
#include "../lista1/LinkedList.h"

class GeneralTree : public Tree
{
protected:
    Object* key;
    unsigned int degree;
    LinkedList<GeneralTree*> list;
public:
    GeneralTree (Object&);
    ~GeneralTree ();

    Object& Key () const;
    GeneralTree& Subtree (unsigned int) const;
    virtual void AttachSubtree (GeneralTree&);
    virtual GeneralTree& DetachSubtree (GeneralTree&);
    void Purge ();

    virtual int Height() const;
};


#endif /* GENERALTREE_H_ */
