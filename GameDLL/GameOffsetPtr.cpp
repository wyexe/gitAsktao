#include "stdafx.h"
#include "GameOffsetPtr.h"
#include <MyTools/Character.h>
#include "GameUi.h"
#include "GameStruct.h"

std::function<DWORD(CGameUi&)> CGameOffsetPtr::GetHpPtr()
{
	return [](CGameUi& GameUi) { return ReadDWORD(GameUi.GetObj() + 人物HP偏移); };
}

std::function<DWORD(CGameUi&)> CGameOffsetPtr::GetMaxHpPtr()
{
	return [](CGameUi& GameUi) { return ReadDWORD(GameUi.GetObj() + 人物MAXHP偏移); };
}

std::function<DWORD(CGameUi&)> CGameOffsetPtr::GetValue()
{
	return [](CGameUi& GameUi) 
	{
		auto pszText = reinterpret_cast<CHAR*>(GameUi.GetObj() + UI文本偏移);
		return pszText == nullptr ? 0 : static_cast<DWORD>(atoi(pszText));
	};
}

std::function<std::wstring(CGameUi&)> CGameOffsetPtr::GetText()
{
	return [](CGameUi& GameUi)
	{
		auto pszText = reinterpret_cast<CHAR*>(GameUi.GetObj() + UI文本偏移);
		return MyTools::CCharacter::ASCIIToUnicode(std::string(pszText));
	};
}

std::function<std::wstring(CGameUi&)> CGameOffsetPtr::GetEditText()
{
	return [](CGameUi& GameUi)
	{
		auto pszText = reinterpret_cast<CHAR*>(ReadDWORD(GameUi.GetObj() + UIEDIT偏移));
		return MyTools::CCharacter::ASCIIToUnicode(std::string(pszText));
	};
}