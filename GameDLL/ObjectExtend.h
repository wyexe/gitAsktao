#ifndef __GITASKTAO_GAMEDLL_CORE_OBJECT_OBJECTEXTEND_H__
#define __GITASKTAO_GAMEDLL_CORE_OBJECT_OBJECTEXTEND_H__

#include <map>
#include <mutex>
#include <MyTools/ClassInstance.h>

class CGameUi;
class CMonster;
class CObjectExtend
{
public:
	CObjectExtend() = default;
	~CObjectExtend() = default;

	// π÷ŒÔ±È¿˙
	UINT GetVecMonster(_Out_ std::vector<CMonster>& VecMonster) CONST;

	// UI±È¿˙
	UINT GetGameUiList(_Out_ std::map<std::wstring, CGameUi>& GameUiList) CONST;

	// 
	BOOL FindPersonAttribute_By_Key(_In_ CONST std::wstring& wsKey, _Out_ std::wstring& wsValue) CONST;
private:
	//
	VOID TraverseGameUi(_In_ DWORD dwNode, _Out_ std::vector<DWORD>& VecGameUiNode) CONST;
private:
	virtual VOID AbstractMethod() = NULL;

	CObjectExtend(CONST CObjectExtend&) = delete;
	CObjectExtend& operator =(CONST CObjectExtend&) = delete;
};



#endif // !__GITASKTAO_GAMEDLL_CORE_OBJECT_OBJECTEXTEND_H__
