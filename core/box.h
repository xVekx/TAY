#ifndef BOX_H
#define BOX_H
//---------------------------------------------------------------------------------------------------
#include "net.h"
//---------------------------------------------------------------------------------------------------
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
		BoxTestFun,		//Функция тестирования
		BoxInverted,
		BoxFun1,
		BoxFun2
	};

	Box(TypeEnum t = BoxNULL,QString nm = "NULL",int id = -1);
	~Box();
	void Init(Box::TypeEnum t = BoxNULL, QString nm = "NULL", int id = -1);

	void Clean();

	void AddPoint(Point* addpoint);
	void AddBox(Box *addbox);
	void AddNet(Net *addnet);

	QString GetName();
	TypeEnum GetType();

	void SetReady(bool r = true);
	bool GetReady();

	bool GetReadyBoxListPoint(QList<Point*> lp);

	Box *GetBox(QString nb);
	Point *GetPoint(QString np);

	QList<Box*> GetListBox(TypeEnum t = BoxAll);
	QList<Point*> GetListPoint(Point::TypeEnum t = Point::PointAll);
	QList<Net*> GetListNet();

	void PrintListPoint(const QList<Point*> lp);
	void PrintListBox(QList<Box*> lb);

	bool StepNet();

	bool ReadyBox(TypeEnum t);

	bool StepBox(TypeEnum t);

	void SetBoxTreeThis();

	Box* CurrentBoxTree();

	void SetIdBox(int id);

	int GetIdBox();

	int GetListBoxSize();

	bool StatusListBoxId();

	void SetReadyTree(bool r);

	bool GetReadyTree();

	double MatOCK2(double k,double k1)
	{
		return -(k1/k-1)/k1;
	}

	double MatOCK(double k1,double k2)
	{
		return (k1)/(1-k1*k2);
	}


	void BoxFunStep(TypeEnum bt, QList<Point *> lpin, QList<Point *> lpout);
	void BoxFunStep(Box *b, TypeEnum bt, QList<Point *> lpin, QList<Point *> lpout);
	bool StepBox2();
	void StepNet2();
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
//---------------------------------------------------------------------------------------------------
#endif // BOX_H
