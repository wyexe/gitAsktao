#ifndef __GITASKTAO_GAMEDLL_CORE_COMMON_GAMEOFFSETPTR_H__
#define __GITASKTAO_GAMEDLL_CORE_COMMON_GAMEOFFSETPTR_H__

#include <functional>

class CGameUi;
class CGameOffsetPtr
{
public:
	CGameOffsetPtr() = default;
	~CGameOffsetPtr() = default;

	std::function<DWORD(CGameUi&)> GetHpPtr();
	std::function<DWORD(CGameUi&)> GetMaxHpPtr();
	std::function<DWORD(CGameUi&)> GetValue();
	std::function<std::wstring(CGameUi&)> GetText();
	std::function<std::wstring(CGameUi&)> GetEditText();
private:

};



#endif // !__GITASKTAO_GAMEDLL_CORE_COMMON_GAMEOFFSETPTR_H__
