#ifndef NET_H
#define NET_H

#include "point.h"

class Net
{
public:
	Net();
	void AddPointIn(Point *addpointin);
	void AddPointOut(Point *addpointout);

	Point *GetPointBoxIn();
	QList<Point *> GetPointBoxOut();
	bool GetReady();
	void Clean();
	void Step();
private:
	Point* pin;
	QList<Point*> pout;
	bool ready;
	bool ocdetect;
};

#endif // NET_H
