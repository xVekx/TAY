#include "mw.h"
#include "ui_mw.h"

MW::MW(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MW)
{
	ui->setupUi(this);


	/*Point p1(Point::PointOUT,"In1");
	p1.SetValue(100);
	qDebug()<<p1.PointInfo();
	Point p2;
	p2 = p1;
	qDebug()<<p2.PointInfo();*/

	s = new Sheme();
	s->SetTest001();
	s->Step();


}

MW::~MW()
{
	delete ui;
}
