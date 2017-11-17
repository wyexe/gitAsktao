#include "stdafx.h"
#include "PetObject.h"
#include <MyTools/Character.h>
#include "ObjectFunction.h"

CPetObject::CPetObject(_In_ DWORD dwNodeBase)
{
	_dwNodeBase = dwNodeBase;
	if (dwNodeBase != NULL)
	{
		SetName();
	}
}

DWORD CPetObject::GetId() CONST
{
	return CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributeTreeHead(), L"id");
}

DWORD CPetObject::GetObj() CONST
{
	return ReadDWORD(GetNodeBase() + 0x10);
}

VOID CPetObject::SetName()
{
	_wsName = CObjectFunction::GetInstance().GetAttributeText_By_Key(GetAttributeTreeHead(), L"name");
}

DWORD CPetObject::GetLevel() CONST
{
	return CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributeTreeHead(), L"level");
}

DWORD CPetObject::GetLoyalty() CONST
{
	return CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributeTreeHead(), L"loyalty");
}

DWORD CPetObject::GetNo() CONST
{
	return CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributeTreeHead(), L"no");
}

DWORD CPetObject::GetAttributeTreeHead() CONST
{
	return ReadDWORD(ReadDWORD(GetObj() + 人物属性偏移 + 0x4 + 0x4) + 0x4);
}

DWORD CPetObject::GetHp() CONST
{
	return CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributeTreeHead(), L"life");
}

DWORD CPetObject::GetMaxHP() CONST
{
	return CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributeTreeHead(), L"max_life");
}

DWORD CPetObject::GetMp() CONST
{
	return CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributeTreeHead(), L"mana");
}

DWORD CPetObject::GetMaxMp() CONST
{
	return CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributeTreeHead(), L"max_mana");
}

DWORD CPetObject::GetExp() CONST
{
	return CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributeTreeHead(), L"exp");
}

DWORD CPetObject::GetMaxExp() CONST
{
	return CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributeTreeHead(), L"exp_to_next_level");
}

DWORD CPetObject::GetJoinWarPetId()
{
	return ReadDWORD(ReadDWORD(宠物基址) + 宠物出战ID偏移);
}
