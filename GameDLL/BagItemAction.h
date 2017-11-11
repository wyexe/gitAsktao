#ifndef __GITASKTAO_GAMEDLL_CORE_OBJECT_BAG_BAGITEMACTION_H__
#define __GITASKTAO_GAMEDLL_CORE_OBJECT_BAG_BAGITEMACTION_H__

#include "BagItemExtend.h"

class CBagItemAction
{
public:
	CBagItemAction() = default;
	~CBagItemAction() = default;

	BOOL UseItem_By_ItemName_In_NoFight(_In_ CONST std::wstring& wsItemName) CONST;


private:
	CBagItemExtend _BagItemExtend;
};


#endif // !__GITASKTAO_GAMEDLL_CORE_OBJECT_BAG_BAGITEMACTION_H__
