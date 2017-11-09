#include "stdafx.h"
#include "BattleAttribute.h"
#include "GameStruct.h"
#include "ObjectFunction.h"
#include "GameUi.h"
#include "GameOffsetPtr.h"

BOOL CBattleAttribute::IsExistFightMeMenu() CONST
{
	return CObjectFunction::GetInstance().IsShowGameUi_By_MapKey(L"FightMeMenuDlg");
}

BOOL CBattleAttribute::IsExistFightPetMenu() CONST
{
	return CObjectFunction::GetInstance().IsShowGameUi_By_MapKey(L"FightPetMenuDlg");
}
