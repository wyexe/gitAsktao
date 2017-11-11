#include "stdafx.h"
#include "BagItemExtend.h"
#include "ObjectFunction.h"

BOOL CBagItemExtend::FindBagItem_By_Name(_In_ CONST std::wstring& wsItemName, _Out_ CBagItem& BagItem) CONST
{
	std::vector<CBagItem> Vec;
	CObjectFunction::GetInstance().GetVecBagItem(Vec, [wsItemName](CONST CBagItem& itm) {return itm.GetName() == wsItemName; });
	if (Vec.empty())
		return FALSE;


	BagItem = Vec.at(0);
	return TRUE;
}

UINT CBagItemExtend::GetCount_By_ItemName(_In_ CONST std::wstring& wsItemName) CONST
{
	std::vector<CBagItem> Vec;
	CObjectFunction::GetInstance().GetVecBagItem(Vec, nullptr);

	UINT uCount = 0;
	std::for_each(Vec.begin(), Vec.end(), [wsItemName, &uCount](CONST CBagItem& itm)
	{
		if (itm.GetName() == wsItemName)
			uCount += itm.GetCount();

	});

	return uCount;
}
