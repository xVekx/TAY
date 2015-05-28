#include "sheme.h"

Sheme::Sheme()
{
}

void Sheme::Step()
{
	if(box.size() <= 0)
	{
		qDebug()<<"box.size() <= 0";
		return;
	}

	QHash<Box::TypeEnum,int> btc;
	foreach (Box* b, box)
	{
		Box::TypeEnum bt = b->GetType();
		if(btc.value(bt,-1) == -1)
		{
			btc.insert(bt,1);
			//qDebug()<<"1";
		}
		else
		{
			int c = btc.value(bt)+1;
			btc.insert(bt,c);
			//qDebug()<<"2";
		}
	}

	foreach (Box::TypeEnum bte, btc.keys()) {
		qDebug()<<btc.value(bte);
	}

}

void Sheme::SetTest001()
{
	Box *signal1 = new Box(Box::BoxBegin);
	signal1->AddPoint(new Point(Point::PointOUT,"Out1"));
	AddBox(signal1);

	Box *signal2 = new Box(Box::BoxBegin);
	signal2->AddPoint(new Point(Point::PointOUT,"Out1"));
	AddBox(signal2);

	Box *signal3 = new Box(Box::BoxBegin);
	signal3->AddPoint(new Point(Point::PointOUT,"Out1"));
	AddBox(signal3);

	Box *block1 = new Box(Box::BoxBody);
	AddBox(block1);
}
