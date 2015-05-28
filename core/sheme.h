#ifndef SHEME_H
#define SHEME_H

#include "box.h"
#include "net.h"

class Sheme
{
public:
	Sheme();



	void Step();

	void AddBox(Box *addbox)
	{
		box.append(addbox);
	}

	void AddNet(Net *addnet)
	{
		net.append(addnet);
	}

	void SetTest001();

private:
	QList<Box*> box;
	QList<Net*> net;
};

#endif // SHEME_H
