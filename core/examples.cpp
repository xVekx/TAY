#include "examples.h"
//---------------------------------------------------------------------------------------------------
Examples::Examples()
{

}
//---------------------------------------------------------------------------------------------------
void Examples::TestSheme001(Box *b)
{
	qDebug()<<"TestSheme001";

	//Источники
	Box *s1 = new Box(Box::BoxSource,"S1");
	{
		s1->AddPoint(new Point(Point::PointOUT,"S1Out1"));
	}
	b->AddBox(s1);

	Box *s2 = new Box(Box::BoxSource,"S2");
	{
		s2->AddPoint(new Point(Point::PointOUT,"S2Out1"));
	}
	b->AddBox(s2);

	Box *s3 = new Box(Box::BoxSource,"S3");
	{
		s3->AddPoint(new Point(Point::PointOUT,"S3Out1"));
	}
	b->AddBox(s3);

	//Функции
	Box *b1 = new Box(Box::BoxTestFun,"B1");
	{
		b1->AddPoint(new Point(Point::PointIN,"B1In1"));
		b1->AddPoint(new Point(Point::PointIN,"B1In2"));
		b1->AddPoint(new Point(Point::PointIN,"B1In3"));

		b1->AddPoint(new Point(Point::PointOUT,"B1Out1"));
		b1->AddPoint(new Point(Point::PointOUT,"B1Out2"));
	}
	b->AddBox(b1);

	//Приемники
	Box *d1 = new Box(Box::BoxDrain,"D1");
	{
		d1->AddPoint(new Point(Point::PointIN,"D1In1"));
	}
	b->AddBox(d1);

	Box *d2 = new Box(Box::BoxDrain,"D2");
	{
		d2->AddPoint(new Point(Point::PointIN,"D2In1"));
	}
	b->AddBox(d2);

	//Связи
	Net *ns1 = new Net();
	{
		ns1->AddPointIn(GetBox("S1")->GetPoint("S1Out1"));
		ns1->AddPointOut(GetBox("B1")->GetPoint("B1In1"));
	}
	b->AddNet(ns1);

	Net *ns2 = new Net();
	{
		ns2->AddPointIn(GetBox("S2")->GetPoint("S2Out1"));
		ns2->AddPointOut(GetBox("B1")->GetPoint("B1In2"));
	}
	b->AddNet(ns2);

	Net *ns3 = new Net();
	{
		ns3->AddPointIn(GetBox("S3")->GetPoint("S3Out1"));
		ns3->AddPointOut(GetBox("B1")->GetPoint("B1In3"));
	}
	b->AddNet(ns3);

	Net *nd1 = new Net();
	{
		nd1->AddPointIn(GetBox("B1")->GetPoint("B1Out1"));
		nd1->AddPointOut(GetBox("D1")->GetPoint("D1In1"));
	}
	b->AddNet(nd1);

	Net *nd2 = new Net();
	{
		nd2->AddPointIn(GetBox("B1")->GetPoint("B1Out2"));
		nd2->AddPointOut(GetBox("D2")->GetPoint("D2In1"));
	}
	b->AddNet(nd2);

	b->GetBox("S1")->GetPoint("S1Out1")->SetValue(1.1);
	b->GetBox("S2")->GetPoint("S2Out1")->SetValue(2.2);
	b->GetBox("S3")->GetPoint("S3Out1")->SetValue(3.3);
}
//---------------------------------------------------------------------------------------------------
void Examples::TestSheme002(Box *b)
{
	qDebug()<<"TestSheme002";
	//Источники
	Box *s1 = new Box(Box::BoxSource,"S1");
	{
		s1->AddPoint(new Point(Point::PointOUT,"S1Out1"));
	}
	b->AddBox(s1);

	Box *s2 = new Box(Box::BoxSource,"S2");
	{
		s2->AddPoint(new Point(Point::PointOUT,"S2Out1"));
	}
	b->AddBox(s2);

	Box *s3 = new Box(Box::BoxSource,"S3");
	{
		s3->AddPoint(new Point(Point::PointOUT,"S3Out1"));
	}
	b->AddBox(s3);

	//Бокс
	Box *b1 = new Box(Box::BoxTestFun,"B1");
	{
		b1->AddPoint(new Point(Point::PointIN,"B1In1"));
		b1->AddPoint(new Point(Point::PointIN,"B1In2"));
		b1->AddPoint(new Point(Point::PointIN,"B1In3"));

		b1->AddPoint(new Point(Point::PointOUT,"B1Out1"));
		b1->AddPoint(new Point(Point::PointOUT,"B1Out2"));
	}
	b->AddBox(b1);

	Box *b2 = new Box(Box::BoxTestFun,"B2");
	{
		b2->AddPoint(new Point(Point::PointIN,"B2In1"));
		b2->AddPoint(new Point(Point::PointIN,"B2In2"));

		b2->AddPoint(new Point(Point::PointOUT,"B2Out1"));
	}
	b->AddBox(b2);

	//Приемники
	Box *d1 = new Box(Box::BoxDrain,"D1");
	{
		d1->AddPoint(new Point(Point::PointIN,"D1In1"));
	}
	b->AddBox(d1);

	Box *d2 = new Box(Box::BoxDrain,"D2");
	{
		d2->AddPoint(new Point(Point::PointIN,"D2In1"));
	}
	b->AddBox(d2);

	Box *d3 = new Box(Box::BoxDrain,"D3");
	{
		d3->AddPoint(new Point(Point::PointIN,"D3In1"));
	}
	b->AddBox(d3);

	//Связи
	Net *ns1 = new Net();
	{
		ns1->AddPointIn(GetBox("S1")->GetPoint("S1Out1"));
		ns1->AddPointOut(GetBox("B1")->GetPoint("B1In1"));
	}
	b->AddNet(ns1);

	Net *ns2 = new Net();
	{
		ns2->AddPointIn(GetBox("S2")->GetPoint("S2Out1"));
		ns2->AddPointOut(GetBox("B1")->GetPoint("B1In2"));
	}
	b->AddNet(ns2);

	Net *ns3 = new Net();
	{
		ns3->AddPointIn(GetBox("S3")->GetPoint("S3Out1"));
		ns3->AddPointOut(GetBox("B1")->GetPoint("B1In3"));
	}
	b->AddNet(ns3);

	Net *ns4 = new Net();
	{
		ns4->AddPointIn(GetBox("B1")->GetPoint("B1Out1"));
		ns4->AddPointOut(GetBox("B2")->GetPoint("B2In1"));
	}
	b->AddNet(ns4);

	Net *ns5 = new Net();
	{
		ns5->AddPointIn(GetBox("B1")->GetPoint("B1Out2"));
		ns5->AddPointOut(GetBox("B2")->GetPoint("B2In2"));
	}
	b->AddNet(ns5);

	Net *nd1 = new Net();
	{
		nd1->AddPointIn(GetBox("B1")->GetPoint("B1Out1"));
		nd1->AddPointOut(GetBox("D1")->GetPoint("D1In1"));
	}
	b->AddNet(nd1);

	Net *nd2 = new Net();
	{
		nd2->AddPointIn(GetBox("B1")->GetPoint("B1Out2"));
		nd2->AddPointOut(GetBox("D2")->GetPoint("D2In1"));
	}
	b->AddNet(nd2);

	Net *nd3 = new Net();
	{
		nd3->AddPointIn(GetBox("B2")->GetPoint("B2Out1"));
		nd3->AddPointOut(GetBox("D3")->GetPoint("D3In1"));
	}
	b->AddNet(nd3);

	b->GetBox("S1")->GetPoint("S1Out1")->SetValue(1.1);
	b->GetBox("S2")->GetPoint("S2Out1")->SetValue(2.2);
	b->GetBox("S3")->GetPoint("S3Out1")->SetValue(3.3);
}
//---------------------------------------------------------------------------------------------------
void Examples::TestSheme003(Box *b)
{
	qDebug()<<"TestSheme003";
	//Источники
	Box *s1 = new Box(Box::BoxSource,"S1");
	{
		s1->AddPoint(new Point(Point::PointOUT,"S1Out1"));
		b->AddBox(s1);
	}

	Box *s2 = new Box(Box::BoxSource,"S2");
	{
		s2->AddPoint(new Point(Point::PointOUT,"S2Out1"));
		b->AddBox(s2);
	}

	Box *s3 = new Box(Box::BoxSource,"S3");
	{
		s3->AddPoint(new Point(Point::PointOUT,"S3Out1"));
		b->AddBox(s3);
	}

	//Бокс
	Box *b1 = new Box(Box::BoxTestFun,"B1");
	{
		b1->AddPoint(new Point(Point::PointIN,"B1In1"));
		b1->AddPoint(new Point(Point::PointIN,"B1In2"));
		b1->AddPoint(new Point(Point::PointIN,"B1In3"));

		b1->AddPoint(new Point(Point::PointOUT,"B1Out1"));
		b1->AddPoint(new Point(Point::PointOUT,"B1Out2"));
		b->AddBox(b1);
	}

	Box *b2 = new Box(Box::BoxTestFun,"B2");
	{
		b2->AddPoint(new Point(Point::PointIN,"B2In1"));
		b2->AddPoint(new Point(Point::PointIN,"B2In2"));
		b2->AddPoint(new Point(Point::PointOUT,"B2Out1"));
		b->AddBox(b2);

		Box *b21 = new Box(Box::BoxTestFun, "B21");

		{
			b21->AddPoint(new Point(Point::PointIN,"B21In1"));
			b21->AddPoint(new Point(Point::PointOUT,"B21Out1"));

			Box *b211 = new Box(Box::BoxTestFun, "B211");
			{
				b21->AddBox(b211);
			}
			b2->AddBox(b21);
		}

		Box *b22 = new Box(Box::BoxTestFun, "B22");
		{
			b22->AddPoint(new Point(Point::PointIN,"B22In1"));
			b22->AddPoint(new Point(Point::PointIN,"B22In2"));
			b22->AddPoint(new Point(Point::PointOUT,"B22Out1"));
			b2->AddBox(b22);
		}

		Net *ns21 = new Net();
		{
			ns21->AddPointIn(GetBox("B2")->GetPoint("B2In1"),b2);
			ns21->AddPointOut(GetBox("B2")->GetBox("B21")->GetPoint("B21In1"),b21);
		}
		b2->AddNet(ns21);

		Net *ns22 = new Net();
		{
			ns22->AddPointIn(GetBox("B2")->GetPoint("B2In2"));
			ns22->AddPointOut(GetBox("B2")->GetBox("B22")->GetPoint("B22In2"));
		}
		b2->AddNet(ns22);

		Net *nb21 = new Net();
		{
			nb21->AddPointIn(GetBox("B2")->GetBox("B21")->GetPoint("B21Out1"),b21);
			nb21->AddPointOut(GetBox("B2")->GetBox("B22")->GetPoint("B22In1"),b22);
		}
		b2->AddNet(nb21);

		Net *nd22 = new Net();
		{
			nd22->AddPointIn(GetBox("B2")->GetBox("B22")->GetPoint("B22Out1"));
			nd22->AddPointOut(GetBox("B2")->GetPoint("B2Out1"));
		}
		b2->AddNet(nd22);
	}
	//Приемники
	Box *d1 = new Box(Box::BoxDrain,"D1");
	{
		d1->AddPoint(new Point(Point::PointIN,"D1In1"));
	}
	b->AddBox(d1);

	Box *d2 = new Box(Box::BoxDrain,"D2");
	{
		d2->AddPoint(new Point(Point::PointIN,"D2In1"));
	}
	b->AddBox(d2);

	Box *d3 = new Box(Box::BoxDrain,"D3");
	{
		d3->AddPoint(new Point(Point::PointIN,"D3In1"));
	}
	b->AddBox(d3);

	//Связи
	Net *ns1 = new Net();
	{
		ns1->AddPointIn(GetBox("S1")->GetPoint("S1Out1"));
		ns1->AddPointOut(GetBox("B1")->GetPoint("B1In1"));
	}
	b->AddNet(ns1);

	Net *ns2 = new Net();
	{
		ns2->AddPointIn(GetBox("S2")->GetPoint("S2Out1"));
		ns2->AddPointOut(GetBox("B1")->GetPoint("B1In2"));
	}
	b->AddNet(ns2);

	Net *ns3 = new Net();
	{
		ns3->AddPointIn(GetBox("S3")->GetPoint("S3Out1"));
		ns3->AddPointOut(GetBox("B1")->GetPoint("B1In3"));
	}
	b->AddNet(ns3);

	Net *ns4 = new Net();
	{
		ns4->AddPointIn(GetBox("B1")->GetPoint("B1Out1"));
		ns4->AddPointOut(GetBox("B2")->GetPoint("B2In1"));
	}
	b->AddNet(ns4);

	Net *ns5 = new Net();
	{
		ns5->AddPointIn(GetBox("B1")->GetPoint("B1Out2"));
		ns5->AddPointOut(GetBox("B2")->GetPoint("B2In2"));
	}
	b->AddNet(ns5);

	Net *nd1 = new Net();
	{
		nd1->AddPointIn(GetBox("B1")->GetPoint("B1Out1"));
		nd1->AddPointOut(GetBox("D1")->GetPoint("D1In1"));
	}
	b->AddNet(nd1);

	Net *nd2 = new Net();
	{
		nd2->AddPointIn(GetBox("B1")->GetPoint("B1Out2"));
		nd2->AddPointOut(GetBox("D2")->GetPoint("D2In1"));
	}
	b->AddNet(nd2);

	Net *nd3 = new Net();
	{
		nd3->AddPointIn(GetBox("B2")->GetPoint("B2Out1"));
		nd3->AddPointOut(GetBox("D3")->GetPoint("D3In1"));
	}
	b->AddNet(nd3);

	b->GetBox("S1")->GetPoint("S1Out1")->SetValue(1.1);
	b->GetBox("S2")->GetPoint("S2Out1")->SetValue(2.2);
	b->GetBox("S3")->GetPoint("S3Out1")->SetValue(3.3);
}
//---------------------------------------------------------------------------------------------------
void Examples::TestSheme004(Box *b)
{
	Box *s1 = new Box(Box::BoxSource,"S1");
	{
		s1->AddPoint(new Point(Point::PointOUT,"S1Out1"));
	}
	b->AddBox(s1);

	Box *f1 = new Box(Box::BoxSumm,"F1");
	{
		f1->AddPoint(new Point(Point::PointIN,"F1In1"));
		f1->AddPoint(new Point(Point::PointIN,"F1In2"));
		f1->AddPoint(new Point(Point::PointOUT,"F1Out1"));
	}
	b->AddBox(f1);

	Box *f2 = new Box(Box::BoxFun1,"F2");
	{
		f2->AddPoint(new Point(Point::PointIN,"F2In1"));
		f2->AddPoint(new Point(Point::PointOUT,"F2Out1"));
	}
	b->AddBox(f2);

	Box *f3 = new Box(Box::BoxFun2,"F3");
	{
		f3->AddPoint(new Point(Point::PointIN,"F3In1"));
		f3->AddPoint(new Point(Point::PointOUT,"F3Out1"));
	}
	b->AddBox(f3);

	Box *f4 = new Box(Box::BoxInverted,"F4");
	{
		f4->AddPoint(new Point(Point::PointIN,"F4In1"));
		f4->AddPoint(new Point(Point::PointOUT,"F4Out1"));
	}
	b->AddBox(f4);

	Box *d1 = new Box(Box::BoxDrain,"D1");
	{
		d1->AddPoint(new Point(Point::PointIN,"D1In1"));
	}
	b->AddBox(d1);

	Net *n1 = new Net();
	{
		n1->AddPointIn(GetBox("S1")->GetPoint("S1Out1"));
		n1->AddPointOut(GetBox("F1")->GetPoint("F1In1"));
	}
	b->AddNet(n1);

	Net *n2 = new Net();
	{
		n2->AddPointIn(GetBox("F1")->GetPoint("F1Out1"));
		n2->AddPointOut(GetBox("F2")->GetPoint("F2In1"));
	}
	b->AddNet(n2);

	Net *n3 = new Net();
	{
		n3->AddPointIn(GetBox("F2")->GetPoint("F2Out1"));
		n3->AddPointOut(GetBox("F3")->GetPoint("F3In1"));
		n3->AddPointOut(GetBox("D1")->GetPoint("D1In1"));
	}
	b->AddNet(n3);

	Net *n4 = new Net();
	{
		n4->AddPointIn(GetBox("F3")->GetPoint("F3Out1"));
		n4->AddPointOut(GetBox("F4")->GetPoint("F4In1"));
	}
	b->AddNet(n4);

	Net *n5 = new Net();
	{
		n5->AddPointIn(GetBox("F4")->GetPoint("F4Out1"));
		n5->AddPointOut(GetBox("F1")->GetPoint("F1In2"));
	}
	b->AddNet(n5);

	b->GetBox("S1")->GetPoint("S1Out1")->SetValue(0.01);
}
//---------------------------------------------------------------------------------------------------

