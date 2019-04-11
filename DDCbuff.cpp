#include "DDCbuff.h"

HANDLE hSnapshot;

PROCESSENTRY32 pe;

int cntHook1 = 1, cntHook2 = 1;
HHOOK KeyHook1, KeyHook2;

DDCbuff::DDCbuff(QWidget *parent)
	: QMainWindow(parent)
{
	
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

void unHook1()
{
	if (cntHook1)
		return;
	cntHook1 = 1;
	UnhookWindowsHookEx(KeyHook1);
}

void unHook2()
{
	if (cntHook2)
		return;
	cntHook2 = 1;
	UnhookWindowsHookEx(KeyHook2);
}


bool DDCbuff::isRunning()
{
	LPCTSTR name = L"ìåï˚ãPêjèÈÅ@Å` Double Dealing Character. ver 1.00b";
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

void DDCbuff::playerStand()
{
	unsigned char code[] = { 0xE9, 0xC6, 0x16, 0x06, 0x00, 0x90, 0x90, 0x90, 0x90, 0x90 };
	unsigned char code2[] = {	
								0x7F, 0x0F, 0xC7, 0x87, 0x84, 0x06, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
								0xE9, 0x27, 0xE9, 0xE9, 0xFF, 0xFF, 0x0D, 0x70, 0x58, 0x4F, 0x00, 0xC7,
								0x87, 0x84, 0x06, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0xE9, 0x12, 0xE9,
								0xF9, 0xFF
							};

	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	WriteProcessMemory(hSnapshot, LPVOID(0x0044F871), code, sizeof(code), NULL);
	WriteProcessMemory(hSnapshot, LPVOID(0x004B0F3C), code2, sizeof(code2), NULL);
}

void DDCbuff::playerStanda()
{
	unsigned char code[] = { 0xC7, 0x87, 0x84, 0x06, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00 };
	unsigned char code2[] = {
								0x7F, 0x0F, 0xC7, 0x87, 0x84, 0x06, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
								0xE9, 0x27, 0xE9, 0xE9, 0xFF, 0xFF, 0x0D, 0x70, 0x58, 0x4F, 0x00, 0xC7,
								0x87, 0x84, 0x06, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0xE9, 0x12, 0xE9,
								0xF9, 0xFF
							};

	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	WriteProcessMemory(hSnapshot, LPVOID(0x0044F871), code, sizeof(code), NULL);
	WriteProcessMemory(hSnapshot, LPVOID(0x004B0F3C), code2, sizeof(code2), NULL);
}

void DDCbuff::punishBonus()
{
	unsigned char code[] = { 0xE9, 0xE4, 0x7E, 0x07, 0x00 };
	unsigned char code2[] = { 
								0x68, 0xA0, 0xA0, 0xA0, 0x80, 0x6A, 0xff, 0X8d, 0X44, 0X24, 0X30, 0X50,
								0x0F, 0x28, 0xDC, 0xE8, 0xB0, 0x70, 0xFA, 0xFF, 0x81, 0x3D, 0x58, 0x58,
								0x4F, 0x00, 0xC8, 0x00, 0x00, 0x00, 0x7C, 0x0C, 0x83, 0x2D, 0x58, 0x58,
								0x4F, 0x00, 0x64, 0xE9, 0xFF, 0x80, 0xF8, 0xFF, 0xC7, 0x05, 0x58, 0x58,
								0x4F, 0x00, 0x64, 0x00, 0x00, 0x00, 0xE9, 0xF0, 0x80, 0xF8, 0xFF
							};

	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	WriteProcessMemory(hSnapshot, LPVOID(0x00439053), code, sizeof(code), NULL);
	WriteProcessMemory(hSnapshot, LPVOID(0x004B0F3C), code2, sizeof(code2), NULL);
}

void DDCbuff::punishBonusa()
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
}

void DDCbuff::inverseBonus()
{
	unsigned char code[] = { 0x7F };
	unsigned char code2[] = { 0x3C, 0x90, 0x90 };

	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS , false, (DWORD)pe.th32ProcessID);
	WriteProcessMemory(hSnapshot, LPVOID(0x00438E01), code, sizeof(code), NULL);
	WriteProcessMemory(hSnapshot, LPVOID(0x00438E31), code2, sizeof(code2), NULL);

}

void DDCbuff::inverseBonusa()
{
	unsigned char code[] = { 0x2C };
	unsigned char code2[] = { 0x32, 0x7C, 0x50 };

	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	WriteProcessMemory(hSnapshot, LPVOID(0x00438E01), code, sizeof(code), NULL);
	WriteProcessMemory(hSnapshot, LPVOID(0x00438E31), code2, sizeof(code2), NULL);

}
