#ifndef __GITASKTAO_GAMEDLL_CORE_OBJECT_OBJECTFUNCTION_H__
#define __GITASKTAO_GAMEDLL_CORE_OBJECT_OBJECTFUNCTION_H__

#include <MyTools/ClassInstance.h>
#include "ObjectExtend.h"
#include "GameUi.h"


class CObjectFunction : public CObjectExtend, public MyTools::CClassInstance<CObjectFunction>
{
public:
	CObjectFunction() = default;
	~CObjectFunction() = default;

	///------GameUi------------------------------------------------
	// 返回指针, be careful, 刷新导致指针失效
	CGameUi* FindGameUi_For_StaticMap_By_MapKey(_In_ CONST std::wstring& wsKeyText);

	// 刷新静态Map
	VOID	RefreshStaticMapGameUi();

	//
	DWORD	GetGameUiValue_By_MapKey(_In_ CONST std::wstring& wsKeyText, _In_ std::function<DWORD(CGameUi&)> GetValuePtr);

	//
	std::wstring GetGameUiText_By_MapKey(_In_ CONST std::wstring& wsKeyText, _In_ std::function<std::wstring(CGameUi&)> GetTextPtr);

	//
	BOOL	IsShowGameUi_By_MapKey(_In_ CONST std::wstring& wsKeyText);

	//
	CONST std::wstring GetPersonAttributeText_By_Key(_In_ CONST std::wstring& wsKey) CONST;

	//
	DWORD		 GetPersonAttributeValue_By_Key(_In_ CONST std::wstring& wsKey) CONST;
private:
	virtual VOID AbstractMethod() override;
private:
	std::map<std::wstring, CGameUi> _MapGameUi;
	std::mutex						_MtxGameUi;
};


#endif // !__GITASKTAO_GAMEDLL_CORE_OBJECT_OBJECTFUNCTION_H__
