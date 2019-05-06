#include "DDCbuff.h"

HANDLE hSnapshot;

PROCESSENTRY32 pe;

int cntHook1 = 1, cntHook2 = 1, cntHook3, cntHook4 = 1;

bool flag[7];

int procStand, procBonus;

int bombCounter, bombFlag;

HHOOK KeyHook1, KeyHook2, KeyHook3, KeyHook4, KeyHook5;

DDCbuff *hzc;

void DDCbuff::checkProg()
{
	if (isRunning())
	{
		this->setWindowTitle("Running");
		if (inverseBox->isChecked())
			inverseBonus();
		else
			inverseBonusA();
		if (lrBox->isChecked())
			setHook2();
		else
			unHook2();
		if (udBox->isChecked())
			setHook1();
		else
			unHook1();
		if (delayBox->isChecked())
			delayBomb();
		else
			delayBombA();
		if (punishBox->isChecked())
			punishBonus();
		else
			punishBonusA();
		if (standBox->isChecked())
			playerStand();
		else
			playerStandA();
		if (lrBoxA->isChecked())
			lr();
		else
			lrA();
		if (udBoxA->isChecked())
			ud();
		else
			udA();
		if (curtainBox->isChecked())
			curtain();
		else
			curtainA();
		if (halfBox->isChecked())
			half();
		else
			halfA();
		if (brBox->isChecked())
			br();
		else
			brA();
		if (drumBox->isChecked())
			drum();
		else
			drumA();
		if (bigBox->isChecked())
			big();
		else
			bigA();
	}
	else
		this->setWindowTitle("No Game");
}

void DDCbuff::curtain()
{
	if (flag[0])
		return;
	flag[0] = true;
	rename("data", "data_b");
	rename("datatiemu", "data");
}

void DDCbuff::curtainA()
{
	if (!flag[0])
		return;
	flag[0] = false;
	rename("data", "datatiemu");
	rename("data_b", "data");
}

void DDCbuff::ud()
{
	if (flag[1])
		return;
	flag[1] = true;
	rename("data", "data_b");
	rename("dataflipud", "data");
}

void DDCbuff::udA()
{
	if (!flag[1])
		return;
	flag[1] = false;
	rename("data", "dataflipud");
	rename("data_b", "data");
}

void DDCbuff::lr()
{
	if (flag[2])
		return;
	flag[2] = true;
	rename("data", "data_b");
	rename("datafliplr", "data");
}

void DDCbuff::lrA()
{
	if (!flag[2])
		return;
	flag[2] = false;
	rename("data", "datafliplr");
	rename("data_b", "data");
}

void DDCbuff::half()
{
	if (flag[3])
		return;
	flag[3] = true;
	rename("data", "data_b");
	rename("datahalf", "data");
}

void DDCbuff::halfA()
{
	if (!flag[3])
		return;
	flag[3] = false;
	rename("data", "datahalf");
	rename("data_b", "data");
}

void DDCbuff::br()
{
	if (flag[4])
		return;
	flag[4] = true;
	rename("data", "data_b");
	rename("databr", "data");
}

void DDCbuff::brA()
{
	if (!flag[4])
		return;
	flag[4] = false;
	rename("data", "databr");
	rename("data_b", "data");
}

void DDCbuff::drum()
{
	if (flag[5])
		return;
	flag[5] = true;
	rename("data", "data_b");
	rename("datadrum", "data");
}

void DDCbuff::drumA()
{
	if (!flag[5])
		return;
	flag[5] = false;
	rename("data", "datadrum");
	rename("data_b", "data");
}

void DDCbuff::big()
{
	if (flag[6])
		return;
	flag[6] = true;
	rename("data", "data_b");
	rename("databig", "data");
}

void DDCbuff::bigA()
{
	if (!flag[6])
		return;
	flag[6] = false;
	rename("data", "databig");
	rename("data_b", "data");
}

