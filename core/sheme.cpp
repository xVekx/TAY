#include "sheme.h"

Sheme::Sheme()
{

}

void Sheme::TestSheme001()
{
	//Источники
	Box *s1 = new Box(Box::BoxSource,"S1");
	{
		s1->AddPoint(new Point(Point::PointOUT,"S1Out1"));
	}
	AddBox(s1);

	Box *s2 = new Box(Box::BoxSource,"S2");
	{
		s2->AddPoint(new Point(Point::PointOUT,"S2Out1"));
	}
	AddBox(s2);

	Box *s3 = new Box(Box::BoxSource,"S3");
	{
		s3->AddPoint(new Point(Point::PointOUT,"S3Out1"));
	}
	AddBox(s3);

	//Бокс
	Box *b1 = new Box(Box::BoxTestFun,"B1");
	{
		b1->AddPoint(new Point(Point::PointIN,"B1In1"));
		b1->AddPoint(new Point(Point::PointIN,"B1In2"));
		b1->AddPoint(new Point(Point::PointIN,"B1In3"));

		b1->AddPoint(new Point(Point::PointOUT,"B1Out1"));
		b1->AddPoint(new Point(Point::PointOUT,"B1Out2"));
	}
	AddBox(b1);

	//Приемники
	Box *d1 = new Box(Box::BoxDrain,"D1");
	{
		d1->AddPoint(new Point(Point::PointIN,"D1In1"));
	}
	AddBox(d1);

	Box *d2 = new Box(Box::BoxDrain,"D2");
	{
		d2->AddPoint(new Point(Point::PointIN,"D2In1"));
	}
	AddBox(d2);

	//Связи
	Net *ns1 = new Net();
	{
		ns1->AddPointIn(GetBox("S1")->GetPoint("S1Out1"));
		ns1->AddPointOut(GetBox("B1")->GetPoint("B1In1"));
	}
	AddNet(ns1);

	qDebug()<<"Net S 2";

	Net *ns2 = new Net();
	{
		ns2->AddPointIn(GetBox("S2")->GetPoint("S2Out1"));
		ns2->AddPointOut(GetBox("B1")->GetPoint("B1In2"));
	}
	AddNet(ns2);

	Net *ns3 = new Net();
	{
		ns3->AddPointIn(GetBox("S3")->GetPoint("S3Out1"));
		ns3->AddPointOut(GetBox("B1")->GetPoint("B1In3"));
	}
	AddNet(ns3);


	Net *nd1 = new Net();
	{
		nd1->AddPointIn(GetBox("B1")->GetPoint("B1Out1"));
		nd1->AddPointOut(GetBox("D1")->GetPoint("D1In1"));
	}
	AddNet(nd1);

	Net *nd2 = new Net();
	{
		nd2->AddPointIn(GetBox("B1")->GetPoint("B1Out2"));
		nd2->AddPointOut(GetBox("D2")->GetPoint("D2In1"));
	}
	AddNet(nd2);

	GetBox("S1")->GetPoint("S1Out1")->SetValue(1.1);
	GetBox("S2")->GetPoint("S2Out1")->SetValue(2.2);
	GetBox("S3")->GetPoint("S3Out1")->SetValue(3.3);

}

bool Sheme::Step()
{
	qDebug()<<"Step";
	//PrintListBox(GetListBox(Box::BoxSource));
	//PrintListBox(GetListBox(Box::BoxDrain));

	for(int z=0;z<10;z++)
	{
		StepNet();
		if(StepBox(Box::BoxAll))
			break;
	}
	PrintListBox(GetListBox(Box::BoxSource));
	PrintListBox(GetListBox(Box::BoxDrain));
	return false;
}
