#ifndef MOUSEMOVE_H
#define MOUSEMOVE_H

#include <QObject>

class MouseMove : public QObject
{
	Q_OBJECT
public:
	explicit MouseMove(QObject *parent = 0);
	~MouseMove();
	void moveMouse(int x, int y);

public slots:
	void processData(int dir);

private:
	int currX, currY;
	int hvSpeed, diagSpeed;
};

#endif // MOUSEMOVE_H
