#ifndef __GITASKTAO_GAMEDLL_CORE_FEATURE_BATTLE_BATTLEACTION_H__
#define __GITASKTAO_GAMEDLL_CORE_FEATURE_BATTLE_BATTLEACTION_H__

#include "Monster.h"
#include "PersonAttribute.h"

#define BATTLE_OPTION_SKILL		0x1	// 甩技能
#define BATTLE_OPTION_CONTROL	0x2	// 使用障碍技能
#define BATTLE_OPTION_HELP		0x4 // 使用辅助技能
class CBattleAction
{
public:
	CBattleAction();
	~CBattleAction() = default;

	BOOL Fight();

	VOID ContinueAutoFight() CONST;
private:
	VOID RefreshData();

	CONST CMonster* FindPerson() CONST;

	CONST CMonster* FindPet() CONST;

	CONST CMonster* FindTarget() CONST;
private:
	VOID Fight_Classes_金() CONST;

	VOID Fight_Classes_木() CONST;

	VOID Fight_Classes_水() CONST;

	VOID Fight_Classes_火() CONST;

	VOID Fight_Classes_土() CONST;

	VOID Fight_Classes_Pet() CONST;
private:
	std::vector<CMonster>	_VecMonster;
	std::wstring			_wsPersonName;
	CPersonAttribute::em_Family _emPersonFamily;
	CPersonAttribute		_PersonAttribute;
};



#endif // !__GITASKTAO_GAMEDLL_CORE_FEATURE_BATTLE_BATTLEACTION_H__
