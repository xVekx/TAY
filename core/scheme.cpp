#include "scheme.h"

Scheme::Scheme() : Box(BoxSheme)
{
	//type = BoxSheme;
}

void Scheme::SetAttrDomElement(QDomDocument &dd, QDomElement &de, QString attr, QString str)
{
	if(!str.isEmpty())
	{
		QDomAttr domAttr = dd.createAttribute(attr);
		domAttr.setValue(str);
		de.setAttributeNode(domAttr);
	}
}

QString Scheme::GetNameBox(Box *box, NetPointBox npb)
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

QDomElement Scheme::BoxDomElement(QDomDocument &domdoc, Box *box)
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

void Scheme::SetIdAllSheme()
{
	QList<Box*> lb;
	AllListBox(lb);
	int n = 0;
	foreach (Box* b, lb) {
		b->SetIdBox(n);
		n++;
	}
}

bool Scheme::Save(QString FileName)
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

Box* Scheme::AddBoxDE(QDomElement de) {
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

bool Scheme::Load(QString FileName)
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

void Scheme::AllListBox(QList<Box *> &lb)
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

void Scheme::CleanAll()
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

bool Scheme::Step()
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

