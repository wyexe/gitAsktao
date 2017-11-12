#include "stdafx.h"
#include "GameCALL.h"

CGameCALL::SendCALLPtr CGameCALL::_SendPtr = reinterpret_cast<CGameCALL::SendCALLPtr>(·¢°üCALL);
CGameCALL::FightCALLPtr CGameCALL::_FightPtr = reinterpret_cast<CGameCALL::SendCALLPtr>(Õ½¶·CALL);
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