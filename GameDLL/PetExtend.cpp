#include "stdafx.h"
#include "PetExtend.h"
#include <MyTools/Log.h>
#include "ObjectFunction.h"

#define _SELF L"PetExtend.cpp"
BOOL CPetExtend::FindJoinWarPet(_Out_ CPetObject& Pet) CONST
{
	DWORD dwPetId = CPetObject::GetJoinWarPetId();
	if (dwPetId == NULL)
		return FALSE;


	std::vector<CPetObject> VecPet;
	CObjectFunction::GetInstance().GetVecPet(VecPet, [dwPetId](CONST CPetObject& PetObject) { return PetObject.GetId() == dwPetId; });
	if (VecPet.size() == 0)
	{
		LOG_MSG_CF(L"遍历不到出战的宠物ID[%X]", dwPetId);
		return FALSE;
	}


	Pet = std::move(VecPet.at(0));
	return TRUE;
}
