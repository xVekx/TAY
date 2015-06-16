#include "mw.h"
#include "ui_mw.h"

MW::MW(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MW)
{
	ui->setupUi(this);

	sheme = new Sheme();

	for(int i=0;i<1;i++)
	{

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
	}


	sheme->Save("../003/001.xml");*/

	sheme->CleanAll();
	}
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
