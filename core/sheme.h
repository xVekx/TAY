#ifndef SHEME_H
#define SHEME_H

#include "box.h"

#include <QStack>
#include <QtXml>

class Sheme : public Box
{
public:
	Sheme();

	bool Step();
	void TestSheme001();
	void TestSheme002();
	void TestSheme003();

	void SetAttrDomElement(QDomDocument& dd,QDomElement& de,QString attr,QString str);
	QString GetNameBox(Box *box, NetPointBox npb);
	QDomElement BoxDomElement(QDomDocument& domdoc,Box *box);
	void SetIdAllSheme();
	bool Save(QString FileName);
	bool Load(QString FileName);

	void AllListBox(QList<Box *> &lb);

	void CleanAll();
};

#endif // SHEME_H
