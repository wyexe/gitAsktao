#ifndef __GITASKTAO_GAMEDLL_CORE_OBJECT_PET_PETEXTEND_H__
#define __GITASKTAO_GAMEDLL_CORE_OBJECT_PET_PETEXTEND_H__

#include "PetObject.h"
class CPetExtend
{
public:
	CPetExtend() = default;
	~CPetExtend() = default;

	BOOL FindJoinWarPet(_Out_ CPetObject& Pet) CONST;
private:

};



#endif // !__GITASKTAO_GAMEDLL_CORE_OBJECT_PET_PETEXTEND_H__
