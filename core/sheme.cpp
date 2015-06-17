#include "sheme.h"

Sheme::Sheme() : Box(BoxSheme)
{
	//type = BoxSheme;
}

void Sheme::TestSheme001()
{
	qDebug()<<"TestSheme001";
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

void Sheme::TestSheme002()
{
	qDebug()<<"TestSheme002";
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

	Box *b2 = new Box(Box::BoxTestFun,"B2");
	{
		b2->AddPoint(new Point(Point::PointIN,"B2In1"));
		b2->AddPoint(new Point(Point::PointIN,"B2In2"));

		b2->AddPoint(new Point(Point::PointOUT,"B2Out1"));
	}
	AddBox(b2);

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

	Box *d3 = new Box(Box::BoxDrain,"D3");
	{
		d3->AddPoint(new Point(Point::PointIN,"D3In1"));
	}
	AddBox(d3);

	//Связи
	Net *ns1 = new Net();
	{
		ns1->AddPointIn(GetBox("S1")->GetPoint("S1Out1"));
		ns1->AddPointOut(GetBox("B1")->GetPoint("B1In1"));
	}
	AddNet(ns1);

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

	Net *ns4 = new Net();
	{
		ns4->AddPointIn(GetBox("B1")->GetPoint("B1Out1"));
		ns4->AddPointOut(GetBox("B2")->GetPoint("B2In1"));
	}
	AddNet(ns4);

	Net *ns5 = new Net();
	{
		ns5->AddPointIn(GetBox("B1")->GetPoint("B1Out2"));
		ns5->AddPointOut(GetBox("B2")->GetPoint("B2In2"));
	}
	AddNet(ns5);

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

	Net *nd3 = new Net();
	{
		nd3->AddPointIn(GetBox("B2")->GetPoint("B2Out1"));
		nd3->AddPointOut(GetBox("D3")->GetPoint("D3In1"));
	}
	AddNet(nd3);

	GetBox("S1")->GetPoint("S1Out1")->SetValue(1.1);
	GetBox("S2")->GetPoint("S2Out1")->SetValue(2.2);
	GetBox("S3")->GetPoint("S3Out1")->SetValue(3.3);
}

void Sheme::TestSheme003()
{
	qDebug()<<"TestSheme003";
	//Источники
	Box *s1 = new Box(Box::BoxSource,"S1");
	{
		s1->AddPoint(new Point(Point::PointOUT,"S1Out1"));
		AddBox(s1);
	}

	Box *s2 = new Box(Box::BoxSource,"S2");
	{
		s2->AddPoint(new Point(Point::PointOUT,"S2Out1"));
		AddBox(s2);
	}

	Box *s3 = new Box(Box::BoxSource,"S3");
	{
		s3->AddPoint(new Point(Point::PointOUT,"S3Out1"));
		AddBox(s3);
	}

	//Бокс
	Box *b1 = new Box(Box::BoxTestFun,"B1");
	{
		b1->AddPoint(new Point(Point::PointIN,"B1In1"));
		b1->AddPoint(new Point(Point::PointIN,"B1In2"));
		b1->AddPoint(new Point(Point::PointIN,"B1In3"));

		b1->AddPoint(new Point(Point::PointOUT,"B1Out1"));
		b1->AddPoint(new Point(Point::PointOUT,"B1Out2"));
		AddBox(b1);
	}

	Box *b2 = new Box(Box::BoxTestFun,"B2");
	{
		b2->AddPoint(new Point(Point::PointIN,"B2In1"));
		b2->AddPoint(new Point(Point::PointIN,"B2In2"));
		b2->AddPoint(new Point(Point::PointOUT,"B2Out1"));

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

		AddBox(b2);

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
	AddBox(d1);

	Box *d2 = new Box(Box::BoxDrain,"D2");
	{
		d2->AddPoint(new Point(Point::PointIN,"D2In1"));
	}
	AddBox(d2);

	Box *d3 = new Box(Box::BoxDrain,"D3");
	{
		d3->AddPoint(new Point(Point::PointIN,"D3In1"));
	}
	AddBox(d3);

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

	Net *ns4 = new Net();
	{
		ns4->AddPointIn(GetBox("B1")->GetPoint("B1Out1"));
		ns4->AddPointOut(GetBox("B2")->GetPoint("B2In1"));
	}
	AddNet(ns4);

	Net *ns5 = new Net();
	{
		ns5->AddPointIn(GetBox("B1")->GetPoint("B1Out2"));
		ns5->AddPointOut(GetBox("B2")->GetPoint("B2In2"));
	}
	AddNet(ns5);


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

	Net *nd3 = new Net();
	{
		nd3->AddPointIn(GetBox("B2")->GetPoint("B2Out1"));
		nd3->AddPointOut(GetBox("D3")->GetPoint("D3In1"));
	}
	AddNet(nd3);

	GetBox("S1")->GetPoint("S1Out1")->SetValue(1.1);
	GetBox("S2")->GetPoint("S2Out1")->SetValue(2.2);
	GetBox("S3")->GetPoint("S3Out1")->SetValue(3.3);
}

void Sheme::SetAttrDomElement(QDomDocument &dd, QDomElement &de, QString attr, QString str)
{
	if(!str.isEmpty())
	{
		QDomAttr domAttr = dd.createAttribute(attr);
		domAttr.setValue(str);
		de.setAttributeNode(domAttr);
	}
}

QString Sheme::GetNameBox(Box *box, NetPointBox npb)
{
	if(npb.GetBox() != NULL) {
		if(npb.GetBox() == box) {
			return box->GetName();
		}
		else {
			Box *s = (Box*)npb.GetBox();
			int i = box->GetListBox().indexOf(s);
			if(i != -1) {
				return box->GetListBox().at(i)->GetName();
			}
		}
	}
	else {
		int i = box->GetListPoint().indexOf(npb.GetPoint());
		if(i != -1) {
			return box->GetName();
		}
		else {
			foreach (Box *b, box->GetListBox()) {
				int i = b->GetListPoint().indexOf(npb.GetPoint());
				if(i != -1) {
					return b->GetName();
				}
			}
		}
	}
	return QString();
}

QDomElement Sheme::BoxDomElement(QDomDocument &domdoc, Box *box)
{
	QDomElement bde = domdoc.createElement("box");
	SetAttrDomElement(domdoc,bde,"name",box->GetName());
	SetAttrDomElement(domdoc,bde,"id",QString("%1").arg(box->GetIdBox()));
	SetAttrDomElement(domdoc,bde,"type",QString("%1").arg(box->GetType()));

	foreach (Point *p, box->GetListPoint()) {
		QDomElement de = domdoc.createElement("point");
		SetAttrDomElement(domdoc,de,"name",p->GetName());
		SetAttrDomElement(domdoc,de,"type",QString("%1").arg(p->GetType()));
		if(box->GetType() == BoxSource)
		{
			SetAttrDomElement(domdoc,de,"value",QString("%1").arg(p->GetValue()));
		}
		bde.appendChild(de);
	}

	foreach (Box *b, box->GetListBox()) {
		QDomElement de = domdoc.createElement("inbox");
		SetAttrDomElement(domdoc,de,"id",QString("%1").arg(b->GetIdBox()));
		bde.appendChild(de);
	}

	foreach (Net *n, box->GetListNet())
	{
		QDomElement de = domdoc.createElement("net");

		QDomElement dein = domdoc.createElement("in");
		SetAttrDomElement(domdoc,dein,"box",GetNameBox(box,n->GetNetBoxPointIn()));
		SetAttrDomElement(domdoc,dein,"point",n->GetPointBoxIn()->GetName());
		de.appendChild(dein);

		foreach (NetPointBox npbout, n->GetNetBoxPointOut()) {
			QDomElement deout = domdoc.createElement("out");
			SetAttrDomElement(domdoc,deout,"box",GetNameBox(box,npbout));
			SetAttrDomElement(domdoc,deout,"point",npbout.GetPoint()->GetName());
			de.appendChild(deout);
		}
		bde.appendChild(de);
	}

	return bde;
}

void BoxInfo(Box* b)
{
	qDebug()<<"Box"<<b->GetName()<<b->GetReadyTree();
}

void Sheme::SetIdAllSheme()
{
	QList<Box*> lb;
	AllListBox(lb);
	int n = 0;
	foreach (Box* b, lb) {
		b->SetIdBox(n);
		n++;
	}
}

bool Sheme::Save(QString FileName)
{
	SetIdAllSheme();
	QDomDocument sd("Sheme");
	QDomElement  de = sd.createElement("elements");
	sd.appendChild(de);

	QList<Box*> lb;
	AllListBox(lb);
	foreach (Box* b, lb)
	{
		QDomElement bde = BoxDomElement(sd,b);
		de.appendChild(bde);
	}

	QFile file(FileName);
	if(!file.open(QIODevice::WriteOnly))
	{
		qDebug()<<"Not open save file:"<<FileName;
		return false;
	}
	QTextStream(&file) << sd.toString();
	//qDebug()<<sd.toString();
	file.close();
	return true;
}

Box* Sheme::AddBoxDE(QDomElement de) {
	Box *b;
	QString namebox = de.attribute("name");
	bool ok;
	TypeEnum typebox = (TypeEnum)de.attribute("type").toInt(&ok);
	if(!ok)
		return NULL;
	int idbox = de.attribute("id").toInt();
	qDebug()<<namebox<<typebox<<idbox;

	if(typebox != BoxSheme)
		b = new Box(typebox,namebox,idbox);
	else {
		b = this;
		b->Init(typebox,namebox,idbox);
	}

	QDomNodeList dnlp = de.elementsByTagName("point");

	for(int i=0;i<dnlp.size();i++) {
		QString namepoint = dnlp.at(i).toElement().attribute("name");
		Point::TypeEnum typepoint = (Point::TypeEnum)dnlp.at(i).toElement().attribute("type").toInt(&ok);
		if(!ok)
			return NULL;
		qDebug()<<" "<<namepoint<<typebox;
		b->AddPoint(new Point(typepoint,namepoint));

		QString valuepoint = dnlp.at(i).toElement().attribute("value");
		if(!valuepoint.isEmpty())
		{
			qDebug()<<"SetValue"<<valuepoint.toDouble();
			b->GetPoint(namepoint)->SetValue(valuepoint.toDouble());
		}
	}
	return b;
}

bool Sheme::Load(QString FileName)
{
	CleanAll();

	QDomDocument ld;
	QFile file(FileName);


	if(file.open(QIODevice::ReadOnly))
	{
		QString Error;
		bool nsp=false;
		int errorLine;
		int errorColumn;
		if(ld.setContent(&file,nsp,&Error,&errorLine,&errorColumn))
		{
			QDomNodeList dnlb = ld.documentElement().elementsByTagName("box");
			qDebug()<<dnlb.size();

			//Создаем обьекты Box
			QHash <int , Box*> IdBoxHash;
			for(int i=0;i<dnlb.size();i++)
			{
				Box *b = AddBoxDE(dnlb.at(i).toElement());
				IdBoxHash.insert(b->GetIdBox(),b);
			}

			qDebug()<<IdBoxHash;
			qDebug()<<(void*)this;

			//Сылки Box обьектов эквиволентные файлу
			for(int i=0;i<dnlb.size();i++)
			{
				int Id = dnlb.at(i).toElement().attribute("id").toInt();
				qDebug()<<Id;
				QDomNodeList dnlbin = dnlb.at(i).toElement().elementsByTagName("inbox");
				Box *b = IdBoxHash.value(Id);
				for(int n = 0;n < dnlbin.size();n++)
				{
					int IdIn = dnlbin.at(n).toElement().attribute("id").toInt();
					qDebug()<<" "<<IdIn;
					Box *bin = IdBoxHash.value(IdIn);
					b->AddBox(bin);
				}

				QDomNodeList dnlnet = dnlb.at(i).toElement().elementsByTagName("net");
				qDebug()<<"Net Count"<<dnlnet.size();

				for(int n = 0; n < dnlnet.size() ; n++)
				{
					Net *net = new Net();
					QDomElement dein = dnlnet.at(n).toElement().elementsByTagName("in").at(0).toElement();
					qDebug()<<dein.attribute("box")<<dein.attribute("point");

					QString namepoint = dein.attribute("point");
					QString namebox = dein.attribute("box");

					if(b->GetName() == namebox)
						net->AddPointIn(b->GetPoint(namepoint),b);
					else
						net->AddPointIn(b->GetBox(namebox)->GetPoint(namepoint),b->GetBox(namebox));


					QDomNodeList dnlout = dnlnet.at(n).toElement().elementsByTagName("out");
					for(int no = 0; no < dnlout.size(); no++)
					{
						namepoint = dnlout.at(no).toElement().attribute("point");
						namebox = dnlout.at(no).toElement().attribute("box");
						qDebug()<<namebox<<namepoint;

						if(b->GetName() == namebox)
							net->AddPointOut(b->GetPoint(namepoint),b);
						else
							net->AddPointOut(b->GetBox(namebox)->GetPoint(namepoint),b->GetBox(namebox));
					}

					b->AddNet(net);


				}



			}


			/*QDomNodeList t1 = dnl.at(11).toElement().elementsByTagName("inbox");
			qDebug()<<t1.size();

			QStringList list;
			for(int i=0;i<t1.size();i++)
			{
				qDebug()<<t1.at(i).toElement().tagName();
				qDebug()<<t1.at(i).toElement().attribute("id").toInt();
				list.append(t1.at(i).toElement().attribute("id"));
			}

			qDebug()<<list;
			foreach (QString strid, list) {

				int id = strid.toInt();
				QDomElement e = dnl.at(id).toElement();
				Box *b;
				AddBoxDE(b,e);

			}*/


			/*foreach (QDomNode dn, dnl)
			{
				qDebug()<<dn.toElement().tagName();
			}*/


			//traverseNode(domElement);
		}
		else
		{
			qDebug()<<"!ld.setContent(&file)";
			//qDebug()<<file.readAll();
			qDebug()<<Error<<errorLine<<errorColumn;
		}
		file.close();
	}
	 else return false;

	 return true;
}

void Sheme::AllListBox(QList<Box *> &lb)
{
	lb.clear();
	QStack<Box*> stktree;
	stktree.push(this);
	bool loop = true;

	while(loop) {
		//qDebug()<<"-------->"<<"Step";
		//BoxInfo(stktree.top());

		if(stktree.top()->GetListBoxSize() == 0) {
			//qDebug()<<"stktree.top()->GetListBoxSize() == 0";
			stktree.top()->SetReadyTree(true);
			lb.append(stktree.top());
			if(stktree.top() != this) {
				stktree.pop();
				continue;
			}
			else
				loop = false;
		}

		//qDebug()<<"List";
		QList<Box*> stklb = stktree.top()->GetListBox();

		bool statpush = false;
		foreach (Box* b, stklb) {
			//BoxInfo(b);
			if(!b->GetReadyTree()) {
				//qDebug()<<"PUSH";
				stktree.push(b);
				statpush = true;
				break;
			}
		}

		if(statpush)
			continue;

		stktree.top()->SetReadyTree(true);
		lb.append(stktree.top());
		if(stktree.top() != this)
			stktree.pop();
		else
			loop = false;
	}

	foreach (Box* b, lb) {
		b->SetReadyTree(false);
	}
}

void Sheme::CleanAll()
{
	QList<Box*> lb;
	AllListBox(lb);
	foreach (Box* b, lb) {
		if(b != this)
		{
			delete b;
		}
		else
		{
			Clean();
		}
	}
}

bool Sheme::Step()
{
	qDebug()<<"Step";
	//PrintListBox(GetListBox(Box::BoxSource));
	//PrintListBox(GetListBox(Box::BoxDrain));

	QStack<Box*> stktree;
	stktree.push(this);

	for(int z=0;z<10;z++)
	{
		qDebug()<<"-----------";
		qDebug()<<z<<" Name BOX"<<stktree.top()->GetName()<<"Size"<<stktree.size();

		bool net=stktree.top()->StepNet();
		stktree.top()->StepBox(Box::BoxAll);

		if(net && stktree.top() == this)
		{
			break;
		}

		if(net && stktree.top() != this)
		{
			qDebug()<<"POP";
			stktree.top()->SetBoxTreeThis();
			if(!stktree.empty())
				qDebug()<<stktree.pop()->GetName();
			qDebug()<<"POP E"<<"size"<<stktree.size();
			qDebug()<<stktree.top()->GetName();
			continue;
		}

		if(stktree.top()->CurrentBoxTree() != stktree.top())
			stktree.push(stktree.top()->CurrentBoxTree());
	}

	PrintListBox(GetListBox(Box::BoxSource));
	PrintListBox(GetListBox(Box::BoxDrain));
	return false;
}
