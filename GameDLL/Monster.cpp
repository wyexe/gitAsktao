#include "stdafx.h"
#include "Monster.h"
#include <MyTools/Character.h>
#include <MyTools/CLEchoException.h>
#include "CodeTransfer.h"
#include "GameCALL.h"

CMonster::CMonster(_In_ DWORD dwIndex, _In_ DWORD dwNodeBase)
{
	_dwNodeBase = dwNodeBase;
	if (_dwNodeBase != NULL)
	{
		_dwIndex = dwIndex;
		auto pszMonsterName = reinterpret_cast<CHAR *>(GetNodeBase() + ¹ÖÎïÃû×ÖÆ«ÒÆ + 0x4);
		_wsName = MyTools::CCharacter::ASCIIToUnicode(std::string(pszMonsterName));
	}
}

DWORD CMonster::GetId() CONST
{
	return MyTools::CLEchoException::GetInstance().InvokeFunc<DWORD>(__FUNCTIONW__, [this] 
	{
		DWORD dwValue = 0;
		DWORD dwAddr = GetNodeBase();

		__asm
		{
			MOV EAX, dwAddr;
			MOV EAX, DWORD PTR DS : [EAX];
			MOV EAX, DWORD PTR DS : [EAX + ¹ÖÎï¹¥»÷IDÐéº¯ÊýÆ«ÒÆ];
			MOV ECX, dwAddr;
			CALL EAX;
			MOV dwValue, EAX;
		}

		return dwValue;
	});
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

VOID CMonster::NormalAttack_To_Target(_In_ CONST CMonster& Target) CONST
{
	CCodeTransfer::PushPtrToMainThread([this, Target] { CGameCALL::NormalAttack(GetId(), Target.GetId()); });
}

VOID CMonster::Defence() CONST
{
	CCodeTransfer::PushPtrToMainThread([this] { CGameCALL::Defence(GetId()); });
}

VOID CMonster::UseItem_To_Target(_In_ CONST CMonster& Target, _In_ CONST CBagItem& Item) CONST
{
	CCodeTransfer::PushPtrToMainThread([=] { CGameCALL::UseItem(GetId(), Target.GetId(), Item.GetId()); });
}

VOID CMonster::RunAway() CONST
{
	CCodeTransfer::PushPtrToMainThread([this] { CGameCALL::RunAway(GetId()); });
}

VOID CMonster::UseSkill(_In_ CONST CMonster& Target, _In_ em_SkillId emSkillId) CONST
{
	CCodeTransfer::PushPtrToMainThread([=] { CGameCALL::UseSKill(this->GetId(), Target.GetId(), emSkillId); });
}
