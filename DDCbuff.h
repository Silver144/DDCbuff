#pragma once

#pragma execution_character_set("utf-8")


#include <QtWidgets/QMainWindow>
#include <QCheckBox>
#include <QTimer>
#include <QPushButton>
#include <Windows.h>
#include <psapi.h>
#include <tlhelp32.h>

class DDCbuff : public QMainWindow
{
	Q_OBJECT

public:
	DDCbuff(QWidget *parent = Q_NULLPTR);
	QTimer *delayBombTimer;
	
	
private:
	QCheckBox *inverseBox;


	bool isRunning();



public slots:
	void inverseBonus();
	void inverseBonusa();
	
	void setHook1();
	void setHook2();

	void punishBonus();
	void punishBonusa();

	void playerStand();
	void playerStanda();

	void delayBomb();
	void delayBomba();
};
