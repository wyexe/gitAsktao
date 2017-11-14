#ifndef __GITASKTAO_GAMEDLL_CORE_TEXT_GAMETEXT_GAMETEXT_H__
#define __GITASKTAO_GAMEDLL_CORE_TEXT_GAMETEXT_GAMETEXT_H__

#include <MyTools/ToolsPublic.h>

class CGameText
{
public:
	CGameText(_In_ CONST std::wstring& wsText);
	~CGameText() = default;

	CONST CHAR* GetBuffer();
private:
	CHAR szText[128];
	CHAR szLongText[32];
	std::string strText;
};

#endif // !__GITASKTAO_GAMEDLL_CORE_TEXT_GAMETEXT_GAMETEXT_H__
