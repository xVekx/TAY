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
		BoxSheme,
		BoxSource,		//Блок источника сигнала, имеет только выходы
		BoxDrain,		//Блок приёмника готового сигнала, толко входы
		BoxFUN,			//Блок Вычисления функции
		BoxSumm,		//Функция суммирования
		BoxTestFun		//Функция тестирования
	};

	Box(TypeEnum t = BoxNULL,QString nm = "NULL");

	void AddPoint(Point* addpoint);
	void AddBox(Box *addbox);
	void AddNet(Net *addnet);

	QString GetName() const;
	TypeEnum GetType() const;

	void SetReady(bool r = true);
	bool GetReady();

	bool GetReadyBoxListPoint(QList<Point*> lp);

	Box *GetBox(QString nb);
	Point *GetPoint(QString np);

	QList<Box*> GetListBox(TypeEnum t = BoxAll);

	QList<Point*> GetListPoint(Point::TypeEnum t = Point::PointAll);

	QList<Net*> GetListNet()
	{
		return net;
	}

	void PrintListPoint(const QList<Point*> lp);
	void PrintListBox(QList<Box*> lb);

	bool StepNet();

	bool ReadyBox(TypeEnum t)
	{
		QList<Box*> lb = GetListBox(t);
		foreach (Box* b, lb)
		{
			if(!b->GetReady())
				return false;
		}
		return true;
	}

	bool StepBox(TypeEnum t)
	{
		QList<Box*>	lb = GetListBox(t);
		foreach (Box *b, lb) {
			if(!b->GetReady())
			{
				qDebug()<<"Box"<<b->GetName();
				QList<Point*> lpin = b->GetListPoint(Point::PointIN);
				if(!GetReadyBoxListPoint(lpin))
				{
					qDebug()<<"continue";
					continue;
				}

				TypeEnum bt = b->GetType();

				switch (bt) {

					case BoxSumm: {
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

						b->SetReady();
						break;
					}

					case BoxTestFun: {

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

						b->SetReady();
						break;
					}

					case BoxDrain: {
						b->SetReady();
						break;
					}

					case BoxSheme:
					{
						boxtree = b;
						break;
					}

					default:
						break;
				}
			}
		}
		return true;
	}

	void SetBoxTreeThis()
	{
		boxtree = this;
	}

	Box* CurrentBoxTree()
	{
		return boxtree;
	}

	void SetIdBox(int id)
	{
		idbox = id;
	}

	int GetIdBox()
	{
		return idbox;
	}

	int GetListBoxSize()
	{
		return box.size();
	}

	bool StatusListBoxId()
	{
		foreach (Box *b, box)
		{
			if(b->GetIdBox() == -1)
				return false;
		}
		return true;
	}

	void SetReadyTree(bool r)
	{
		readytree = r;
	}

	bool GetReadyTree()
	{
		return readytree;
	}

private:

	QList<Point*>	point;
	QList<Box*>		box;
	QList<Net*>		net;
	TypeEnum		type;
	QString			namebox;
	bool			ready;
	Box*			boxtree;
	int				idbox;
	bool			readytree;

};

#endif // BOX_H
