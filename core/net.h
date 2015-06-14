#ifndef NET_H
#define NET_H

#include "point.h"

class NetPointBox
{
public:
	NetPointBox(Point *p,void *b)
	{
		point = p;
		box = b;
	}

	void *GetBox()
	{
		return box;
	}

	Point *GetPoint()
	{
		return point;
	}

private:
	void *box;
	Point *point;
};

class Net
{
public:
	Net();
	~Net();
	void AddPointIn(Point *addpointin, void* boxin = NULL);
	void AddPointOut(Point *addpointout, void* boxout = NULL);

	Point *GetPointBoxIn();
	QList<Point *> GetPointBoxOut();

	NetPointBox GetNetBoxPointIn()
	{
		NetPointBox npb(pin,bin);
		return npb;
	}

	QList<NetPointBox> GetNetBoxPointOut()
	{
		QList<NetPointBox> lnpb;

		for(int n=0;n<pout.size();n++)
		{
			lnpb.append(NetPointBox(pout.at(n),bout.at(n)));
		}

		return lnpb;
	}

	bool GetReady();
	void Clean();
	bool Step();
private:
	Point* pin;
	void* bin;
	QList<Point*> pout;
	QList<void*> bout;
	bool ready;
	bool ocdetect;
};

#endif // NET_H
