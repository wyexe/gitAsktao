#include "stdafx.h"
#include "GameUi.h"
#include <MyTools/Character.h>
#include <MyTools/Log.h>

#define _SELF L"GameUi.cpp"
CGameUi::CGameUi(_In_ DWORD dwNodeBase)
{
	_dwNodeBase = dwNodeBase;
	auto pszNamePtr = reinterpret_cast<CHAR*>(GetObj() + UIName偏移);
	_wsName = MyTools::CCharacter::ASCIIToUnicode(std::string(pszNamePtr));
}

DWORD CGameUi::GetObj() CONST
{
	return ReadDWORD(GetNodeBase() + 0x8);
}

BOOL CGameUi::IsShow() CONST
{
	return ReadBYTE(GetObj() + 人物战斗菜单UI偏移) != 0;
}
