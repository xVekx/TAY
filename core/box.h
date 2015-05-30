#ifndef BOX_H
#define BOX_H

#include "net.h"

class Box
{
public:

	enum TypeEnum
	{
		BoxNULL = 0,	//Блок не определён
		BoxAll,			//Все блоки
		BoxSource,		//Блок источника сигнала, имеет только выходы
		BoxDrain,		//Блок приёмника готового сигнала, толко входы
		BoxFUN,			//Блок Вычисления
		BoxSumm,		//Функция суммирования
		BoxTestFun		//Функция тестирования
	};

	Box(TypeEnum t = BoxNULL,QString nm = "NULL");

	void AddPoint(Point* addpoint);

	void AddBox(Box *addbox);

	void AddNet(Net *addnet);

	QString GetName() const;

	TypeEnum GetType() const;

	bool GetReady() const;

	bool GetReadyBoxListPoint(QList<Point*> lp);

	Box *GetBox(QString nb);

	Point *GetPoint(QString np);

	QList<Box*> GetListBox(TypeEnum t);

	QList<Point*> GetListPoint(Point::TypeEnum t);

	void PrintListPoint(const QList<Point*> lp);

	void PrintListBox(QList<Box*> lb)
	{
		foreach (Box *b, lb) {
			qDebug()<<b->GetName();
			QList<Point*> lp = b->GetListPoint(Point::PointAll);
			PrintListPoint(b->GetListPoint(Point::PointAll));
		}
	}



	bool StepNet()
	{
		foreach (Net* n, net) {
			qDebug()<<n->Step();
		}
		return false;
	}

	bool StepBox(TypeEnum t)
	{
		QList<Box*>	lb = GetListBox(t);
		foreach (Box *b, lb) {
			if(!b->GetReady())
			{
				switch (t) {
					case BoxSumm: {
						qDebug()<<"BoxSumm"<<b->GetName();
						QList<Point*> lpin = b->GetListPoint(Point::PointIN);
						if(!GetReadyBoxListPoint(lpin))
							continue;
						QList<Point*> lpout = b->GetListPoint(Point::PointOUT);

						double summ = 0;
						foreach (Point* pin, lpin) {
							summ += pin->GetValue();
						}

						foreach (Point* pout, lpout) {
							pout->SetValue(summ);
						}

						PrintListPoint(lpin);
						PrintListPoint(lpout);

						break;
					}
					case BoxTestFun: {
						qDebug()<<"BoxTestFun"<<b->GetName();
						QList<Point*> lpin = b->GetListPoint(Point::PointIN);
						if(!GetReadyBoxListPoint(lpin))
							continue;
						QList<Point*> lpout = b->GetListPoint(Point::PointOUT);

						double summ = 0;
						foreach (Point* pin, lpin) {
							summ += pin->GetValue();
						}

						double z = 1.0f;
						foreach (Point* pout, lpout) {
							pout->SetValue(summ*z);
							z = z + 1.0f;
						}

						PrintListPoint(lpin);
						PrintListPoint(lpout);

						break;
					}
					default:
						break;
				}
			}

		}
		return false;
	}

private:

	QList<Point*>	point;
	QList<Box*>		box;
	QList<Net*>		net;
	TypeEnum		type;
	QString			namebox;
	bool			ready;

};

#endif // BOX_H
