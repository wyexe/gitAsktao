#ifndef __GITASKTAO_GAMEDLL_CORE_OBJECT_PET_PETOBJECT_H__
#define __GITASKTAO_GAMEDLL_CORE_OBJECT_PET_PETOBJECT_H__

#include "BaseObject.h"

class CPetObject : public CBaseObject, public CBaseObjectAttribute
{
public:
	CPetObject(_In_ DWORD dwNodeBase);
	~CPetObject() = default;

	DWORD GetId() CONST;

	DWORD GetObj() CONST;

	VOID SetName();

	DWORD GetLevel() CONST;

	DWORD GetLoyalty() CONST;

	DWORD GetNo() CONST;

	DWORD GetAttributeTreeHead() CONST;
	
	virtual DWORD GetHp() CONST override;

	virtual DWORD GetMaxHP() CONST override;

	virtual DWORD GetMp() CONST override;

	virtual DWORD GetMaxMp() CONST override;

	virtual DWORD GetExp() CONST override;

	virtual DWORD GetMaxExp() CONST override;

	static DWORD GetJoinWarPetId();
private:

};


#endif // !__GITASKTAO_GAMEDLL_CORE_OBJECT_PET_PETOBJECT_H__
