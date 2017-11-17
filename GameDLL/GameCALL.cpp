#include "stdafx.h"
#include "GameCALL.h"

CGameCALL::SendCALLPtr CGameCALL::_SendPtr = reinterpret_cast<CGameCALL::SendCALLPtr>(发包CALL);
CGameCALL::FightCALLPtr CGameCALL::_FightPtr = reinterpret_cast<CGameCALL::SendCALLPtr>(战斗CALL);
CHAR CGameCALL::_szEmptyText[32] = { 0 };
VOID CGameCALL::UseItem_NoFight(_In_ DWORD dwItemId)
{
	__try
	{
		CONST static CHAR szText[] = { "pos = %d" };
		_SendPtr(dwItemId, szText, 0x220C);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBoxW(NULL, L"UseItem_NoFight", L"", NULL);
	}
}

VOID CGameCALL::NormalAttack(_In_ DWORD dwInvokeId, _In_ DWORD dwTarId)
{
	__try
	{
		_FightPtr(dwInvokeId, dwTarId, 0x2, 0x0, _szEmptyText, _szEmptyText, _szEmptyText, 0, _szEmptyText);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBoxW(NULL, L"NormalAttack", L"", NULL);
	}
}

VOID CGameCALL::Defence(_In_ DWORD dwInvokeId)
{
	__try
	{
		_FightPtr(dwInvokeId, dwInvokeId, 0x1, 0x0, _szEmptyText, _szEmptyText, _szEmptyText, 0, _szEmptyText);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBoxW(NULL, L"Defence", L"", NULL);
	}
}

VOID CGameCALL::UseItem(_In_ DWORD dwInvokeId, _In_ DWORD dwTarId, _In_ DWORD dwItemId)
{
	__try
	{
		_FightPtr(dwInvokeId, dwTarId, 0x4, dwItemId, _szEmptyText, _szEmptyText, _szEmptyText, 0, _szEmptyText);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBoxW(NULL, L"UseItem", L"", NULL);
	}
}

VOID CGameCALL::RunAway(_In_ DWORD dwPersonId)
{
	__try
	{
		_FightPtr(dwPersonId, dwPersonId, 0x7, 0x0, _szEmptyText, _szEmptyText, _szEmptyText, 0, _szEmptyText);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBoxW(NULL, L"RunAway", L"", NULL);
	}
}

VOID CGameCALL::UseSKill(_In_ DWORD dwInvokeId, _In_ DWORD dwTarId, _In_ em_SkillId SkillId)
{
	__try
	{
		_FightPtr(dwInvokeId, dwTarId, 0x3, SkillId, _szEmptyText, _szEmptyText, _szEmptyText, 0, _szEmptyText);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBoxW(NULL, L"UseSKill", L"", NULL);
	}
}

