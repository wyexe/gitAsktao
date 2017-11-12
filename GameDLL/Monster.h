#ifndef __GITASKTAO_GAMEDLL_CORE_OBJECT_MONSTER_MONSTER_H__
#define __GITASKTAO_GAMEDLL_CORE_OBJECT_MONSTER_MONSTER_H__

#include "BaseObject.h"
#include "BagItem.h"

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

public:
	///-----Attribute---------------------------------------
	DWORD GetId() CONST;

	DWORD GetIndex() CONST;

	em_Type GetType() CONST;

	virtual DWORD GetHp() CONST override;

	virtual DWORD GetMaxHP() CONST override;
public:
	///-----Action---------------------------------------
	VOID NormalAttack_To_Target(_In_ CONST CMonster& Target) CONST;

	VOID Defence() CONST;

	VOID UseItem_To_Target(_In_ CONST CMonster& Target, _In_ CONST CBagItem& Item) CONST;

	VOID RunAway() CONST;
private:
	DWORD _dwIndex = NULL;
};



#endif // !__GITASKTAO_GAMEDLL_CORE_OBJECT_MONSTER_MONSTER_H__
