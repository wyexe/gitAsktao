#ifndef __GITASKTAO_GAMEDLL_CORE_OBJECT_MONSTER_MONSTER_H__
#define __GITASKTAO_GAMEDLL_CORE_OBJECT_MONSTER_MONSTER_H__

#include "BaseObject.h"

class CMonster : public CBaseObject, public CBaseObjectAttribute
{
public:
	enum class em_Type
	{
		em_Type_Monster,
		em_Type_TeamMember
	};
public:
	CMonster() = default;
	CMonster(_In_ DWORD dwIndex, _In_ DWORD dwNodeBase);
	~CMonster() = default;

	DWORD GetId() CONST;

	DWORD GetIndex() CONST;

	em_Type GetType() CONST;

	virtual DWORD GetHp() CONST override;

	virtual DWORD GetMaxHP() CONST override;
private:
	DWORD _dwIndex = NULL;
};



#endif // !__GITASKTAO_GAMEDLL_CORE_OBJECT_MONSTER_MONSTER_H__
