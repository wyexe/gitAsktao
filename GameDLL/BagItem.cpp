#include "stdafx.h"
#include "BagItem.h"
#include <MyTools/Character.h>
#include <MyTools/Log.h>
#include "ObjectFunction.h"
#include "CodeTransfer.h"
#include "GameCALL.h"

#define _SELF L"BagItem.cpp"
CBagItem::CBagItem(_In_ DWORD dwNodeBase)
{
	_dwNodeBase = dwNodeBase;
	if(_dwNodeBase != NULL)
		SetName();
}

CBagItem::CBagItem()
{
	_dwNodeBase = 0;
}

VOID CBagItem::SetName()
{
	_wsName = CObjectFunction::GetInstance().GetAttributeText_By_Key(GetAttributeTreeHead(), L"name");
}

DWORD CBagItem::GetObjAddr() CONST
{
	return ReadDWORD(GetNodeBase() + 0x10);
}

DWORD CBagItem::GetItemType() CONST
{
	// 1=装备
	return CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributeTreeHead(), L"item_type");
}

DWORD CBagItem::GetDurability() CONST
{
	return CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributeTreeHead(), L"durability");
}

DWORD CBagItem::GetCount() CONST
{
	return CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributeTreeHead(), L"server_count");
}

DWORD CBagItem::GetId() CONST
{
	return CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributeTreeHead(), L"pos");
}

DWORD CBagItem::GetAttributeTreeHead() CONST
{
	return ReadDWORD(ReadDWORD(GetObjAddr() + 0x4 + 0x4 + 0x4) + 0x4);
}

VOID CBagItem::UseItem_NoFight()
{
	LOG_C_D(L"非战斗下使用物品[%s]", GetName().c_str());
	CCodeTransfer::PushPtrToMainThread([this] { CGameCALL::UseItem_NoFight(GetId()); });
}
