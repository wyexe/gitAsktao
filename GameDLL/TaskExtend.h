#ifndef __GITASKTAO_GAMEDLL_CORE_OBJECT_TASK_TASKEXTEND_H__
#define __GITASKTAO_GAMEDLL_CORE_OBJECT_TASK_TASKEXTEND_H__

#include "TaskObject.h"

class CTaskExtend
{
public:
	CTaskExtend() = default;
	~CTaskExtend() = default;

	BOOL FindTask_By_Name(_In_ CONST std::wstring& wsTaskName, _Out_ CTaskObject& TaskObject) CONST;

	BOOL ExistTask(_In_ CONST std::wstring& wsTaskName) CONST;
private:

};



#endif // !__GITASKTAO_GAMEDLL_CORE_OBJECT_TASK_TASKEXTEND_H__
