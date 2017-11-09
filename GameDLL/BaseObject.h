#ifndef __GITASKTAO_GAMEDLL_CORE_OBJECT_BASEOBJECT_BASEOBJECT_H__
#define __GITASKTAO_GAMEDLL_CORE_OBJECT_BASEOBJECT_BASEOBJECT_H__

#include "GameStruct.h"
#include <MyTools/ToolsPublic.h>

class CBaseObject
{
public:
	CBaseObject() = default;
	~CBaseObject() = default;

	virtual DWORD GetNodeBase() CONST { return _dwNodeBase; }

	CONST std::wstring& GetName() CONST { return _wsName; }
protected:
	DWORD			_dwNodeBase = NULL;
	std::wstring	_wsName;
};

class CBaseObjectAttribute
{
protected:
	template<typename ValueType>
	static DWORD GetPercentValue(_In_ ValueType&& Value, _In_ ValueType&& MaxValue)
	{
		return (MaxValue == 0  || MaxValue  == 0xFFFFFFFF) ? 0 : Value * 100 / MaxValue;
	}
public:
	CBaseObjectAttribute() = default;
	~CBaseObjectAttribute() = default;

	///---HP--------------------------------------------
	virtual DWORD GetHp() CONST = NULL;
	virtual DWORD GetMaxHP() CONST = NULL;
	DWORD GetPercentHp() CONST { return GetPercentValue(GetHp(), GetMaxHP()); };


	///---MP--------------------------------------------
	virtual DWORD GetMp() CONST { return 0; };
	virtual DWORD GetMaxMp() CONST { return 0; };
	DWORD GetPercentMp() CONST { return GetPercentValue(GetMp(), GetMaxMp()); };

	///---Expr--------------------------------------------
	virtual DWORD GetExp() CONST { return 0; };
	virtual DWORD GetMaxExp() CONST { return 0; };
	DWORD GetPercentExp() CONST { return GetPercentValue(GetExp(), GetMaxExp()); };


private:

};



#endif // !__GITASKTAO_GAMEDLL_CORE_OBJECT_BASEOBJECT_BASEOBJECT_H__
