#include "box.h"

Box::Box(Box::TypeEnum t, QString nm)
{
	idbox = -1;
	type = t;
	namebox = nm;
	if(t != Box::BoxSource)
	{
		ready = false;
	}
	else
	{
		ready = true;
	}
	boxtree = this;
	readytree = false;
}

void Box::AddPoint(Point *addpoint)
{
	point.append(addpoint);
}

void Box::AddBox(Box *addbox)
{
	box.append(addbox);
}

void Box::AddNet(Net *addnet)
{
	net.append(addnet);
}

QString Box::GetName() const
{
	return namebox;
}

Box::TypeEnum Box::GetType() const
{
	return type;
}

void Box::SetReady(bool r)
{
	ready = r;
}

bool Box::GetReady()
{
	return ready;
}

bool Box::GetReadyBoxListPoint(QList<Point *> lp)
{
	foreach (Point *p, lp) {
		if(p->GetReady() != true)
			return false;
	}
	return true;
}

Box *Box::GetBox(QString nb)
{
	foreach (Box *b, box) {
		if(nb == b->GetName())
		{
			return b;
		}
	}
	return NULL;
}

Point *Box::GetPoint(QString np)
{
	foreach (Point *p, point) {
		if(np == p->GetName()) {
			return p;
		}
	}
	return NULL;
}

QList<Box *> Box::GetListBox(Box::TypeEnum t)
{
	if(t == BoxAll)
		return box;
	QList<Box*> lb;
	foreach (Box *b, box) {
		if(b->GetType() == t) {
			lb<<b;
		}
	}
	return lb;
}

QList<Point *> Box::GetListPoint(Point::TypeEnum t)
{
	if(t == Point::PointAll)
		return point;
	QList<Point*> lp;
	foreach (Point *p, point) {
		if(p->GetType() == t)
		{
			lp<<p;
		}
	}
	return lp;
}

void Box::PrintListPoint(const QList<Point *> lp)
{
	qDebug()<<"List point size ="<<lp.size();
	foreach (Point *p, lp) {
		qDebug()<<p->PointInfo();
	}
}

void Box::PrintListBox(QList<Box *> lb)
{
	foreach (Box *b, lb) {
		qDebug()<<b->GetName();
		QList<Point*> lp = b->GetListPoint(Point::PointAll);
		PrintListPoint(b->GetListPoint(Point::PointAll));
	}
}

bool Box::StepNet()
{
	int count = 0;
	foreach (Net* n, net) {
		if(n->Step())
			count++;
	}
	qDebug()<<"StepNet"<<net.size()<<count<<(net.size() == count);
	return net.size() == count;
}
