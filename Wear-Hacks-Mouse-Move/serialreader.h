#ifndef SERIALREADER_H
#define SERIALREADER_H

#include <QObject>
#include <QtSerialPort/QSerialPort>

class SerialReader : public QObject
{
	Q_OBJECT
public:
	explicit SerialReader(QObject *parent = 0);
	~SerialReader();

signals:
	void dataReady(int data);

private slots:
	void readData();

private:
	QString portName;
	QSerialPort serial;
};

#endif // SERIALREADER_H
