#include "stdafx.h"
#include "PetAttribute.h"
#include <MyTools/Character.h>
#include "ObjectFunction.h"
#include "GameUi.h"
#include "GameOffsetPtr.h"

DWORD CPetAttribute::GetHp() CONST
{
	return CObjectFunction::GetInstance().GetGameUiValue_By_MapKey(L"PanPetDlg.Life", CGameOffsetPtr().GetHpPtr());
}

DWORD CPetAttribute::GetMaxHP() CONST
{
	return CObjectFunction::GetInstance().GetGameUiValue_By_MapKey(L"PanPetDlg.Life", CGameOffsetPtr().GetMaxHpPtr());
}

DWORD CPetAttribute::GetMp() CONST
{
	return CObjectFunction::GetInstance().GetGameUiValue_By_MapKey(L"PanPetDlg.Mana", CGameOffsetPtr().GetHpPtr());
}

DWORD CPetAttribute::GetMaxMp() CONST
{
	return CObjectFunction::GetInstance().GetGameUiValue_By_MapKey(L"PanPetDlg.Mana", CGameOffsetPtr().GetMaxHpPtr());
}

DWORD CPetAttribute::GetExp() CONST
{
	return CObjectFunction::GetInstance().GetGameUiValue_By_MapKey(L"PanPetDlg.Exp", CGameOffsetPtr().GetHpPtr());
}

DWORD CPetAttribute::GetMaxExp() CONST
{
	return CObjectFunction::GetInstance().GetGameUiValue_By_MapKey(L"PanPetDlg.Exp", CGameOffsetPtr().GetMaxHpPtr());
}

DWORD CPetAttribute::GetLevel() CONST
{
	return CObjectFunction::GetInstance().GetGameUiValue_By_MapKey(L"PetDlg.LevelStatic", CGameOffsetPtr().GetValue());
}

std::wstring CPetAttribute::GetName() CONST
{
	return CObjectFunction::GetInstance().GetGameUiText_By_MapKey(L"PetDlg.NameEdit", CGameOffsetPtr().GetEditText());
}

DWORD CPetAttribute::GetAttributePoint() CONST
{
	return CObjectFunction::GetInstance().GetGameUiValue_By_MapKey(L"PetDlg.AttribPointStatic", CGameOffsetPtr().GetValue());
}

DWORD CPetAttribute::GetLoyal() CONST
{
	return CObjectFunction::GetInstance().GetGameUiValue_By_MapKey(L"PetDlg.LoyalStatic", CGameOffsetPtr().GetValue());
}
