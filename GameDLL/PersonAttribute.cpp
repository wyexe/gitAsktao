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
	return CObjectFunction::GetInstance().GetPersonAttributeValue_By_Key(L"life");
}

DWORD CPersonAttribute::GetMaxHP() CONST
{
	return CObjectFunction::GetInstance().GetPersonAttributeValue_By_Key(L"life");
}

DWORD CPersonAttribute::GetMp() CONST
{
	return CObjectFunction::GetInstance().GetPersonAttributeValue_By_Key(L"mana");
}

DWORD CPersonAttribute::GetMaxMp() CONST
{
	return CObjectFunction::GetInstance().GetGameUiValue_By_MapKey(L"PanMeDlg.Mana", CGameOffsetPtr().GetMaxHpPtr());
}

DWORD CPersonAttribute::GetExp() CONST
{
	return CObjectFunction::GetInstance().GetPersonAttributeValue_By_Key(L"exp");
}

DWORD CPersonAttribute::GetMaxExp() CONST
{
	return CObjectFunction::GetInstance().GetPersonAttributeValue_By_Key(L"exp_to_next_level");
}

DWORD CPersonAttribute::GetTotalScore() CONST
{
	return CObjectFunction::GetInstance().GetPersonAttributeValue_By_Key(L"total_score");
}

std::wstring CPersonAttribute::GetName() CONST
{
	return CObjectFunction::GetInstance().GetPersonAttributeText_By_Key(L"name");
}

DWORD CPersonAttribute::GetLevel() CONST
{
	return CObjectFunction::GetInstance().GetPersonAttributeValue_By_Key(L"level");
}

DWORD CPersonAttribute::GetReputation() CONST
{
	return CObjectFunction::GetInstance().GetPersonAttributeValue_By_Key(L"reputation");
}

std::wstring CPersonAttribute::GetPartyName() CONST
{
	return CObjectFunction::GetInstance().GetPersonAttributeText_By_Key(L"party");
}

DWORD CPersonAttribute::GetPartyContrib() CONST
{
	return CObjectFunction::GetInstance().GetPersonAttributeValue_By_Key(L"party/contrib");
}

DWORD CPersonAttribute::GetDaoXing() CONST
{
	return CObjectFunction::GetInstance().GetPersonAttributeValue_By_Key(L"tao") / 360;
}

DWORD CPersonAttribute::GetPot() CONST
{
	return CObjectFunction::GetInstance().GetPersonAttributeValue_By_Key(L"pot");
}

DWORD CPersonAttribute::GetAttributePoint() CONST
{
	return CObjectFunction::GetInstance().GetPersonAttributeValue_By_Key(L"attrib_point");
}

DWORD CPersonAttribute::GetPolarPoint() CONST
{
	return CObjectFunction::GetInstance().GetPersonAttributeValue_By_Key(L"polar_point");
}

CPersonAttribute::CashContent CPersonAttribute::GetMoney() CONST
{
	CashContent Content = 
	{ 
		CObjectFunction::GetInstance().GetPersonAttributeValue_By_Key(L"cash"), 
		CObjectFunction::GetInstance().GetPersonAttributeValue_By_Key(L"voucher") 
	};
	return Content;
}

Point CPersonAttribute::GetPoint() CONST
{
	return Point(
		CObjectFunction::GetInstance().GetPersonAttributeValue_By_Key(L"x"), 
		CObjectFunction::GetInstance().GetPersonAttributeValue_By_Key(L"y"));
}

std::wstring CPersonAttribute::GetMapName() CONST
{
	// MainThread Get MapName
	return CObjectFunction::GetInstance().GetPersonAttributeText_By_Key(L"map_name");
}

BOOL CPersonAttribute::IsFighting() CONST
{
	return ReadBYTE(ReadDWORD(是否战斗中基址) + 0xC) == 0x9;
}

std::wstring CPersonAttribute::GetFamily() CONST
{
	return CObjectFunction::GetInstance().GetPersonAttributeText_By_Key(L"family");
}

std::wstring CPersonAttribute::GetFamilyMaster() CONST
{
	return CObjectFunction::GetInstance().GetPersonAttributeText_By_Key(L"master");
}