void DDCbuff::UIsetup()
{
	setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);
	int width = GetSystemMetrics(SM_CXFULLSCREEN);
	int height = GetSystemMetrics(SM_CYFULLSCREEN);
	this->setWindowTitle("No Game");
	this->setWindowFlags(Qt::WindowCloseButtonHint);
	this->setFixedSize(286, 367);
	this->move((width - 286) / 2, (height - 367) / 2);

	inverseBox->setGeometry(20, 20, 111, 31);
	lrBox->setGeometry(150, 20, 111, 31);
	udBox->setGeometry(20, 70, 111, 31);
	delayBox->setGeometry(150, 70, 111, 31);
	standBox->setGeometry(20, 120, 111, 31);
	punishBox->setGeometry(150, 120, 111, 31);
	lrBoxA->setGeometry(20, 170, 111, 31);
	udBoxA->setGeometry(150, 170, 111, 31);
	halfBox->setGeometry(20, 220, 111, 31);
	curtainBox->setGeometry(150, 220, 111, 31);
	brBox->setGeometry(20, 270, 111, 31);
	drumBox->setGeometry(150, 270, 111, 31);
	bigBox->setGeometry(20, 320, 111, 31);

}

LRESULT CALLBACK KeyProc1(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode != HC_ACTION)
		return CallNextHookEx(KeyHook1, nCode, wParam, lParam);
	PKBDLLHOOKSTRUCT LowKey = NULL;
	LowKey = (PKBDLLHOOKSTRUCT)lParam;
	if (LowKey->vkCode == VK_UP)
		return 1;
	if (LowKey->vkCode == VK_DOWN)
		return 1;
	return CallNextHookEx(KeyHook1, nCode, wParam, lParam);
}

LRESULT CALLBACK KeyProc2(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode != HC_ACTION)
		return CallNextHookEx(KeyHook2, nCode, wParam, lParam);
	PKBDLLHOOKSTRUCT LowKey = NULL;
	LowKey = (PKBDLLHOOKSTRUCT)lParam;
	if (LowKey->vkCode == VK_LEFT)
		return 1;
	if (LowKey->vkCode == VK_RIGHT)
		return 1;
	return CallNextHookEx(KeyHook2, nCode, wParam, lParam);
}

LRESULT CALLBACK KeyProc3(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode != HC_ACTION)
		return CallNextHookEx(KeyHook3, nCode, wParam, lParam);
	PKBDLLHOOKSTRUCT LowKey = NULL;
	LowKey = (PKBDLLHOOKSTRUCT)lParam;
	if (LowKey->vkCode == 'X')
	{
		if (bombFlag)
			return 1;
		else
		{
			if (bombCounter == 1)
				return CallNextHookEx(KeyHook3, nCode, wParam, lParam);
			else
			{
				bombFlag = 1;
				hzc->delayBombTimer->start(1500);
				return 1;
			}
		}
	}
	return CallNextHookEx(KeyHook3, nCode, wParam, lParam);
}

LRESULT CALLBACK KeyProc4(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode != HC_ACTION)
		return CallNextHookEx(KeyHook4, nCode, wParam, lParam);
	PKBDLLHOOKSTRUCT LowKey = NULL;
	LowKey = (PKBDLLHOOKSTRUCT)lParam;
	if (LowKey->vkCode == 'X')
		return 1;
	return CallNextHookEx(KeyHook4, nCode, wParam, lParam);
}

LRESULT CALLBACK KeyProc5(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode != HC_ACTION)
		return CallNextHookEx(KeyHook5, nCode, wParam, lParam);
	PKBDLLHOOKSTRUCT LowKey = NULL;
	LowKey = (PKBDLLHOOKSTRUCT)lParam;
	if (LowKey->vkCode == VK_CONTROL)
		return 1;
	return CallNextHookEx(KeyHook5, nCode, wParam, lParam);
}

void DDCbuff::setHook1()
{
	if (!cntHook1)
		return;
	cntHook1 = 0;
	KeyHook1 = SetWindowsHookEx(WH_KEYBOARD_LL, KeyProc1, GetModuleHandle(NULL), 0);
}

void DDCbuff::setHook2()
{
	if (!cntHook2)
		return;
	cntHook2 = 0;
	KeyHook2 = SetWindowsHookEx(WH_KEYBOARD_LL, KeyProc2, GetModuleHandle(NULL), 0);
}

