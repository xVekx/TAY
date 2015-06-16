#include "mw.h"
#include <QApplication>
//---------------------------------------------------------------------------------------------------
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
void MessageOutput(QtMsgType type, const QMessageLogContext &, const QString & msg)
{
#else
void MessageOutput(QtMsgType type,const char *msg)
{
#endif
	QString Msg;

	QFile LogFile("log.txt");
	LogFile.open(QIODevice::WriteOnly | QIODevice::Append );
	QTextStream logfile(&LogFile);
	QTextStream console(stderr);

	switch (type)
	{
		case QtDebugMsg:
		{
			//Msg = QString("QDebug - %1").arg(msg);
			Msg = QString("%1").arg(msg);
			break;
		}
		case QtWarningMsg:
		{
			Msg = QString("Warning - %1").arg(msg);
			break;
		}
		case QtCriticalMsg:
		{
			Msg = QString("Critical - %1").arg(msg);
			break;
		}
		case QtFatalMsg:
		{
			Msg = QString("Fatal - %1").arg(msg);
			break;
		}
		default:{break;}
	}

	console<<Msg<<endl;
	logfile<<Msg<<endl;
	LogFile.close();
}
//---------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
	qInstallMessageHandler(MessageOutput);
#else
	qInstallMsgHandler(MessageOutput);
#endif
	MW w;
	w.show();
	return a.exec();
}
//---------------------------------------------------------------------------------------------------
