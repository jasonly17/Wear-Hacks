#include "serialreader.h"
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

SerialReader::SerialReader(QObject *parent) : QObject(parent)
{
	// select the correct port
	QString portName = QSerialPortInfo::availablePorts().at(0).portName();
	serial.setPortName(portName);
	serial.setBaudRate(QSerialPort::Baud9600);

	if (!serial.open(QIODevice::ReadOnly)) {
		qDebug() << QString("Can't open %1, error code %2")
					.arg(portName).arg(serial.error());
	} else {
		connect(&serial, SIGNAL(readyRead()),
				this, SLOT(readData()));
	}
}

SerialReader::~SerialReader()
{
}

void SerialReader::readData()
{
	char data;
	qint64 bytesRead = serial.read(&data, 1); // read one byte at a time
	if (bytesRead == 1) {
		qDebug() << data;
		emit dataReady(data);
	}
	emit dataReady(0);
}
