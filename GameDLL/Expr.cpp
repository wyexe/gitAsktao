#include "stdafx.h"
#include "Expr.h"
#include <MyTools/Log.h>
#include <MyTools/Character.h>
#include <MyTools/CLEchoException.h>
#include "GameStruct.h"
#include "Monster.h"
#include "ObjectFunction.h"
#include "BagItemAction.h"
#include "GameCALL.h"
#include "PersonAttribute.h"
#include "AskScanBase.h"
#include "GameUi.h"
#include "CodeTransfer.h"
#include "GameText.h"
#include "PetObject.h"
#include "PetExtend.h"

#define _SELF L"Expr.cpp"
CExpr::CExpr()
{

}

CExpr::~CExpr()
{
	Release();
}

VOID CExpr::Release()
{

}

std::vector<MyTools::ExpressionFunPtr>& CExpr::GetVec()
{
	static std::vector<MyTools::ExpressionFunPtr> Vec =
	{
		{ std::bind(&CExpr::Help,this, std::placeholders::_1),L"Help" },
		{ std::bind(&CExpr::PrintUi,this, std::placeholders::_1),L"PrintUi" },
		{ std::bind(&CExpr::Test,this, std::placeholders::_1),L"Test" },
		{ std::bind(&CExpr::WatchNewUi,this, std::placeholders::_1),L"WatchNewUi" },
		{ std::bind(&CExpr::PrintMonster,this, std::placeholders::_1),L"PrintMonster" },
		{ std::bind(&CExpr::PrintBag,this, std::placeholders::_1),L"PrintBag" },
		{ std::bind(&CExpr::ScanBase,this, std::placeholders::_1),L"ScanBase" },
	};

	return Vec;
}

VOID CExpr::Help(CONST std::vector<std::wstring>&)
{
	auto& Vec = GetVec();
	for (CONST auto& itm : Vec)
		LOG_C_D(L"MethodName=%s", itm.wsFunName.c_str());
}

VOID TraverseUi(_In_ DWORD dwNode, _Out_ std::vector<DWORD>& Vec)
{
	DWORD dwLinkTableHead = ReadDWORD(dwNode + 0x1E4);
	for (DWORD dwObjectAddr = ReadDWORD(dwLinkTableHead);; dwObjectAddr = ReadDWORD(dwObjectAddr))
	{
		if (dwObjectAddr == dwLinkTableHead)
			break;

		if (ReadDWORD(dwObjectAddr + 0x8) == 0)
			break;

		Vec.push_back(dwObjectAddr);
	}
}

VOID CExpr::PrintUi(CONST std::vector<std::wstring>&)
{
	std::vector<DWORD> Vec;
	DWORD dwRoot = ReadDWORD(UI遍历基址);
	TraverseUi(dwRoot, Vec);

	LOG_C_D(L"Vec.size=%d", Vec.size());
	for (auto& itm : Vec)
	{
		DWORD dwObject = ReadDWORD(itm + 0x8);
		CHAR* pszText = reinterpret_cast<CHAR*>(dwObject + 0x94);
		std::wstring wsUiName = MyTools::CCharacter::ASCIIToUnicode(pszText);
		LOG_C_D(L"itm.Show=%d, Obj=%X,Name=%s", ReadBYTE(dwObject + 0x40), dwObject, wsUiName.c_str());


		std::vector<DWORD> VecObject;
		TraverseUi(dwObject, VecObject);
		for (auto& ChildUiObject : VecObject)
		{
			std::wstring wsChildUiName = MyTools::CCharacter::ASCIIToUnicode(reinterpret_cast<CHAR*>(ReadDWORD(ChildUiObject + 8) + 0x94));
			LOG_C_D(L"%s->[Base=%X,Obj=%X, Name=%s]", wsUiName.c_str(), ChildUiObject, ReadDWORD(ChildUiObject + 8), wsChildUiName.c_str());
		}
	}
}

VOID CExpr::WatchNewUi(CONST std::vector<std::wstring>& VecParam)
{
	static std::map<std::wstring, CGameUi> VecGameUi;
	if (VecParam.size() == 0)
	{
		LOG_C_D(L"WatchNewUi(0|1)");
		return;
	}

	if (VecParam.at(0) == L"0")
	{
		VecGameUi.clear();
		CObjectFunction::GetInstance().GetGameUiList(VecGameUi);
		LOG_C_D(L"CurrentUi.count=%d", VecGameUi.size());
	}
	else
	{
		std::map<std::wstring, CGameUi> tmpVecGameUi;
		CObjectFunction::GetInstance().GetGameUiList(tmpVecGameUi);

		// 判断新增和消逝的UI
		LOG_C_D(L"----------------新增的UI-------------------------");
		for (auto& NewGameUi : tmpVecGameUi)
		{
			auto itr = VecGameUi.find(NewGameUi.first);
			if (itr == VecGameUi.end())
			{
				LOG_C_D(L"NewUi.Name=%s, Obj=%X", NewGameUi.second.GetName().c_str(), NewGameUi.second.GetObj());
			}
		}

		LOG_C_D(L"----------------消逝的UI-------------------------");
		for (auto& OldGameUi : VecGameUi)
		{
			auto itr = tmpVecGameUi.find(OldGameUi.first);
			if (itr == tmpVecGameUi.end())
			{
				LOG_C_D(L"DesktoryUi.Name=%s, Obj=%X", OldGameUi.second.GetName().c_str(), OldGameUi.second.GetObj());
			}
		}
		VecGameUi.clear();
	}
}

