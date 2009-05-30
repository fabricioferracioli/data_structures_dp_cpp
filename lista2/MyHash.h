/*
 * Hash.h
 *
 *  Created on: 15/05/2009
 *      Author: fabricio
 */

#ifndef MYHASH_H_
#define MYHASH_H_

#include <string>
#include <stdlib.h>
#include <math.h>

typedef unsigned int HashValue;

class MyHash {
public:
	MyHash();

	HashValue Hash (char);

	HashValue Hash (int);

	HashValue Hash (double);

	HashValue Hash (std::string const&);

	virtual ~MyHash();
};

#endif /* MYHASH_H_ */
