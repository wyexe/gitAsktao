#ifndef __GITASKTAO_GAMEDLL_CORE_FEATURE_GAMECORE_GAMECALL_H__
#define __GITASKTAO_GAMEDLL_CORE_FEATURE_GAMECORE_GAMECALL_H__

#include "GameStruct.h"

class CGameCALL
{
public:
	CGameCALL() = default;
	~CGameCALL() = default;

	static VOID UseItem_NoFight(_In_ DWORD dwItemId);
private:

};



#endif // !__GITASKTAO_GAMEDLL_CORE_FEATURE_GAMECORE_GAMECALL_H__
