#include "stdafx.h"
#include "BagItem.h"
#include <MyTools/Character.h>
#include "ObjectFunction.h"
#include "CodeTransfer.h"
#include "GameCALL.h"

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
	// 1=×°±¸
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
	CCodeTransfer::PushPtrToMainThread([this] { CGameCALL::UseItem_NoFight(GetId()); });
}
