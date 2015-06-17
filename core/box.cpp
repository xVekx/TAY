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
	//qDebug()<<"List point size ="<<lp.size();
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
void Box::StepNet2()
{
	foreach (Net *n, net) {
		n->Step2();
	}
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
double k = 2.1;

void Box::BoxFunStep(Box *b,TypeEnum bt,QList<Point*> lpin,QList<Point*> lpout)
{
	switch (bt) {
		case BoxSumm: {
			double summ = 0;
			foreach (Point* pin, lpin) {
				summ += pin->GetValue();
			}
			foreach (Point* pout, lpout) {
				pout->SetValue(summ);
			}
			b->SetReady();
			break;
		}
		case BoxInverted: {
			double summ = 0;
			foreach (Point* pin, lpin) {
				summ += pin->GetValue();
			}
			summ = -summ;
			foreach (Point* pout, lpout) {
				pout->SetValue(summ);
			}
			b->SetReady();
			break;
		}
		case BoxFun1: {
			double res = lpin.at(0)->GetValue() * 1;
			lpout.at(0)->SetValue(res);
			b->SetReady();
			break;
		}
		case BoxFun2: {
			double res =  -lpin.at(0)->GetValue() * 0.9;
			lpout.at(0)->SetValue(res);
			b->SetReady();
			break;
		}
		case BoxTestFun: {
			double summ = 0;
			foreach (Point* pin, lpin) {
				summ += pin->GetValue();
			}

			double z = 1.0f;
			foreach (Point* pout, lpout) {
				pout->SetValue(summ*z);
				z = z + 1.0f;
			}
			b->SetReady();
			break;
		}
		case BoxDrain: {
			b->SetReady();
			break;
		}
		case BoxSheme: {
			boxtree = b;
			break;
		}
		default:
			break;
	}

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
				qDebug()<<"continue";

				continue;
			}

			TypeEnum bt = b->GetType();
			QList<Point*> lpout;
			lpout += b->GetListPoint(Point::PointOUT);

			BoxFunStep(b,bt,lpin,lpout);

			PrintListPoint(lpin);
			PrintListPoint(lpout);
		}
	}
	return true;
}
//---------------------------------------------------------------------------------------------------
bool Box::StepBox2()
{
	QList<Point*> lpin = GetListPoint(Point::PointIN);
	QList<Point*> lpout = GetListPoint(Point::PointOUT);
	TypeEnum bt = GetType();
	BoxFunStep(this,bt,lpin,lpout);
	//PrintListPoint(lpin);
	//PrintListPoint(lpout);
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
