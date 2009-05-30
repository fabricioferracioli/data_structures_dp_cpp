/*
 * Ownership.h
 *
 *  Created on: 18/05/2009
 *      Author: fabricio
 */

#ifndef OWNERSHIP_H_
#define OWNERSHIP_H_

class Ownership
{
    bool isOwner;
protected:
    Ownership () : isOwner (true)
	{}
    Ownership (Ownership& arg) : isOwner (arg.isOwner)
	{ arg.isOwner = false; }
public:
    void AssertOwnership ()
	{ isOwner = true; }
    void RescindOwnership ()
	{ isOwner = false; }
    bool IsOwner () const
	{ return isOwner; }
};

#endif /* OWNERSHIP_H_ */
