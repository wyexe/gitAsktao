#ifndef __GITASKTAO_GAMEDLL_CORE_FEATURE_GAMECORE_GAMECALL_H__
#define __GITASKTAO_GAMEDLL_CORE_FEATURE_GAMECORE_GAMECALL_H__

#include "GameStruct.h"

class CGameCALL
{
public:
	using SendCALLPtr = BOOL(WINAPIV*)(...);
	using FightCALLPtr = BOOL(WINAPIV*)(...);
public:
	CGameCALL() = default;
	~CGameCALL() = default;

	static VOID UseItem_NoFight(_In_ DWORD dwItemId);

	static VOID NormalAttack(_In_ DWORD dwInvokeId, _In_ DWORD dwTarId);

	static VOID Defence(_In_ DWORD dwInvokeId);

	static VOID UseItem(_In_ DWORD dwInvokeId, _In_ DWORD dwTarId, _In_ DWORD dwItemId);

	static VOID RunAway(_In_ DWORD dwPersonId);

	static VOID UseSKill(_In_ DWORD dwInvokeId, _In_ DWORD dwTarId, _In_ em_SkillId SkillId);
private:
	static SendCALLPtr	_SendPtr;
	static FightCALLPtr _FightPtr;
	static CHAR         _szEmptyText[32];
};



#endif // !__GITASKTAO_GAMEDLL_CORE_FEATURE_GAMECORE_GAMECALL_H__
