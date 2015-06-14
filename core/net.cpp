#include "net.h"

Net::Net()
{
	ready = false;
	ocdetect = false;
}

Net::~Net()
{
	pout.clear();
	bout.clear();
}

void Net::AddPointIn(Point *addpointin, void* boxin)
{
	pin = addpointin;
	bin = boxin;
}

void Net::AddPointOut(Point *addpointout, void *boxout)
{
	pout.append(addpointout);
	bout.append(boxout);
}

Point *Net::GetPointBoxIn()
{
	return pin;
}

QList<Point *> Net::GetPointBoxOut()
{
	return pout;
}

bool Net::GetReady()
{
	return ready;
}

void Net::Clean()
{
	pin->Clean();

	for(int p=0;p<pout.size();p++)
	{
		pout[p]->Clean();
	}
	ready = false;
	ocdetect = false;
}

bool Net::Step()
{
	if(!ready && pin->GetReady())
	{
		for(int i=0;i<pout.size();i++)
		{
			pout[i]->SetValue(pin->GetValue());
		}
		ready = true;
	}
	return ready;
}
