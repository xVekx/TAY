#ifndef POINT_H
#define POINT_H
//---------------------------------------------------------------------------------------------------
#include <QString>
#include <QDebug>
//---------------------------------------------------------------------------------------------------
class Point
{
public:
//--------------------------------------------------------------------------------------------------
	enum TypeEnum	//Тип точки
	{
		PointNULL	= 0,	//Неопределенно
		PointIN,	//Точка является входом
		PointOUT	//Точка является выходом
	};

	Point();
	Point(TypeEnum t, QString n);
	QString GetName();
	void SetName(QString n);
	void SetType(TypeEnum t);
	TypeEnum GetType();
	void SetValue(double v);
	bool GetReady();
	void Clean();
	double GetValue();
	QString PointInfo();

	Point &operator = (const Point &s)
	{
		SetValue(s.value);
		return *this;
	}

private:
	double value;					//Результат
	bool ready;						//Статус при пересчёте
	QString name;					//Имя точки
	TypeEnum type;					//Тип точки
};
//---------------------------------------------------------------------------------------------------
#endif // POINT_H
