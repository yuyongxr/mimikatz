/*	Benjamin DELPY `gentilkiwi`
	http://blog.gentilkiwi.com
	benjamin@gentilkiwi.com
	Licence : http://creativecommons.org/licenses/by/3.0/fr/
*/
#pragma once
#include <ntstatus.h>
#define WIN32_NO_STATUS
#define SECURITY_WIN32
#include <windows.h>
#include <sspi.h>
#include <sddl.h>
#include <wincred.h>
#include <ntsecapi.h>
#include <ntsecpkg.h>
#include <stdio.h>
#include <wchar.h>
#include "../modules/kull_m_output.h"
//#define KERBEROS_TOOLS
//#define DPAPI_TOOLS
//#define LSASS_DECRYPT
#define NET_MODULE
#ifdef _M_X64
	#define MIMIKATZ_ARCH L"x64"
#else ifdef _M_IX86
	#define MIMIKATZ_ARCH L"x86"
#endif

#define MIMIKATZ				L"mimikatz"
#define MIMIKATZ_VERSION		L"2.0 alpha"
#define MIMIKATZ_CODENAME		L"Kiwi en C"
#define MIMIKATZ_FULL			MIMIKATZ L" " MIMIKATZ_VERSION L" (" MIMIKATZ_ARCH L") release \"" MIMIKATZ_CODENAME L"\" (" TEXT(__DATE__) L" " TEXT(__TIME__) L")"
#define MIMIKATZ_SPECIAL		L"                                "
#define MIMIKATZ_DEFAULT_LOG	MIMIKATZ L".log"
#define MIMIKATZ_DRIVER			L"mimidrv"
#define MIMIKATZ_KERBEROS_EXT	L"kirbi"

#ifdef _WINDLL
	#define MIMIKATZ_AUTO_COMMAND_START		0
	#define MIMIKATZ_AUTO_COMMAND_STRING	L"powershell"
#else
	#define MIMIKATZ_AUTO_COMMAND_START		1
	#define MIMIKATZ_AUTO_COMMAND_STRING	L"commandline"
#endif

#ifndef NT_SUCCESS
#define NT_SUCCESS(Status) ((NTSTATUS)(Status) >= 0)
#endif

#ifndef PRINT_ERROR
#define PRINT_ERROR(...) (kprintf(L"ERROR " TEXT(__FUNCTION__) L" ; " __VA_ARGS__))
#endif

#ifndef PRINT_ERROR_AUTO
#define PRINT_ERROR_AUTO(func) (kprintf(L"ERROR " TEXT(__FUNCTION__) L" ; " func L" (0x%08x)\n", GetLastError()))
#endif

#ifndef W00T
#define W00T(...) (kprintf(TEXT(__FUNCTION__) L" w00t! ; " __VA_ARGS__))
#endif

DWORD MIMIKATZ_NT_MAJOR_VERSION, MIMIKATZ_NT_MINOR_VERSION, MIMIKATZ_NT_BUILD_NUMBER;

#ifndef MS_ENH_RSA_AES_PROV_XP
#define MS_ENH_RSA_AES_PROV_XP	L"Microsoft Enhanced RSA and AES Cryptographic Provider (Prototype)"
#endif

#define RtlEqualLuid(L1, L2) (((L1)->LowPart == (L2)->LowPart) && ((L1)->HighPart == (L2)->HighPart))
#define RtlEqualGuid(L1, L2) (RtlEqualMemory(L1, L2, sizeof(GUID)))
#define LM_NTLM_HASH_LENGTH	16

#define KULL_M_WIN_BUILD_XP		2600
#define KULL_M_WIN_BUILD_2K3	3790
#define KULL_M_WIN_BUILD_VISTA	6000
#define KULL_M_WIN_BUILD_7		7600
#define KULL_M_WIN_BUILD_8		9200
#define KULL_M_WIN_BUILD_BLUE	9600
#define KULL_M_WIN_BUILD_10		9800
#define KULL_M_WIN_BUILD_10b	9879

#define KULL_M_WIN_MIN_BUILD_XP		2500
#define KULL_M_WIN_MIN_BUILD_2K3	3000
#define KULL_M_WIN_MIN_BUILD_VISTA	6000
#define KULL_M_WIN_MIN_BUILD_7		7000
#define KULL_M_WIN_MIN_BUILD_8		8000
#define KULL_M_WIN_MIN_BUILD_BLUE	9400
#define KULL_M_WIN_MIN_BUILD_10		9800