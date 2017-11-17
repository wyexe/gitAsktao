#ifndef __GITASKTAO_GAMEDLL_CORE_OBJECT_NPC_NPCOBJECT_H__
#define __GITASKTAO_GAMEDLL_CORE_OBJECT_NPC_NPCOBJECT_H__

#include "BaseObject.h"

class CNpcObject : public CBaseObject
{
public:
	enum class em_Type
	{
		UnKnow,
		Npc,
		Player
	};
public:
	CNpcObject(_In_ DWORD dwNodeBase);
	~CNpcObject() = default;

	//
	VOID SetName();

	//
	DWORD GetId() CONST;

	//
	DWORD GetObj() CONST;

	// 
	em_Type GetType() CONST;

	//
	Point GetPoint() CONST;

	//
	float GetDis() CONST;

	//
	VOID OpenNpc() CONST;
private:
	DWORD GetAttributeTreeHead() CONST;
};



#endif // !__GITASKTAO_GAMEDLL_CORE_OBJECT_NPC_NPCOBJECT_H__
