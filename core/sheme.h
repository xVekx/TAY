#ifndef SHEME_H
#define SHEME_H

#include "box.h"

#include <QStack>

class Sheme : public Box
{
public:
	Sheme();

	bool Step();
	void TestSheme001();
	void TestSheme002();
	void TestSheme003();
};

#endif // SHEME_H
