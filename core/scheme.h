#ifndef SCHEME_H
#define SCHEME_H
//---------------------------------------------------------------------------------------------------
#include "box.h"

#include <QStack>
#include <QtXml>
//---------------------------------------------------------------------------------------------------
class Scheme : public Box
{
public:
	Scheme();

	bool Step();

	void SetAttrDomElement(QDomDocument& dd,QDomElement& de,QString attr,QString str);
	QString GetNameBox(Box *box, NetPointBox npb);
	QDomElement BoxDomElement(QDomDocument& domdoc,Box *box);
	void SetIdAllSheme();
	bool Save(QString FileName);
	bool Load(QString FileName);

	void AllListBox(QList<Box *> &lb);

	void CleanAll();
	Box *AddBoxDE(QDomElement de);
	void TestSheme004(Box *b);
	void Step2();
};
//---------------------------------------------------------------------------------------------------
#endif // SHEME_H