void DDCbuff::setHook3()
{
	if (!cntHook3)
		return;
	cntHook3 = 0;
	KeyHook3 = SetWindowsHookEx(WH_KEYBOARD_LL, KeyProc3, GetModuleHandle(NULL), 0);
}

void DDCbuff::setHook4()
{
	if (!cntHook4)
		return;
	cntHook4 = 0;
	KeyHook4 = SetWindowsHookEx(WH_KEYBOARD_LL, KeyProc4, GetModuleHandle(NULL), 0);
}

void DDCbuff::unHook1()
{
	if (cntHook1)
		return;
	cntHook1 = 1;
	UnhookWindowsHookEx(KeyHook1);
}

void DDCbuff::unHook2()
{
	if (cntHook2)
		return;
	cntHook2 = 1;
	UnhookWindowsHookEx(KeyHook2);
}

void DDCbuff::unHook3()
{
	if (cntHook3)
		return;
	cntHook3 = 1;
	UnhookWindowsHookEx(KeyHook3);
}

void DDCbuff::unHook4()
{
	if (cntHook4)
		return;
	cntHook4 = 1;
	UnhookWindowsHookEx(KeyHook4);
}

bool DDCbuff::isRunning()
{
	LPCTSTR name = L"“Œ•û‹Pjé@` Double Dealing Character. ver 1.00b";
	PROCESSENTRY32 tmppe;
	DWORD id = 0, TID1, PID1 = -1;
	HANDLE tmphSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	HWND hCurrentWindow1 = FindWindow(NULL, name);
	TID1 = GetWindowThreadProcessId(hCurrentWindow1, &PID1);
	tmppe.dwSize = sizeof(PROCESSENTRY32);
	if (!Process32First(tmphSnapshot, &tmppe)) return false;
	do
	{
		tmppe.dwSize = sizeof(PROCESSENTRY32);
		if (Process32Next(tmphSnapshot, &tmppe) == FALSE) return false;
		if (tmppe.th32ProcessID == PID1)
		{
			pe = tmppe;
			hSnapshot = tmphSnapshot;
			return true;
		}
	} while (1);
}

void DDCbuff::bombCount()
{
	if (bombCounter == 1)
	{
		bombFlag = 0;
		INPUT input;
		ZeroMemory(&input, sizeof(input));
		input.type = INPUT_KEYBOARD;
		input.ki.wVk = 'X';
		input.ki.wScan = MapVirtualKey(input.ki.wVk, MAPVK_VK_TO_VSC);
		SendInput(1, &input, sizeof(INPUT));
		Sleep(100);
		input.ki.dwFlags = KEYEVENTF_KEYUP;
		SendInput(1, &input, sizeof(INPUT)); 
		
		delayBombTimer->stop();
		bombCounter = 0;
	}
	else
		bombCounter++;
}

void DDCbuff::delayBomb()
{
	bombFlag = 0;
	setHook3();
}

void DDCbuff::delayBombA()
{
	delayBombTimer->stop();
	unHook3();
}

void DDCbuff::playerStand()
{
	unsigned char code[] = { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };

	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	WriteProcessMemory(hSnapshot, LPVOID(0x0044DECB), code, sizeof(code), NULL);

	setHook4();

	procStand = 1;
}

void DDCbuff::playerStandA()
{
	if (procStand)
	{
		unsigned char code[] = { 0x0F, 0x84, 0x00, 0x01, 0x00, 0x00 };

		hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
		WriteProcessMemory(hSnapshot, LPVOID(0x0044DECB), code, sizeof(code), NULL);

		unHook4();

		procStand = 0;
	}
}

