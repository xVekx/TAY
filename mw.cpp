#include "mw.h"
#include "ui_mw.h"

MW::MW(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MW)
{
	ui->setupUi(this);

	scheme = new Examples();


	/*scheme->TestSheme003(scheme);

	QList<Box*> listbox;

	scheme->AllListBox(listbox);

	scheme->SetIdAllSheme();

	//---------------------------
	qDebug()<<"---------";
	foreach (Box *b, listbox)
	{
		qDebug()<<b->GetName()<<b->GetIdBox();
		QString NameListBox ;
		foreach (Box *be, b->GetListBox()) {
			NameListBox += be->GetName()+ " ";
		}
		if(!NameListBox.isEmpty())
		qDebug()<<"Box add"<<NameListBox;
	}

	scheme->Save("../TAY/examples/001.xml");

	scheme->CleanAll();

	qDebug()<<scheme->Load("../TAY/examples/001.xml");

	scheme->Step();*/

	/*qDebug()<<"---------";
	sheme->AllListBox(listbox);
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

	scheme->TestSheme004(scheme);

	//for(int i=0;i<2;i++)
	scheme->Step();
	//scheme->Save("../TAY/examples/001.xml");

}

MW::~MW()
{
	delete ui;
}

void MW::on_TestSave_clicked()
{
	scheme->CleanAll();
	scheme->TestSheme003(scheme);
	QList<Box*> listbox;
	scheme->AllListBox(listbox);
	scheme->SetIdAllSheme();
}
