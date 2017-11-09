#ifndef __GITASKTAO_GAMEDLL_CORE_OBJECT_PET_PETATTRIBUTE_H__
#define __GITASKTAO_GAMEDLL_CORE_OBJECT_PET_PETATTRIBUTE_H__

#include "BaseObject.h"

class CPetAttribute : public CBaseObjectAttribute
{
public:
	CPetAttribute() = default;
	~CPetAttribute() = default;

	virtual DWORD GetHp() CONST override;
	virtual DWORD GetMaxHP() CONST override;


	virtual DWORD GetMp() CONST override;
	virtual DWORD GetMaxMp() CONST override;


	virtual DWORD GetExp() CONST override;
	virtual DWORD GetMaxExp() CONST override;

	// 等级
	DWORD	GetLevel() CONST;

	// 名称
	std::wstring GetName() CONST;

	// 属性点
	DWORD	GetAttributePoint() CONST;

	// 忠诚度
	DWORD	GetLoyal() CONST;
private:

};



#endif // !__GITASKTAO_GAMEDLL_CORE_OBJECT_PET_PETATTRIBUTE_H__
