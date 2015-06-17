#ifndef EXAMPLES_H
#define EXAMPLES_H

#include "scheme.h"

class Examples: public Scheme
{
public:
	Examples();
	void TestSheme001(Box *b);
	void TestSheme002(Box *b);
	void TestSheme003(Box *b);
	void TestSheme004(Box *b);
};

#endif // EXAMPLES_H
