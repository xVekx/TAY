#include "mw.h"
#include "ui_mw.h"

MW::MW(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MW)
{
	ui->setupUi(this);

	sheme = new Sheme();
	sheme->TestSheme003();
	QList<Box*> listbox;
	sheme->AllListBox(listbox);
	sheme->SetIdAllSheme();
	//---------------------------
	/*qDebug()<<"---------";
	foreach (Box *b, listbox)
	{
		qDebug()<<b->GetName()<<b->GetIdBox();
		QString NameListBox ;
		foreach (Box *be, b->GetListBox()) {
			NameListBox += be->GetName()+ " ";
		}
		if(!NameListBox.isEmpty())
		qDebug()<<"Box add"<<NameListBox;
	}*/

	sheme->Save("../003/001.xml");


	//sheme->SetIdAllSheme();
	//sheme->Save("../003/001.xml");
	//sheme->Step();

	/*QDomDocument doc("addressbook");
	QDomElement  domElement = doc.createElement("adressbook");
	doc.appendChild(domElement);*/

	/*QDomElement contact1 =
		contact(doc, "Piggy", "+49 631322187", "piggy@mega.de");

	QDomElement contact2 =
		contact(doc, "Kermit", "+49 631322181", "kermit@mega.de");

	QDomElement contact3 =
		contact(doc, "Gonzo", "+49 631322186", "gonzo@mega.de");

	domElement.appendChild(contact1);
	domElement.appendChild(contact2);
	domElement.appendChild(contact3);*/

	/*QFile file("adressbook.xml");
	if(file.open(QIODevice::WriteOnly)) {
		QTextStream(&file) << doc.toString();
		file.close();
	}*/



}

MW::~MW()
{
	delete ui;
}
