#include "stdafx.h"
#include "BagItemAction.h"

BOOL CBagItemAction::UseItem_By_ItemName_In_NoFight(_In_ CONST std::wstring& wsItemName) CONST
{
	CBagItem BagItem;
	if (!_BagItemExtend.FindBagItem_By_Name(wsItemName, BagItem))
		return FALSE;

	BagItem.UseItem_NoFight();
	return TRUE;
}
