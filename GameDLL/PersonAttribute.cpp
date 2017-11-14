#include "stdafx.h"
#include "PersonAttribute.h"
#include <MyTools/Character.h>
#include <MyTools/Log.h>
#include "ObjectFunction.h"
#include "GameUi.h"
#include "GameOffsetPtr.h"

#define _SELF L"PersonAttribute.cpp"
DWORD CPersonAttribute::GetHp() CONST
{
	return CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributePoint(), L"life");
}

DWORD CPersonAttribute::GetMaxHP() CONST
{
	return CObjectFunction::GetInstance().GetGameUiValue_By_MapKey(L"PanMeDlg.Life", CGameOffsetPtr().GetMaxHpPtr());
}

DWORD CPersonAttribute::GetMp() CONST
{
	return CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributePoint(),L"mana");
}

DWORD CPersonAttribute::GetMaxMp() CONST
{
	return CObjectFunction::GetInstance().GetGameUiValue_By_MapKey(L"PanMeDlg.Mana", CGameOffsetPtr().GetMaxHpPtr());
}

DWORD CPersonAttribute::GetExp() CONST
{
	return CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributePoint(),L"exp");
}

DWORD CPersonAttribute::GetMaxExp() CONST
{
	return CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributePoint(),L"exp_to_next_level");
}

DWORD CPersonAttribute::GetTotalScore() CONST
{
	return CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributePoint(), L"total_score");
}

std::wstring CPersonAttribute::GetName() CONST
{
	return CObjectFunction::GetInstance().GetAttributeText_By_Key(GetAttributePoint(), L"name");
}

DWORD CPersonAttribute::GetLevel() CONST
{
	return CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributePoint(),L"level");
}

DWORD CPersonAttribute::GetReputation() CONST
{
	return CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributePoint(),L"reputation");
}

std::wstring CPersonAttribute::GetPartyName() CONST
{
	return CObjectFunction::GetInstance().GetAttributeText_By_Key(GetAttributePoint(), L"party");
}

DWORD CPersonAttribute::GetPartyContrib() CONST
{
	return CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributePoint(),L"party/contrib");
}

DWORD CPersonAttribute::GetDaoXing() CONST
{
	return CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributePoint(),L"tao") / 360;
}

DWORD CPersonAttribute::GetPot() CONST
{
	return CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributePoint(),L"pot");
}

DWORD CPersonAttribute::GetAttributePoint() CONST
{
	return CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributePoint(),L"attrib_point");
}

DWORD CPersonAttribute::GetPolarPoint() CONST
{
	return CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributePoint(),L"polar_point");
}

CPersonAttribute::CashContent CPersonAttribute::GetMoney() CONST
{
	CashContent Content =
	{
		CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributePoint(),L"cash"),
		CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributePoint(),L"voucher")
	};
	return Content;
}

Point CPersonAttribute::GetPoint() CONST
{
	return Point(
		CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributePoint(),L"x"),
		CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributePoint(),L"y"));
}

std::wstring CPersonAttribute::GetMapName() CONST
{
	// MainThread Get MapName
	return CObjectFunction::GetInstance().GetAttributeText_By_Key(GetAttributePoint(), L"map_name");
}

std::wstring CPersonAttribute::GetCurrentLine()
{
	return MyTools::CCharacter::ASCIIToUnicode(std::string(reinterpret_cast<CONST CHAR*>(线路基址 + 0x4)));
}

BOOL CPersonAttribute::IsFighting() CONST
{
	return ReadBYTE(ReadDWORD(是否战斗中基址) + 0xC) == 0x9;
}

std::wstring CPersonAttribute::GetFamily() CONST
{
	return CObjectFunction::GetInstance().GetAttributeText_By_Key(GetAttributePoint(), L"family");
}

std::wstring CPersonAttribute::GetFamilyMaster() CONST
{
	return CObjectFunction::GetInstance().GetAttributeText_By_Key(GetAttributePoint(), L"master");
}

DWORD CPersonAttribute::GetAttributeTreeHead() CONST
{
	return ReadDWORD(ReadDWORD(ReadDWORD(人物属性基址) + 人物属性偏移 + 0x4 + 0x4) + 0x4);
}
