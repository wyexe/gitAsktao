#include "stdafx.h"
#include "StatusCheck.h"
#include <MyTools/Log.h>
#include "CodeTransfer.h"
#include "PetExtend.h"
#include "PetObject.h"
#include "GameCALL.h"
#include "TaskExtend.h"
#include "BagItemAction.h"
#include "BagItemExtend.h"
#include "ObjectFunction.h"

#define _SELF L"StatusCheck.cpp"
VOID CStatusCheck::CheckHealth() CONST
{
	if (_PersonAttribute.IsFighting())
		return;


	if (_PersonAttribute.GetPercentHp() <= 70)
	{
		LOG_C_D(L"ÈËÎï²¹Ñª");
		CCodeTransfer::PushPtrToMainThread([] { CGameCALL::PersonAddHp(); });
	}
	if (_PersonAttribute.GetPercentMp() <= 70)
	{
		LOG_C_D(L"ÈËÎï²¹À¶");
		CCodeTransfer::PushPtrToMainThread([] { CGameCALL::PersonAddMp(); });
	}

	CPetObject Pet(0);
	if (CPetExtend().FindJoinWarPet(Pet))
	{
		if (Pet.GetPercentHp() <= 70)
		{
			LOG_C_D(L"³èÎï²¹Ñª");
			CCodeTransfer::PushPtrToMainThread([Pet] { CGameCALL::PetAddHp(Pet.GetObj()); });
		}
		if (Pet.GetPercentMp() <= 70)
		{
			LOG_C_D(L"³èÎï²¹À¶");
			CCodeTransfer::PushPtrToMainThread([Pet] { CGameCALL::PetAddMp(Pet.GetObj()); });
		}
		if (Pet.GetLoyalty() < 80)
		{
			LOG_C_E(L"³èÎïÖÒ³Ï¶È²»¹»ÁË¡­¡­");
		}
	}
}

VOID CStatusCheck::CheckExorcism() CONST
{
	if (!CTaskExtend().ExistTask(L"ÇýÄ§Ïã") && !CTaskExtend().ExistTask(L"Ç¿Á¦ÇýÄ§Ïã"))
	{
		CBagItemExtend BagItemExtend;
		if (BagItemExtend.GetCount_By_ItemName(L"Ç¿Á¦ÇýÄ§Ïã") != 0)
		{
			CBagItemAction().UseItem_By_ItemName_In_NoFight(L"Ç¿Á¦ÇýÄ§Ïã");
			::Sleep(1000);
		}
		else if (BagItemExtend.GetCount_By_ItemName(L"ÇýÄ§Ïã") != 0)
		{
			CBagItemAction().UseItem_By_ItemName_In_NoFight(L"ÇýÄ§Ïã");
			::Sleep(1000);
		}
	}
}

VOID CStatusCheck::CheckDaoDaoDao() CONST
{
	auto pTaoTaoTaoDlg = CObjectFunction::GetInstance().FindGameUi_For_StaticMap_By_MapKey(L"TaoTaoTaoDlg.StartBtn");
	if (pTaoTaoTaoDlg != nullptr && pTaoTaoTaoDlg->IsShow())
	{
		LOG_C_D(L"µÀµÀµÀµÄÒ¡½±");
		pTaoTaoTaoDlg->Click();
		::Sleep(8 * 1000);
	}
}