VOID CGameCALL::Walk(_In_ DWORD dwX, _In_ DWORD dwY)
{
	__try
	{
		dwX *= 0x18;
		dwY *= 0x18;
		__asm
		{
			MOV EAX, 走路CALL基址;
			MOV EAX, DWORD PTR DS : [EAX];
			MOV ESI, DWORD PTR DS : [EAX];
			MOV EDX, DWORD PTR DS : [ESI + 走路偏移];

			PUSH dwX;
			PUSH dwY;

			MOV ECX, 走路基址;
			MOV ECX, DWORD PTR DS : [ECX];
			CALL EDX;
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBoxW(NULL, L"Walk", L"", NULL);
	}
}

VOID CGameCALL::ClickChildGameUi(_In_ DWORD dwUiObject)
{
	__try
	{
		CONST static CHAR szText[] = { "CLICKED_BTN"};
		__asm
		{
			PUSH 0x0;
			LEA EAX, szText;
			PUSH EAX;

			MOV ECX, dwUiObject;
			MOV EAX, 鼠标点击CALL;
			CALL EAX;
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBoxW(NULL, L"ClickChildGameUi", L"", NULL);
	}
}

VOID CGameCALL::FindPath(_In_ LPCSTR pszText)
{
	__try
	{
		DWORD dwArray[128] = { 0 };
		dwArray[寻路Buffer偏移 / 4] = 0xC136;

		__asm
		{
			MOV EAX, pszText;
			PUSH EAX;
			
			LEA ECX, dwArray;
			MOV EAX, 寻路CALL;
			CALL EAX;
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBoxW(NULL, L"FindPath", L"", NULL);
	}
}

VOID CGameCALL::PetAddHp(_In_ DWORD dwPetObject)
{
	__try
	{
		CONST static CHAR szText[] = { "life" };
		__asm
		{
			MOV ECX, 宠物补血基址;
			MOV ECX, DWORD PTR DS : [ECX];

			PUSH 0;
			PUSH 0x64;
			
			LEA EAX, szText;
			PUSH EAX;

			PUSH dwPetObject;

			MOV EAX, 宠物补血CALL;
			CALL EAX;
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBoxW(NULL, L"PetAddHp", L"", NULL);
	}
}

VOID CGameCALL::PetAddMp(_In_ DWORD dwPetObject)
{
	__try
	{
		CONST static CHAR szText[] = { "mana" };
		__asm
		{
			MOV ECX, 宠物补血基址;
			MOV ECX, DWORD PTR DS : [ECX];

			PUSH 0;
			PUSH 0x64;

			LEA EAX, szText;
			PUSH EAX;

			PUSH dwPetObject;

			MOV EAX, 宠物补血CALL;
			CALL EAX;
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBoxW(NULL, L"PetAddHp", L"", NULL);
	}
}

VOID CGameCALL::OpenNpc(_In_ DWORD dwNpcId)
{
	__try
	{
		CONST static CHAR szText[] = { "id = %d" };
		_SendPtr(dwNpcId, szText, 0x2050);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBoxW(NULL, L"OpenNpc", L"", NULL);
	}
}

VOID CGameCALL::ClickNpcMenu(_In_ DWORD dwGameUiObject)
{
	__try
	{
		__asm
		{
			MOV EBX, dwGameUiObject;
			MOV EAX, DWORD PTR DS : [EBX + Npc选项菜单点击偏移];
			PUSH 0;
			MOV ECX, EBX;
			CALL EAX;
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBoxW(NULL, L"ClickNpcMenu", L"", NULL);
	}
}

VOID CGameCALL::PersonAddHp()
{
	__try
	{
		static CONST CHAR szText[] = { "life" };
		__asm
		{
			MOV ECX, 人物属性基址;
			MOV ECX, DWORD PTR DS : [ECX];

			PUSH 0;
			PUSH 0x64;
			LEA EAX, szText;
			PUSH EAX;
			PUSH ECX;

			MOV ECX, 人物补血基址;
			MOV EAX, 人物补血CALL;
			CALL EAX;
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBoxW(NULL, L"PersonAddHp", L"", NULL);
	}
}

VOID CGameCALL::PersonAddMp()
{
	__try
	{
		static CONST CHAR szText[] = { "mana" };
		__asm
		{
			MOV ECX, 人物属性基址;
			MOV ECX, DWORD PTR DS : [ECX];

			PUSH 0;
			PUSH 0x64;
			LEA EAX, szText;
			PUSH EAX;
			PUSH ECX;

			MOV ECX, 人物补血基址;
			MOV EAX, 人物补血CALL;
			CALL EAX;
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBoxW(NULL, L"PersonAddMp", L"", NULL);
	}
}

VOID CGameCALL::SkipTalk(_In_ DWORD dwGameUiObject)
{
	__try
	{
		// TalkNoMenuDlg
		__asm
		{
			MOV ECX, dwGameUiObject;
			MOV EAX, 跳过对话CALL;
			CALL EAX;
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBoxW(NULL, L"SkipTalk", L"", NULL);
	}
}

