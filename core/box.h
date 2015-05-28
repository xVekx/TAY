#ifndef BOX_H
#define BOX_H

#include "point.h"

class Box
{
public:

	enum TypeEnum
	{
		BoxBegin,
		BoxBody,
		BoxEnd
	};

	Box(TypeEnum t = BoxBody)
	{
		type = t;
	}

	void AddPoint(Point* addpoint)
	{
		point.append(addpoint);
	}

	TypeEnum GetType()
	{
		return type;
	}

private:

	QList<Point*> point;
	TypeEnum type;

};

#endif // BOX_H
