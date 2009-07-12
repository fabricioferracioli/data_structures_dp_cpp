/*
 * AVL.h
 *
 *  Created on: 11/07/2009
 *      Author: fabricio
 */

#ifndef AVL_H_
#define AVL_H_

#include "BST.h"

class AVLTree : public BST
{
protected:
    int height;

    int BalanceFactor () const;
    void AdjustHeight ();
    void LLRotation ();
    void LRRotation ();
    void RRRotation ();
    void RLRotation ();
    void AttachKey (Object&);
    Object& DetachKey ();
    void Balance ();
    int Max(int const, int const) const;
public:
    AVLTree ();

    int Height () const;
    AVLTree& Left () const;
    AVLTree& Right () const;
};
#endif /* AVL_H_ */
