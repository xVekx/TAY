#include "point.h"
//---------------------------------------------------------------------------------------------------
static QString pointtypename[] =
{
	"PointNULL",
	"PointIN",
	"PointOUT"
};
//---------------------------------------------------------------------------------------------------
Point::Point()
{
	ready = false,
			value = 0.0;
	type = PointNULL;
	name = "PointNULL";
}
//---------------------------------------------------------------------------------------------------
Point::Point(Point::TypeEnum t, QString n)
{
	ready = false,
			value = 0.0;
	type = t;
	name = n;
}
//---------------------------------------------------------------------------------------------------
QString Point::GetName()
{
	return name;
}
//---------------------------------------------------------------------------------------------------
void Point::SetName(QString n)
{
	name = n;
}
//---------------------------------------------------------------------------------------------------
void Point::SetType(Point::TypeEnum t)
{
	type = t;
}
//---------------------------------------------------------------------------------------------------
Point::TypeEnum Point::GetType()
{
	return type;
}
//---------------------------------------------------------------------------------------------------
void Point::SetValue(double v)
{
	ready = true;
	value = v;
}
//---------------------------------------------------------------------------------------------------
bool Point::GetReady()
{
	return ready;
}
//---------------------------------------------------------------------------------------------------
void Point::Clean()
{
	value = 0.0;
	ready = false;
}
//---------------------------------------------------------------------------------------------------
double Point::GetValue()
{
	return value;
}
//---------------------------------------------------------------------------------------------------
QString Point::PointInfo()
{
	QString str;
	str	=	"Point Name(" + name +
			"),Type(" + pointtypename[type] + ")";
	if(ready)
	{
		str += ",Ready(TRUE)";
	}
	else
	{
		str += ",Ready(FALSE)";
	}

	str += QString(",Value(%1)").arg(value);
	return str;
}
//---------------------------------------------------------------------------------------------------