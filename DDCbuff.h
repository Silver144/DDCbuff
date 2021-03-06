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
	QTimer *timer;
	
private:
	QCheckBox *inverseBox;
	QCheckBox *lrBox;
	QCheckBox *udBox;
	QCheckBox *delayBox;
	QCheckBox *standBox;
	QCheckBox *punishBox;
	QCheckBox *lrBoxA;
	QCheckBox *udBoxA;
	QCheckBox *halfBox;
	QCheckBox *brBox;
	QCheckBox *curtainBox;
	QCheckBox *drumBox;
	QCheckBox *bigBox;


	bool isRunning();
	void UIsetup();

	void setHook3();
	void unHook3();

	void setHook4();
	void unHook4();



public slots:
	void checkProg();

	void inverseBonus();
	void inverseBonusA();
	
	void setHook1();
	void setHook2();

	void unHook1();
	void unHook2();

	void punishBonus();
	void punishBonusA();

	void playerStand();
	void playerStandA();

	void delayBomb();
	void delayBombA();
	void bombCount();

	void curtain();
	void curtainA();

	void ud();
	void udA();

	void lr();
	void lrA();

	void half();
	void halfA();

	void br();
	void brA();

	void drum();
	void drumA();

	void big();
	void bigA();
};
