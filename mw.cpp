#include "mw.h"
#include "ui_mw.h"

MW::MW(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MW)
{
	ui->setupUi(this);

	sheme = new Sheme();
	sheme->TestSheme002();
	sheme->Step();
}

MW::~MW()
{
	delete ui;
}
