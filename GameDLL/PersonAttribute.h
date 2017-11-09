#ifndef __GITASKTAO_GAMEDLL_CORE_OBJECT_PERSON_PERSONATTRIBUTE_H__
#define __GITASKTAO_GAMEDLL_CORE_OBJECT_PERSON_PERSONATTRIBUTE_H__

#include "BaseObject.h"

// 非虚函数部分需要呼出Alt+C才可以查看人物属性
class CPersonAttribute : public CBaseObjectAttribute
{
public:
	CPersonAttribute() = default;
	~CPersonAttribute() = default;

	virtual DWORD GetHp() CONST override;
	virtual DWORD GetMaxHP() CONST override;


	virtual DWORD GetMp() CONST override;
	virtual DWORD GetMaxMp() CONST override;


	virtual DWORD GetExp() CONST override;
	virtual DWORD GetMaxExp() CONST override;

	// 战绩
	DWORD	GetTotalScore() CONST;

	// 名字
	std::wstring GetName() CONST;

	// 等级
	DWORD	GetLevel() CONST;

	// 声望
	DWORD	GetReputation() CONST;

	// 帮派
	std::wstring GetPartyName() CONST;

	// 帮贡
	DWORD	GetPartyContrib() CONST;

	// 道行(/年)
	DWORD GetDaoXing() CONST;

	// 潜能
	DWORD	GetPot() CONST;

	// 还没加的属性点
	DWORD	GetAttributePoint() CONST;

	// 还没加的相性点
	DWORD	GetPolarPoint() CONST;

	// 金币
	struct CashContent
	{
		DWORD dwCash	= 0;  // 金币
		DWORD dwMoney	= 0; // 代金卷
	};
	CashContent	GetMoney() CONST;

	// 坐标
	Point	GetPoint() CONST;

	// 地图
	std::wstring GetMapName() CONST;

	// 线路
	std::wstring GetCurrentLine();

	// 是否战斗中
	BOOL IsFighting() CONST;

	// 获取门派
	std::wstring GetFamily() CONST;

	// 门派师傅
	std::wstring GetFamilyMaster() CONST;
};



#endif // !__GITASKTAO_GAMEDLL_CORE_OBJECT_PERSON_PERSONATTRIBUTE_H__
