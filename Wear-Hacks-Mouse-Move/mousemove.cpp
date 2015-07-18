#include <Windows.h>
#include "mousemove.h"
#include <QDebug>

MouseMove::MouseMove(QObject *parent) : QObject(parent)
{
	POINT pt;
	GetCursorPos(&pt);
	currX = pt.x;
	currY = pt.y;
	hvSpeed = 8;
	diagSpeed = 3;
	qDebug() << currX << currY;
}

MouseMove::~MouseMove()
{
}

void MouseMove::moveMouse(int x, int y)
{
	currX += x;
	currY += y;
	SetCursorPos(currX, currY);

}

void MouseMove::processData(int dir)
{
	qDebug() << dir;
	switch (dir) {
	case 1:
		moveMouse(0, -hvSpeed);
		break;
	case 2:
		moveMouse(0, hvSpeed);
		break;
	case 3:
		moveMouse(-hvSpeed, 0);
		break;
	case 4:
		moveMouse(hvSpeed, 0);
		break;
	case 5:
		moveMouse(-diagSpeed, -diagSpeed);
		break;
	case 6:
		moveMouse(diagSpeed, -diagSpeed);
		break;
	case 7:
		moveMouse(-diagSpeed, diagSpeed);
		break;
	case 8:
		moveMouse(diagSpeed, diagSpeed);
		break;
	default:
		break;
	}
}
