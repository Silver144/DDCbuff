#pragma once

#pragma execution_character_set("utf-8")


#include <QtWidgets/QMainWindow>
#include <QCheckBox>
#include <Windows.h>
#include <psapi.h>
#include <tlhelp32.h>

class DDCbuff : public QMainWindow
{
	Q_OBJECT

public:
	DDCbuff(QWidget *parent = Q_NULLPTR);
	
	
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
};
