/*
 * BST.h
 *
 *  Created on: 11/07/2009
 *      Author: fabricio
 */

#ifndef BST_H_
#define BST_H_

#include "BinaryTree.h"
#include "SearchTree.h"

class BST : public BinaryTree, public SearchTree
{
protected:
    virtual void AttachKey (Object&);
    virtual Object& DetachKey ();
    virtual void Balance ();
public:
	BST();
	BST(Object&);
    BST& Left () const;
    BST& Right () const;
    Object& FindMin () const;
    Object& FindMax () const;
    Object& Find (Object const& object) const;
    void Insert (Object& object);
    void Withdraw (Object& object);
    bool IsMember(const Object&) const;
};

#endif /* BST_H_ */
