#include "stdafx.h"
#include "BagItem.h"
#include <MyTools/Character.h>
#include "ObjectFunction.h"
#include "CodeTransfer.h"
#include "GameCALL.h"

CBagItem::CBagItem(_In_ DWORD dwNodeBase)
{
	_dwNodeBase = dwNodeBase;
	SetName();
}

CBagItem::CBagItem()
{
	_dwNodeBase = 0;
}

VOID CBagItem::SetName()
{
	_wsName = CObjectFunction::GetInstance().GetItemText_By_Key(*this, L"name");
}

DWORD CBagItem::GetObjAddr() CONST
{
	return ReadDWORD(GetNodeBase() + 0x10);
}

DWORD CBagItem::GetItemType() CONST
{
	// 1=×°±¸
	return CObjectFunction::GetInstance().GetItemValue_By_Key(*this, L"item_type");
}

DWORD CBagItem::GetDurability() CONST
{
	return CObjectFunction::GetInstance().GetItemValue_By_Key(*this, L"durability");
}

DWORD CBagItem::GetCount() CONST
{
	return CObjectFunction::GetInstance().GetItemValue_By_Key(*this, L"server_count");
}

DWORD CBagItem::GetId() CONST
{
	return CObjectFunction::GetInstance().GetItemValue_By_Key(*this, L"pos");
}

VOID CBagItem::UseItem_NoFight()
{
	CCodeTransfer::PushPtrToMainThread([this] { CGameCALL::UseItem_NoFight(GetId()); });
}
