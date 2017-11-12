#ifndef _GITASKTAO_GAMEDLL_CORE_FEATURE_GAMECORE_CODETRANSFER_H__
#define _GITASKTAO_GAMEDLL_CORE_FEATURE_GAMECORE_CODETRANSFER_H__

#include <MyTools/ToolsPublic.h>

class CCodeTransfer
{
public:
	struct ThreadMethodInfo
	{
		std::function<VOID(VOID)> ThreadExcutePtr;
		HANDLE                    hEvent;
	};
public:
	CCodeTransfer() = default;
	~CCodeTransfer() = default;

	static VOID Hook();

	static VOID UnHook();

	static VOID PushPtrToMainThread(_In_ std::function<VOID(VOID)> MethodPtr);

	static VOID ExcutePtr();

private:
	static BOOL WINAPI _PeekMessage(_Out_ LPMSG lpMsg, _In_opt_ HWND hWnd, _In_ UINT wMsgFilterMin, _In_ UINT wMsgFilterMax, _In_ UINT wRemoveMsg);

	static VOID Action_In_HookVirtualProtect(_In_ std::function<VOID(VOID)> Ptr);

	static DWORD GetHookVirtualProtectAddr();
};



#endif // !_GITASKTAO_GAMEDLL_CORE_FEATURE_GAMECORE_CODETRANSFER_H__
