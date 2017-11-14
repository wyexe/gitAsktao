#include "stdafx.h"
#include "GameText.h"
#include <MyTools/Character.h>

CGameText::CGameText(_In_ CONST std::wstring& wsText)
{
	strText = MyTools::CCharacter::UnicodeToASCII(wsText);
}

CONST CHAR* CGameText::GetBuffer()
{
	ZeroMemory(szLongText, sizeof(szLongText));
	ZeroMemory(szText, sizeof(szText));
	if (strText.length() <= 0xF)
	{
		MyTools::CCharacter::strcpy_my(szText + 4, strText.c_str());
		*reinterpret_cast<DWORD*>(szText + 0x14) = strText.length();
		*reinterpret_cast<DWORD*>(szText + 0x18) = 0xF;
	}
	else
	{
		MyTools::CCharacter::strcpy_my(szLongText, strText.c_str());
		*reinterpret_cast<DWORD*>(szText + 0x04) = reinterpret_cast<DWORD>(szLongText);
		*reinterpret_cast<DWORD*>(szText + 0x14) = strText.length();
		*reinterpret_cast<DWORD*>(szText + 0x18) = 0x1F;
	}
	return szText;
}
