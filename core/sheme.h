#ifndef SHEME_H
#define SHEME_H

#include "box.h"

class Sheme : public Box
{
public:
	Sheme();

	bool Step();
	void TestSheme001();
	void TestSheme002();
};

#endif // SHEME_H
