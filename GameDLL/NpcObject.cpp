#include "stdafx.h"
#include "NpcObject.h"
#include <MyTools/Character.h>
#include <MyTools/CLEchoException.h>
#include <MyTools/CLPublic.h>
#include <MyTools/Log.h>
#include "ObjectFunction.h"
#include "PersonAttribute.h"
#include "CodeTransfer.h"
#include "GameCALL.h"

#define _SELF L"NpcObject.cpp"
CNpcObject::CNpcObject(_In_ DWORD dwNodeBase)
{
	_dwNodeBase = dwNodeBase;
	if (_dwNodeBase != NULL)
	{
		SetName();
	}
}

VOID CNpcObject::SetName()
{
	DWORD dwNamePtr = NULL;
	MyTools::CLEchoException::GetInstance().InvokeAction(__FUNCTIONW__, [this, &dwNamePtr]
	{
		DWORD dwObj = GetObj();
		DWORD dwValue = 0;
		__asm
		{
			PUSHAD;
			MOV EAX, dwObj;
			MOV EDX, DWORD PTR DS : [EAX];
			MOV ECX, EAX;
			MOV EAX, DWORD PTR DS : [EDX + NPCÃû×ÖÐéº¯ÊýÆ«ÒÆ];
			CALL EAX;
			MOV dwValue, EAX;
			POPAD;
		}
		dwNamePtr = dwValue;
	});
	if (dwNamePtr != NULL)
	{
		_wsName = MyTools::CCharacter::ASCIIToUnicode(reinterpret_cast<CONST CHAR*>(dwNamePtr));
	}
}

DWORD CNpcObject::GetId() CONST
{
	DWORD dwId = NULL;
	MyTools::CLEchoException::GetInstance().InvokeAction(__FUNCTIONW__, [this, &dwId]
	{
		DWORD dwObj = GetObj();
		DWORD dwValue = 0;
		__asm
		{
			PUSHAD;
			MOV EAX, dwObj;
			MOV EDX, DWORD PTR DS : [EAX];
			MOV ECX, EAX;
			MOV EAX, DWORD PTR DS : [EDX + NPCIDÐéº¯ÊýÆ«ÒÆ];
			CALL EAX;
			MOV dwValue, EAX;
			POPAD;
		}
		dwId = dwValue;
	});

	return dwId;
}

DWORD CNpcObject::GetObj() CONST
{
	return ReadDWORD(GetNodeBase() + 0x14);
}

CNpcObject::em_Type CNpcObject::GetType() CONST
{
	DWORD dwType0 = ReadDWORD(GetObj() + 0x28);
	DWORD dwType1 = ReadDWORD(GetObj() + 0x2C);
	DWORD dwType2 = ReadDWORD(GetObj() + 0x38);
	DWORD dwType3 = ReadDWORD(GetObj() + 0xA4);

	if (dwType0 == 0 && dwType1 == 0 && dwType2 == 0 && dwType3 == 1)
		return em_Type::Npc;
	else if (dwType0 == 1 && dwType1 == 1 && dwType2 == 1 && dwType3 == 0)
		return em_Type::Player;

	return em_Type::UnKnow;
}

Point CNpcObject::GetPoint() CONST
{
	return Point
	(
		CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributeTreeHead(), L"x"),
		CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributeTreeHead(), L"y")
	);
}

float CNpcObject::GetDis() CONST
{
	return MyTools::CLPublic::GetDisBy2D(CPersonAttribute().GetPoint(), GetPoint());
}

VOID CNpcObject::OpenNpc() CONST
{
	CCodeTransfer::PushPtrToMainThread([this] { CGameCALL::OpenNpc(this->GetId()); });
}

DWORD CNpcObject::GetAttributeTreeHead() CONST
{
	return ReadDWORD(ReadDWORD(GetObj() + ÈËÎïÊôÐÔÆ«ÒÆ + 0x4 + 0x4) + 0x4);
}
