#ifndef __GITASKTAO_GAMEDLL_CORE_FEATURE_BATTLE_BATTLEATTRIBUTE_H__
#define __GITASKTAO_GAMEDLL_CORE_FEATURE_BATTLE_BATTLEATTRIBUTE_H__

#include <Windows.h>

class CBattleAttribute
{
public:
	CBattleAttribute() = default;
	~CBattleAttribute() = default;

	CBattleAttribute(CONST CBattleAttribute&) = delete;
	CBattleAttribute& operator=(CONST CBattleAttribute&) = delete;

	BOOL IsExistFightMeMenu() CONST;

	BOOL IsExistFightPetMenu() CONST;
private:

};



#endif // !__GITASKTAO_GAMEDLL_CORE_FEATURE_BATTLE_BATTLEATTRIBUTE_H__
