#include "stdafx.h"
#include "CodeTransfer.h"
#include <thread>
#include <future>
#include <Psapi.h>
#include <MyTools/Character.h>
#include <MyTools/CLThread.h>
#include <MyTools/LdrHeader.h>
#include <MyTools/CLPublic.h>
#include <MyTools/CLProcess.h>
#include <MyTools/CLAsync.h>
#include <MyTools/CmdLog.h>
#include <MyTools/TimeTick.h>
#include <MyTools/Log.h>
#include "GameVariable.h"

#define _SELF L"CodeTransfer.cpp"


using PeekMessageAPtr = BOOL(WINAPI*)(_Out_ LPMSG lpMsg, _In_opt_ HWND hWnd, _In_ UINT wMsgFilterMin, _In_ UINT wMsgFilterMax, _In_ UINT wRemoveMsg);
static CRITICAL_SECTION _Lock;
static std::queue<CCodeTransfer::ThreadMethodInfo> _QueThreadMethod;
static PeekMessageAPtr _OldPeekMessagePtr = nullptr;

VOID CCodeTransfer::Hook()
{
	::InitializeCriticalSection(&_Lock);
	auto RealPeekMessagePtr = reinterpret_cast<PeekMessageAPtr>(::GetProcAddress(::GetModuleHandleW(L"user32.dll"), "PeekMessageA"));
	CValueVariable::GetInstance().SetValueAndGetOldValue_By_Id(em_VariableName::NewPeekMessageAddr, reinterpret_cast<DWORD>(RealPeekMessagePtr));

	MyTools::CLdrHeader().InlineHook(RealPeekMessagePtr, _PeekMessage, reinterpret_cast<void **>(&_OldPeekMessagePtr));

	if (ReadBYTE(Hook¼ì²â1) != 0xEB)
	{
		LOG_C_D(L"ÐÞ¸ÄHook¼ì²â1  Addr=%X", GetHookVirtualProtectAddr());
		Action_In_HookVirtualProtect([] {MyTools::CCharacter::WriteBYTE(Hook¼ì²â1, 0xEB); });
		LOG_C_D(L"ÐÞ¸Ä%s", ReadBYTE(Hook¼ì²â1) != 0xEB ? L"Ê§°Ü" : L"³É¹¦");
	}
}

VOID CCodeTransfer::UnHook()
{
	auto RealPeekMessagePtr = reinterpret_cast<PeekMessageAPtr>(CValueVariable::GetInstance().GetRefValue_By_Id(em_VariableName::NewPeekMessageAddr));
	if (RealPeekMessagePtr != nullptr && _OldPeekMessagePtr != nullptr)
	{
		MyTools::CLdrHeader().UnInlineHook(RealPeekMessagePtr, reinterpret_cast<void *>(_OldPeekMessagePtr));
		CValueVariable::GetInstance().SetValueAndGetOldValue_By_Id(em_VariableName::NewPeekMessageAddr, 0);
	}

	// ¼ÓËøÅÐ¶ÏÑ­»·½áÊø!
	::EnterCriticalSection(&_Lock);
	::LeaveCriticalSection(&_Lock);
	::DeleteCriticalSection(&_Lock);
}

VOID CCodeTransfer::PushPtrToMainThread(_In_ std::function<VOID(VOID)> MethodPtr)
{
	ThreadMethodInfo ThreadMethodInfo_;
	ThreadMethodInfo_.hEvent = ::CreateEventW(NULL, FALSE, FALSE, NULL);
	if (ThreadMethodInfo_.hEvent == NULL)
	{
		LOG_MSG_CF(L"hEvent = NULL, Err=%d", ::GetLastError());
		return;
	}

	ThreadMethodInfo_.ThreadExcutePtr = MethodPtr;

	::EnterCriticalSection(&_Lock);
	_QueThreadMethod.push(ThreadMethodInfo_);
	::LeaveCriticalSection(&_Lock);

//	::PostMessageW(CValueVariable::GetInstance().GetGameHwnd() , WM_NULL, NULL, NULL);
	::WaitForSingleObject(ThreadMethodInfo_.hEvent, INFINITE);
	::CloseHandle(ThreadMethodInfo_.hEvent);
	ThreadMethodInfo_.hEvent = INVALID_HANDLE_VALUE;
}

VOID CCodeTransfer::ExcutePtr()
{
	::EnterCriticalSection(&_Lock);
	if (!_QueThreadMethod.empty())
	{
		auto& itm = _QueThreadMethod.front();
		itm.ThreadExcutePtr();
		::SetEvent(itm.hEvent);
		_QueThreadMethod.pop();
	}
	::LeaveCriticalSection(&_Lock);
}

BOOL WINAPI CCodeTransfer::_PeekMessage(_Out_ LPMSG lpMsg, _In_opt_ HWND hWnd, _In_ UINT wMsgFilterMin, _In_ UINT wMsgFilterMax, _In_ UINT wRemoveMsg)
{
	BOOL bRetCode = _OldPeekMessagePtr(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg);
	ExcutePtr();
	return bRetCode;
}

VOID CCodeTransfer::Action_In_HookVirtualProtect(_In_ std::function<VOID(VOID)> Ptr)
{
	DWORD dwOldHookVirtualProtectValue1 = ReadDWORD(GetHookVirtualProtectAddr());
	DWORD dwOldHookVirtualProtectValue2 = ReadDWORD(GetHookVirtualProtectAddr() + 0x4);
	//LOG_C_D(L"dwOldHookVirtualProtectValue=[%X,%X]", dwOldHookVirtualProtectValue1, dwOldHookVirtualProtectValue2);

	DWORD dwProtect = 0;
	::VirtualProtect(reinterpret_cast<LPVOID>(»Ö¸´VirtualProtect), 0x8, PAGE_EXECUTE_READWRITE, &dwProtect);
	*reinterpret_cast<DWORD*>(GetHookVirtualProtectAddr() + 0x0) = 0x4DB8;
	*reinterpret_cast<BYTE*>(GetHookVirtualProtectAddr() + 0x4) = 0x0000;
	Ptr();
	*reinterpret_cast<DWORD*>(GetHookVirtualProtectAddr() + 0x0) = dwOldHookVirtualProtectValue1;
	*reinterpret_cast<DWORD*>(GetHookVirtualProtectAddr() + 0x4) = dwOldHookVirtualProtectValue2;
	::VirtualProtect(reinterpret_cast<LPVOID>(»Ö¸´VirtualProtect), 0x8, dwProtect, &dwProtect);
}

DWORD CCodeTransfer::GetHookVirtualProtectAddr()
{
	static DWORD dwAddr = »Ö¸´VirtualProtect - NTDLLµØÖ· + reinterpret_cast<DWORD>(::GetModuleHandleW(L"ntdll.dll"));
	return dwAddr;
}
