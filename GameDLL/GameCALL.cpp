#include "stdafx.h"
#include "GameCALL.h"

VOID CGameCALL::UseItem_NoFight(_In_ DWORD dwItemId)
{
	__try
	{
		CONST static CHAR szText[] = { "pos = %d" };
		__asm
		{
			PUSHAD;
			PUSH dwItemId;
			LEA EAX, szText;
			PUSH EAX;
			PUSH 0x220C;
			MOV EAX, ·¢°üCALL;
			CALL EAX;
			ADD ESP, 0xC;
			POPAD;
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBoxW(NULL, L"UseItem_NoFight", L"", NULL);
	}
}
