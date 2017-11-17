#include "stdafx.h"
#include "BattleAction.h"
#include <MyTools/Log.h>
#include <MyTools/Character.h>
#include <MyTools/CLPublic.h>
#include "PersonAttribute.h"
#include "PetObject.h"
#include "PetExtend.h"
#include "ObjectFunction.h"
#include "BattleAttribute.h"

#define _SELF L"BattleAction.cpp"
CBattleAction::CBattleAction()
{
	_wsPersonName = _PersonAttribute.GetName();
	_emPersonFamily = _PersonAttribute.GetFamilyType();
}

BOOL CBattleAction::Fight(_In_ DWORD dwOption)
{
	CBattleAttribute BattleAttribute;
	LOG_C_D(L"开始战斗");
	while (g_IsRuning && _PersonAttribute.IsFighting())
	{
		CObjectFunction::GetInstance().RefreshStaticMapGameUi();
		if (BattleAttribute.IsExistFightMeMenu())
		{
			LOG_C_D(L"轮到我们行动了!");
			switch (_emPersonFamily)
			{
			case CPersonAttribute::em_Family::em_Family_UnKnow:
				LOG_MSG_CF(L"未知职业……");
				break;
			case CPersonAttribute::em_Family::em_Family_金:
				Fight_Classes_金();
				break;
			case CPersonAttribute::em_Family::em_Family_木:
				Fight_Classes_木();
				break;
			case CPersonAttribute::em_Family::em_Family_水:
				Fight_Classes_水();
				break;
			case CPersonAttribute::em_Family::em_Family_火:
				Fight_Classes_火();
				break;
			case CPersonAttribute::em_Family::em_Family_土:
				Fight_Classes_土();
				break;
			default:
				break;
			}

			Fight_Classes_Pet();
		}
		::Sleep(1000);
	}

	LOG_C_D(L"战斗结束");
	return TRUE;
}

VOID CBattleAction::RefreshData()
{
	CObjectFunction::GetInstance().GetVecMonster(_VecMonster);
	std::sort(_VecMonster.begin(), _VecMonster.end(), [](CONST CMonster& itm1, CONST CMonster& itm2) { return itm1.GetId() < itm2.GetId(); });
}

CONST CMonster* CBattleAction::FindPerson() CONST
{
	return MyTools::CLPublic::Vec_find_if_Const(_VecMonster, [this](CONST CMonster& itm)
	{
		return itm.GetName() == _wsPersonName;
	});
}

CONST CMonster* CBattleAction::FindPet() CONST
{
	return MyTools::CLPublic::Vec_find_if_Const(_VecMonster, [] (CONST CMonster& itm)
	{
		return itm.GetId() == CPetObject::GetJoinWarPetId();
	});
}

CONST CMonster* CBattleAction::FindTarget() CONST
{
	return MyTools::CLPublic::Vec_find_if_Const(_VecMonster, [](CONST CMonster& itm)
	{
		return itm.GetType() == CMonster::em_Type::em_Type_Monster;
	});
}

VOID CBattleAction::Fight_Classes_金() CONST
{
	auto pPerson = FindPerson();
	if (pPerson == nullptr)
	{
	//	LOG_C_D(L"Empty Person");
		return;
	}

	auto pTarget = FindTarget();
	if (pTarget == nullptr)
	{
		//LOG_C_D(L"pTarget = nullptr");
		return;
	}

	if (pPerson->GetPercentMp() <= 10)
	{
		//LOG_C_D(L"人物蓝不够了, 防御");
		pPerson->Defence();
		return;
	}

	pPerson->UseSkill(*pTarget, em_SkillId_金_金光乍现);
	::Sleep(1000);
}

VOID CBattleAction::Fight_Classes_木() CONST
{
	auto pPerson = FindPerson();
	if (pPerson == nullptr)
	{
		//	LOG_C_D(L"Empty Person");
		return;
	}

	auto pTarget = FindTarget();
	if (pTarget == nullptr)
	{
		//LOG_C_D(L"pTarget = nullptr");
		return;
	}

	if (pPerson->GetPercentMp() <= 10)
	{
		//LOG_C_D(L"人物蓝不够了, 防御");
		pPerson->Defence();
		return;
	}

	pPerson->UseSkill(*pTarget, em_SkillId_木_摘叶飞花);
	::Sleep(1000);
}

VOID CBattleAction::Fight_Classes_水() CONST
{
	auto pPerson = FindPerson();
	if (pPerson == nullptr)
	{
		//	LOG_C_D(L"Empty Person");
		return;
	}

	auto pTarget = FindTarget();
	if (pTarget == nullptr)
	{
		//LOG_C_D(L"pTarget = nullptr");
		return;
	}

	if (pPerson->GetPercentMp() <= 10)
	{
		//LOG_C_D(L"人物蓝不够了, 防御");
		pPerson->Defence();
		return;
	}

	pPerson->UseSkill(*pTarget, em_SkillId_水_滴水石穿);
	::Sleep(1000);
}

VOID CBattleAction::Fight_Classes_火() CONST
{

}

VOID CBattleAction::Fight_Classes_土() CONST
{

}

VOID CBattleAction::Fight_Classes_Pet() CONST
{
	auto pPet = FindPet();
	if (pPet == nullptr)
		return;

	if (pPet->GetPercentMp() <= 10)
	{
		LOG_C_D(L"BB蓝不够了, 防御");
		pPet->Defence();
		return;
	}
	
	auto pTarget = FindTarget();
	if (pTarget == nullptr)
	{
		LOG_C_D(L"pTarget = nullptr");
		return;
	}
	pPet->UseSkill(*pTarget, em_SkillId_金_金光乍现);
	::Sleep(1000);
}
