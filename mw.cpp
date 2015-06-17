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

	sheme->Save("../TAY/examples/001.xml");

	sheme->CleanAll();

	qDebug()<<sheme->Load("../TAY/examples/001.xml");

	sheme->Step();

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

}

MW::~MW()
{
	delete ui;
}

void MW::on_TestSave_clicked()
{
	sheme->CleanAll();
	sheme->TestSheme003();
	QList<Box*> listbox;
	sheme->AllListBox(listbox);
	sheme->SetIdAllSheme();
}
