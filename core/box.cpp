#include "box.h"
//---------------------------------------------------------------------------------------------------
Box::Box(Box::TypeEnum t, QString nm, int id) {
	Init(t,nm,id);
}
//---------------------------------------------------------------------------------------------------
Box::~Box() {
	Clean();
}
//---------------------------------------------------------------------------------------------------
void Box::Init(Box::TypeEnum t, QString nm, int id)
{
	idbox = id;
	type = t;
	namebox = nm;
	if(t != Box::BoxSource) {
		ready = false;
	}
	else {
		ready = true;
	}
	boxtree = this;
	readytree = false;
}
//---------------------------------------------------------------------------------------------------
void Box::Clean() {
	foreach (Net *n, net) {
		delete n;
	}
	net.clear();
	foreach (Point *p, point) {
		delete p;
	}
	point.clear();
	box.clear();
}
//---------------------------------------------------------------------------------------------------
void Box::AddPoint(Point *addpoint) {
	point.append(addpoint);
}
//---------------------------------------------------------------------------------------------------
void Box::AddBox(Box *addbox) {
	box.append(addbox);
}
//---------------------------------------------------------------------------------------------------
void Box::AddNet(Net *addnet) {
	net.append(addnet);
}
//---------------------------------------------------------------------------------------------------
QString Box::GetName() {
	return namebox;
}
//---------------------------------------------------------------------------------------------------
Box::TypeEnum Box::GetType() {
	return type;
}
//---------------------------------------------------------------------------------------------------
void Box::SetReady(bool r) {
	ready = r;
}
//---------------------------------------------------------------------------------------------------
bool Box::GetReady() {
	return ready;
}
//---------------------------------------------------------------------------------------------------
bool Box::GetReadyBoxListPoint(QList<Point *> lp) {
	foreach (Point *p, lp) {
		if(p->GetReady() != true)
			return false;
	}
	return true;
}
//---------------------------------------------------------------------------------------------------
Box *Box::GetBox(QString nb) {
	foreach (Box *b, box) {
		if(nb == b->GetName())
			return b;
	}
	return NULL;
}
//---------------------------------------------------------------------------------------------------
Point *Box::GetPoint(QString np) {
	foreach (Point *p, point) {
		if(np == p->GetName()) {
			return p;
		}
	}
	return NULL;
}
//---------------------------------------------------------------------------------------------------
QList<Box *> Box::GetListBox(Box::TypeEnum t) {
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
//---------------------------------------------------------------------------------------------------
QList<Point *> Box::GetListPoint(Point::TypeEnum t) {
	if(t == Point::PointAll)
		return point;
	QList<Point*> lp;
	foreach (Point *p, point) {
		if(p->GetType() == t)
			lp<<p;
	}
	return lp;
}
//---------------------------------------------------------------------------------------------------
QList<Net *> Box::GetListNet() {
	return net;
}
//---------------------------------------------------------------------------------------------------
void Box::PrintListPoint(const QList<Point *> lp) {
	qDebug()<<"List point size ="<<lp.size();
	foreach (Point *p, lp) {
		qDebug()<<p->PointInfo();
	}
}
//---------------------------------------------------------------------------------------------------
void Box::PrintListBox(QList<Box *> lb) {
	foreach (Box *b, lb) {
		qDebug()<<b->GetName();
		QList<Point*> lp = b->GetListPoint(Point::PointAll);
		PrintListPoint(b->GetListPoint(Point::PointAll));
	}
}
//---------------------------------------------------------------------------------------------------
bool Box::StepNet() {
	int count = 0;
	foreach (Net* n, net) {
		if(n->Step())
			count++;
	}
	qDebug()<<"StepNet"<<net.size()<<count<<(net.size() == count);
	return net.size() == count;
}
//---------------------------------------------------------------------------------------------------
bool Box::ReadyBox(Box::TypeEnum t) {
	QList<Box*> lb = GetListBox(t);
	foreach (Box* b, lb) {
		if(!b->GetReady())
			return false;
	}
	return true;
}
//---------------------------------------------------------------------------------------------------
bool Box::StepBox(Box::TypeEnum t)
{
	QList<Box*>	lb = GetListBox(t);
	foreach (Box *b, lb) {
		if(!b->GetReady()) {
			qDebug()<<"Box"<<b->GetName();
			QList<Point*> lpin = b->GetListPoint(Point::PointIN);
			if(!GetReadyBoxListPoint(lpin))
			{
				qDebug()<<lpin;
				qDebug()<<"continue";
				continue;
			}

			TypeEnum bt = b->GetType();

			switch (bt) {

				case BoxSumm: {
					QList<Point*> lpout = b->GetListPoint(Point::PointOUT);

					double summ = 0;
					foreach (Point* pin, lpin) {
						summ += pin->GetValue();
					}

					foreach (Point* pout, lpout) {
						pout->SetValue(summ);
					}

					PrintListPoint(lpin);
					PrintListPoint(lpout);

					b->SetReady();
					break;
				}

				case BoxInverted: {
					QList<Point*> lpout = b->GetListPoint(Point::PointOUT);

					double summ = 0;
					foreach (Point* pin, lpin) {
						summ += pin->GetValue();
					}

					summ -= summ;

					foreach (Point* pout, lpout) {
						pout->SetValue(summ);
					}

					PrintListPoint(lpin);
					PrintListPoint(lpout);

					b->SetReady();
					break;
				}

				case BoxFun1: {
					QList<Point*> lpout = b->GetListPoint(Point::PointOUT);

					/*double summ = 0;
					foreach (Point* pin, lpin) {
						summ += pin->GetValue();
					}

					summ -= summ;

					foreach (Point* pout, lpout) {
						pout->SetValue(summ);
					}*/

					double res = 1000 * 1000 * lpin.at(0)->GetValue();
					lpout.at(0)->SetValue(res);

					PrintListPoint(lpin);
					PrintListPoint(lpout);

					b->SetReady();
					break;
				}

				case BoxFun2: {
					QList<Point*> lpout = b->GetListPoint(Point::PointOUT);

					/*double summ = 0;
					foreach (Point* pin, lpin) {
						summ += pin->GetValue();
					}

					summ -= summ;

					foreach (Point* pout, lpout) {
						pout->SetValue(summ);
					}*/

					double res = 0.0001 * lpin.at(0)->GetValue();
					lpout.at(0)->SetValue(res);

					PrintListPoint(lpin);
					PrintListPoint(lpout);

					b->SetReady();
					break;
				}


				case BoxTestFun: {

					QList<Point*> lpout = b->GetListPoint(Point::PointOUT);

					double summ = 0;
					foreach (Point* pin, lpin) {
						summ += pin->GetValue();
					}

					double z = 1.0f;
					foreach (Point* pout, lpout) {
						pout->SetValue(summ*z);
						z = z + 1.0f;
					}

					PrintListPoint(lpin);
					PrintListPoint(lpout);

					b->SetReady();
					break;
				}

				case BoxDrain: {
					b->SetReady();
					break;
				}

				case BoxSheme:
				{
					boxtree = b;
					break;
				}

				default:
					break;
			}
		}
	}
	return true;
}
//---------------------------------------------------------------------------------------------------
void Box::SetBoxTreeThis() {
	boxtree = this;
}
//---------------------------------------------------------------------------------------------------
Box *Box::CurrentBoxTree()
{
	return boxtree;
}
//---------------------------------------------------------------------------------------------------
void Box::SetIdBox(int id)
{
	idbox = id;
}
//---------------------------------------------------------------------------------------------------
int Box::GetIdBox()
{
	return idbox;
}
//---------------------------------------------------------------------------------------------------
int Box::GetListBoxSize()
{
	return box.size();
}
//---------------------------------------------------------------------------------------------------
bool Box::StatusListBoxId()
{
	foreach (Box *b, box)
	{
		if(b->GetIdBox() == -1)
			return false;
	}
	return true;
}
//---------------------------------------------------------------------------------------------------
void Box::SetReadyTree(bool r)
{
	readytree = r;
}
//---------------------------------------------------------------------------------------------------
bool Box::GetReadyTree()
{
	return readytree;
}
//---------------------------------------------------------------------------------------------------
