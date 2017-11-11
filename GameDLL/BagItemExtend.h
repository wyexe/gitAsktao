#ifndef __GITASKTAO_GAMEDLL_CORE_OBJECT_BAG_BAGITEMEXTEND_H__
#define __GITASKTAO_GAMEDLL_CORE_OBJECT_BAG_BAGITEMEXTEND_H__

#include "BagItem.h"

class CBagItemExtend
{
public:
	CBagItemExtend() = default;
	~CBagItemExtend() = default;

	BOOL FindBagItem_By_Name(_In_ CONST std::wstring& wsItemName, _Out_ CBagItem& BagItem) CONST;

	UINT GetCount_By_ItemName(_In_ CONST std::wstring& wsItemName) CONST;
private:

};



#endif // !__GITASKTAO_GAMEDLL_CORE_OBJECT_BAG_BAGITEMEXTEND_H__
