#include "stdafx.h"
#include "TaskObject.h"
#include <MyTools/Character.h>
#include "ObjectFunction.h"

CTaskObject::CTaskObject(_In_ DWORD dwNodeBase)
{
	_dwNodeBase = dwNodeBase;
	if (dwNodeBase != NULL)
		SetName();
}

VOID CTaskObject::SetName()
{
	_wsName = CObjectFunction::GetInstance().GetAttributeText_By_Key(GetAttributeTreeHead(), L"draw_name", TRUE);
	if (_wsName.empty())
	{
		_wsName = CObjectFunction::GetInstance().GetAttributeText_By_Key(GetAttributeTreeHead(), L"raw_type", TRUE);
	}
	if (_wsName.empty())
	{
		_wsName = CObjectFunction::GetInstance().GetAttributeText_By_Key(GetAttributeTreeHead(), L"task_type");
	}
}

CONST std::wstring CTaskObject::GetTaskClasses() CONST
{
	return CObjectFunction::GetInstance().GetAttributeText_By_Key(GetAttributeTreeHead(), L"task_class");
}

CONST std::wstring CTaskObject::GetTaskPrompt() CONST
{
	return CObjectFunction::GetInstance().GetAttributeText_By_Key(GetAttributeTreeHead(), L"task_prompt");
}

DWORD CTaskObject::GetAttributeTreeHead() CONST
{
	return ReadDWORD(ReadDWORD(GetNodeBase() + 0x4 + 0x4) + 0x4);
}