void DDCbuff::punishBonus()
{
	unsigned char code[] = { 0xE9, 0xE4, 0x7E, 0x07, 0x00 };
	unsigned char code2[] = { 
								0x68, 0xA0, 0xA0, 0xA0, 0x80, 0x6A, 0xFF, 0X8D, 0X44, 0X24, 0X30, 0X50,
								0x0F, 0x28, 0xDC, 0xE8, 0xB0, 0x70, 0xFA, 0xFF, 0x81, 0x3D, 0x58, 0x58,
								0x4F, 0x00, 0xC8, 0x00, 0x00, 0x00, 0x7C, 0x0C, 0x83, 0x2D, 0x58, 0x58,
								0x4F, 0x00, 0x64, 0xE9, 0xFF, 0x80, 0xF8, 0xFF, 0xC7, 0x05, 0x58, 0x58,
								0x4F, 0x00, 0x64, 0x00, 0x00, 0x00, 0xE9, 0xF0, 0x80, 0xF8, 0xFF
							};

	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	WriteProcessMemory(hSnapshot, LPVOID(0x00439053), code, sizeof(code), NULL);
	WriteProcessMemory(hSnapshot, LPVOID(0x004B0F3C), code2, sizeof(code2), NULL);

	procBonus = 1;
}

void DDCbuff::punishBonusA()
{
	if (procBonus)
	{
		unsigned char code[] = { 0x68, 0xA0, 0xA0, 0xA0, 0x80 };
		unsigned char code2[] = {
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0X00, 0X00, 0X00, 0X00, 0X00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
		};

		hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
		WriteProcessMemory(hSnapshot, LPVOID(0x00439053), code, sizeof(code), NULL);
		WriteProcessMemory(hSnapshot, LPVOID(0x004B0F3C), code2, sizeof(code2), NULL);

		procBonus = 0;
	}
	
}

void DDCbuff::inverseBonus()
{
	unsigned char code[] = { 0xE9, 0x39, 0x81, 0x07, 0x00 };
	unsigned char code2[] = {
		0x83, 0xF8, 0x14, 0x0F, 0x8C, 0xE3, 0x7F, 0xF8, 0xFF, 0x83, 0xF8, 0x3C,
		0x0F, 0x8F, 0xE6, 0x7E, 0xF8, 0xFF, 0xE9, 0xB0, 0x7E, 0xF8, 0xFF			  
	};

	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS , false, (DWORD)pe.th32ProcessID);
	WriteProcessMemory(hSnapshot, LPVOID(0x00438DFE), code, sizeof(code), NULL);
	WriteProcessMemory(hSnapshot, LPVOID(0x004B0F3C), code2, sizeof(code2), NULL);

}

void DDCbuff::inverseBonusA()
{
	unsigned char code[] = { 0x83, 0xF8, 0x3C, 0x7C, 0x2C };
	unsigned char code2[] = {
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	};

	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	WriteProcessMemory(hSnapshot, LPVOID(0x00438DFE), code, sizeof(code), NULL);
	WriteProcessMemory(hSnapshot, LPVOID(0x004B0F3C), code2, sizeof(code2), NULL);

}

DDCbuff::DDCbuff(QWidget *parent)
	: QMainWindow(parent)
{
	hzc = this;

	procStand = 0;
	procBonus = 0;

	memset(flag, false, sizeof(flag));

	inverseBox = new QCheckBox("½±Àø»¥»»", this);
	lrBox = new QCheckBox("×óÓÒ·âÓ¡", this);
	udBox = new QCheckBox("ÉÏÏÂ·âÓ¡", this);
	delayBox = new QCheckBox("ËÄ³ßÕ¨µ¯", this);
	standBox = new QCheckBox("ÌæÉíµØ²Ø", this);
	punishBox = new QCheckBox("Ãâ·ÑÎç²Í", this);
	lrBoxA = new QCheckBox("×óÓÒ·­×ª", this);
	udBoxA = new QCheckBox("ÉÏÏÂ·­×ª", this);
	halfBox = new QCheckBox("¹¥»÷¼Ó±¶", this);
	brBox = new QCheckBox("br", this);
	curtainBox = new QCheckBox("ÌúÄ»", this);
	drumBox = new QCheckBox("drum", this);
	bigBox = new QCheckBox("±ä´ó", this);

	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(checkProg()));
	timer->start(100);

	KeyHook5 = SetWindowsHookEx(WH_KEYBOARD_LL, KeyProc5, GetModuleHandle(NULL), 0);

	delayBombTimer = new QTimer(this);
	connect(delayBombTimer, SIGNAL(timeout()), this, SLOT(bombCount()));

	UIsetup();
}
