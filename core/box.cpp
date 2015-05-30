#include "box.h"

Box::Box(Box::TypeEnum t, QString nm)
{
	type = t;
	namebox = nm;
	ready = false;
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

bool Box::GetReady() const
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
