#include "stdafx.h"
#include "TaskExtend.h"
#include "ObjectFunction.h"

BOOL CTaskExtend::FindTask_By_Name(_In_ CONST std::wstring& wsTaskName, _Out_ CTaskObject& TaskObject) CONST
{
	std::vector<CTaskObject> VecTask;
	CObjectFunction::GetInstance().GetVecTask(VecTask, [wsTaskName](CONST CTaskObject& itm) {return itm.GetName() == wsTaskName; });

	if (VecTask.size() == 0)
		return FALSE;

	TaskObject = std::move(VecTask.at(0));
	return TRUE;
}

BOOL CTaskExtend::ExistTask(_In_ CONST std::wstring& wsTaskName) CONST
{
	CTaskObject TaskObject(0);
	return FindTask_By_Name(wsTaskName, TaskObject);
}
