#include "DDCbuff.h"

HANDLE hSnapshot;

PROCESSENTRY32 pe;

int cntHook1 = 1, cntHook2 = 1, cntHook3;

int procStand, procBonus;

int bombCounter, bombFlag;

HHOOK KeyHook1, KeyHook2, KeyHook3;

DDCbuff *hzc;

DDCbuff::DDCbuff(QWidget *parent)
	: QMainWindow(parent)
{
	hzc = this;

	procStand = 0;
	procBonus = 0;

	inverseBox = new QCheckBox("½±Àø»¥»»", this);
	lrBox = new QCheckBox("×óÓÒ·âÓ¡", this);
	udBox = new QCheckBox("ÉÏÏÂ·âÓ¡", this);
	delayBox = new QCheckBox("ËÄ³ßÕ¨µ¯", this);
	standBox = new QCheckBox("ÌæÉíµØ²Ø", this);
	punishBox = new QCheckBox("Ãâ·ÑÎç²Í", this);

	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(checkProg()));
	timer->start(100);

	delayBombTimer = new QTimer(this);
	connect(delayBombTimer, SIGNAL(timeout()), this, SLOT(bombCount()));

	UIsetup();
}

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
	}
	else
		this->setWindowTitle("No Game");
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
	unsigned char code[] = { 0xE9, 0xC6, 0x16, 0x06, 0x00, 0x90, 0x90, 0x90, 0x90, 0x90 };
	unsigned char code2[] = {	
								0x83, 0x3D, 0x70, 0x58, 0x4F, 0x00, 0x00, 0x7F, 0x19, 0xC7, 0x87, 0x84,
								0x06, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0xC7, 0x05, 0x70, 0x58, 0x4F,
								0x00, 0x03, 0x00, 0x00, 0x00, 0xE9, 0x1D, 0xE9, 0xF9, 0xFF, 0xFF, 0x0D,
								0x70, 0x58, 0x4F, 0x00, 0xC7, 0x87, 0x84, 0x06, 0x00, 0x00, 0x02, 0x00,
								0x00, 0x00, 0x83, 0x05, 0x58, 0x58, 0x4F, 0x00, 0x32, 0xE9, 0x01, 0xE9,
								0xF9, 0xFF
							};
	unsigned char code3[] = { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };
	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	WriteProcessMemory(hSnapshot, LPVOID(0x0044F871), code, sizeof(code), NULL);
	WriteProcessMemory(hSnapshot, LPVOID(0x004B0F3C), code2, sizeof(code2), NULL);
	WriteProcessMemory(hSnapshot, LPVOID(0x0044DF45), code3, sizeof(code3), NULL);
	procStand = 1;
}

void DDCbuff::playerStandA()
{
	if (procStand)
	{
		unsigned char code[] = { 0xC7, 0x87, 0x84, 0x06, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00 };
		unsigned char code2[62];
		unsigned char code3[] = { 0xC7, 0x05, 0x70, 0x58, 0x4F, 0x00, 0x03, 0x00, 0x00, 0x00 };

		memset(code2, 0, sizeof(code2));

		hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
		WriteProcessMemory(hSnapshot, LPVOID(0x0044F871), code, sizeof(code), NULL);
		WriteProcessMemory(hSnapshot, LPVOID(0x004B0F3C), code2, sizeof(code2), NULL);
		WriteProcessMemory(hSnapshot, LPVOID(0x0044DF45), code3, sizeof(code3), NULL);

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
	unsigned char code[] = { 0x7F };
	unsigned char code2[] = { 0x3C, 0x90, 0x90 };

	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS , false, (DWORD)pe.th32ProcessID);
	WriteProcessMemory(hSnapshot, LPVOID(0x00438E01), code, sizeof(code), NULL);
	WriteProcessMemory(hSnapshot, LPVOID(0x00438E31), code2, sizeof(code2), NULL);

}

void DDCbuff::inverseBonusA()
{
	unsigned char code[] = { 0x7C };
	unsigned char code2[] = { 0x32, 0x7C, 0x50 };

	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	WriteProcessMemory(hSnapshot, LPVOID(0x00438E01), code, sizeof(code), NULL);
	WriteProcessMemory(hSnapshot, LPVOID(0x00438E31), code2, sizeof(code2), NULL);

}
