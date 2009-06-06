/*
 * Enumeration.h
 *
 *  Created on: 06/06/2009
 *      Author: fabricio
 */

#ifndef ENUMERATION_H_
#define ENUMERATION_H_

#include "Ownership.h"
#include "Container.h"

class Enumeration: public virtual Ownership
{
	public:
		Enumeration(Container&);
		bool hasMoreElements ();
		Object& nextElement ();
		virtual ~Enumeration();

	protected:
		Iterator &it;
		Container &c;
};

#endif /* ENUMERATION_H_ */