DWORD GetECX()
{
	CObjectFunction::GetInstance().RefreshStaticMapGameUi();
	auto pGameUi = CObjectFunction::GetInstance().FindGameUi_For_StaticMap_By_MapKey(L"TaskDlg.CurrentDetails");
	if (pGameUi == nullptr)
	{
		pGameUi = CObjectFunction::GetInstance().FindGameUi_For_StaticMap_By_MapKey(L"TaskTraceDlg.TaskDesc0");
		if (pGameUi == nullptr)
		{
			auto pTaskDlg = CObjectFunction::GetInstance().FindGameUi_For_StaticMap_By_MapKey(L"PanToolDlg.QstBtn");
			if (pTaskDlg == nullptr)
			{
				LOG_C_E(L"pTaskDlg = nullptr");
				return 0;
			}
			pTaskDlg->Click();
			::Sleep(2 * 1000);

			CObjectFunction::GetInstance().RefreshStaticMapGameUi();
			/*auto pCloseBtn = CObjectFunction::GetInstance().FindGameUi_For_StaticMap_By_MapKey(L"TaskDlg.CloseButton");
			if (pCloseBtn != nullptr)
			{
				pCloseBtn->Click();
				::Sleep(2000);
			}*/


			pGameUi = CObjectFunction::GetInstance().FindGameUi_For_StaticMap_By_MapKey(L"TaskDlg.CurrentDetails");
			if (pGameUi == nullptr)
			{
				pGameUi = CObjectFunction::GetInstance().FindGameUi_For_StaticMap_By_MapKey(L"TaskTraceDlg.TaskDesc0");
				if (pGameUi == nullptr)
				{
					LOG_C_E(L"pGameUi = nullptr");
					return 0;
				}
			}
		}
	}

	LOG_C_D(L"pGameUi=%X,Obj=%X,Name=%s", pGameUi, pGameUi->GetObj(), pGameUi->GetName().c_str());
	return pGameUi->GetObj();
}


VOID CExpr::Test(CONST std::vector<std::wstring>&)
{
	/*std::vector<CMonster> VecMonster;
	CObjectFunction::GetInstance().GetVecMonster(VecMonster);

	CMonster Person;
	for (auto& itm : VecMonster)
	{
		if (itm.GetName() == CPersonAttribute().GetName())
		{
			Person = itm;
			break;
		}
	}


	CPetObject Pet(0);
	if (!CPetExtend().FindJoinWarPet(Pet))
		return;

	CMonster PetMonster;
	for (auto& itm : VecMonster)
	{
		if (itm.GetName() == Pet.GetName())
		{
			PetMonster = itm;
			break;
		}
	}

	for (auto& itm : VecMonster)
	{
		if(itm.GetType() != CMonster::em_Type::em_Type_Monster)
			continue;

		LOG_C_D(L"用金光乍现");
		Person.UseSkill(itm, em_SkillId_金_金虹贯日);
		::Sleep(1000);
		PetMonster.Defence();
		break;
	}
	*/
	/*std::vector<CPetObject> VecPet;
	CObjectFunction::GetInstance().GetVecPet(VecPet, nullptr);
	for (auto& itm : VecPet)
	{
		CObjectFunction::GetInstance().GetPetText_By_Key(itm, L"*");
	}*/
}

VOID CExpr::PrintMonster(CONST std::vector<std::wstring>&)
{
	std::vector<CMonster> VecMonster;
	CObjectFunction::GetInstance().GetVecMonster(VecMonster);
	for (auto& itm : VecMonster)
	{
		LOG_C_D(L"NodeBase=%X, Index=%d, ID=%X, Name=%s", itm.GetNodeBase(), itm.GetIndex(), itm.GetId(), itm.GetName().c_str());
	}
}

VOID CExpr::PrintBag(CONST std::vector<std::wstring>&)
{
	std::vector<CBagItem> Vec;
	CObjectFunction::GetInstance().GetVecBagItem(Vec, nullptr);
	LOG_C_D(L"Bag.size=%d", Vec.size());

	std::wstring wsValue;
	for (auto& itm : Vec)
	{
		LOG_C_D(L"NodeBase=%X, Name=%s, Type=%X, Count=%d, ID=%X", itm.GetNodeBase(), itm.GetName().c_str(), itm.GetItemType(), itm.GetCount(), itm.GetId());
		//CObjectFunction::GetInstance().FindItemAttribute_By_Key(itm, L"*", wsValue);
	}
}

VOID CExpr::ScanBase(CONST std::vector<std::wstring>&)
{
	CAskScanBase().Start();
}
