#include "stdafx.h"
#include "Monster.h"
#include <MyTools/Character.h>

CMonster::CMonster(_In_ DWORD dwIndex, _In_ DWORD dwNodeBase)
{
	_dwNodeBase = dwNodeBase;
	_dwIndex = dwIndex;
	auto pszMonsterName = reinterpret_cast<CHAR *>(GetNodeBase() + ¹ÖÎïÃû×ÖÆ«ÒÆ);
	_wsName = MyTools::CCharacter::ASCIIToUnicode(std::string(pszMonsterName));
}

DWORD CMonster::GetId() CONST
{
	return ReadDWORD(GetNodeBase() + 0x8);
}

DWORD CMonster::GetIndex() CONST
{
	return _dwIndex;
}

CMonster::em_Type CMonster::GetType() CONST
{
	return _dwIndex < 10 ? em_Type::em_Type_Monster : em_Type::em_Type_TeamMember;
}

DWORD CMonster::GetHp() CONST
{
	return ReadDWORD(GetNodeBase() + ¶ÓÓÑHPÆ«ÒÆ);
}

DWORD CMonster::GetMaxHP() CONST
{
	return ReadDWORD(GetNodeBase() + ¶ÓÓÑMAXHPÆ«ÒÆ);
}