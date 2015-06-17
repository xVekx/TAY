#ifndef MW_H
#define MW_H

#include <QMainWindow>
#include "core/examples.h"
#include <QtXml>

namespace Ui {
class MW;
}

class MW : public QMainWindow
{
	Q_OBJECT

public:
	explicit MW(QWidget *parent = 0);
	~MW();
	Examples *scheme;

private slots:
	void on_TestSave_clicked();

private:
	Ui::MW *ui;
};

#endif // MW_H
