/*
 * AVL.cpp
 *
 *  Created on: 11/07/2009
 *      Author: fabricio
 */

#include "AVLTree.h"

AVLTree::AVLTree () : BST (), height (-1)
{}

int AVLTree::Height () const
{
	return height;
}

int AVLTree::Max(int const leftNodeHeight, int const rightNodeHeight) const
{
	return leftNodeHeight > rightNodeHeight ? leftNodeHeight : rightNodeHeight;
}

void AVLTree::AdjustHeight ()
{
    if (IsEmpty ())
    	height = -1;
    else
    	height = Max (left->Height (), right->Height ()) + 1;
}

int AVLTree::BalanceFactor () const
{
    if (IsEmpty ())
    	return 0;
    else
    	return left->Height () - right->Height ();
}

AVLTree& AVLTree::Left () const
{
	return dynamic_cast<AVLTree&> (BST::Left ());
}

AVLTree& AVLTree::Right () const
{
	return dynamic_cast<AVLTree&> (BST::Right ());
}

void AVLTree::LLRotation ()
{
    if (IsEmpty ())
    	throw std::domain_error ("invalid rotation");

    BinaryTree* const tmp = right;
    right = left;
    left = Right ().left;
    Right ().left = Right ().right;
    Right ().right = tmp;

    Object* const tmpObj = key;
    key = Right ().key;
    Right ().key = tmpObj;

    Right ().AdjustHeight ();
    AdjustHeight ();
}

void AVLTree::RRRotation ()
{
    if (IsEmpty ())
    	throw std::domain_error ("invalid rotation");

    BinaryTree* const tmp = left;
    left = right;
    right = Left ().right;
    Left ().right = Left ().left;
    Left ().left = tmp;

    Object* const tmpObj = key;
    key = Left ().key;
    Left ().key = tmpObj;

    Left ().AdjustHeight ();
    AdjustHeight ();
}

void AVLTree::LRRotation ()
{
    if (IsEmpty ())
    	throw std::domain_error ("invalid rotation");

    Left ().RRRotation ();
    LLRotation ();
}

void AVLTree::RLRotation ()
{
    if (IsEmpty ())
    	throw std::domain_error ("invalid rotation");

    Right ().LLRotation ();
    RRRotation ();
}

void AVLTree::Balance ()
{
    AdjustHeight ();
    if (abs (BalanceFactor ()) > 1)
    {
		if (BalanceFactor () > 0)
		{
			if (Left ().BalanceFactor () > 0)
				LLRotation ();
			else
				LRRotation ();
		}
		else
		{
			if (Right ().BalanceFactor () < 0)
				RRRotation ();
			else
				RLRotation ();
		}
    }
}

void AVLTree::AttachKey (Object& object)
{
    if (!IsEmpty ())
    	throw std::domain_error ("invalid operation");

    key = &object;
    left = new AVLTree ();
    right = new AVLTree ();
    height = 0;
}

Object& AVLTree::DetachKey ()
{
    height = -1;
    return BST::DetachKey ();
}
