#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include "serialreader.h"
#include "mousemove.h"
#include "Windows.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

	foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
		qDebug() << info.portName();
	}

	SerialReader reader;
	MouseMove move;
	QObject::connect(&reader, SIGNAL(dataReady(int)), &move, SLOT(processData(int)));

	// demo
//	for (int x = 0; x < 9; x++) {
//		for (int i = 0; i < 50; i++) {
//			move.processData(x);
//			Sleep(40);
//		}
//	}

    return app.exec();
}
