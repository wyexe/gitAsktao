#ifndef __GITASKTAO_GAMEDLL_CORE_OBJECT_TASK_TASKOBJECT_H__
#define __GITASKTAO_GAMEDLL_CORE_OBJECT_TASK_TASKOBJECT_H__

#include "BaseObject.h"

class CTaskObject : public CBaseObject
{
public:
	CTaskObject(_In_ DWORD dwNodeBase);
	~CTaskObject() = default;

	VOID SetName();

	CONST std::wstring GetTaskClasses() CONST;

	CONST std::wstring GetTaskPrompt() CONST;
private:
	DWORD GetAttributeTreeHead() CONST;
};


#endif // !__GITASKTAO_GAMEDLL_CORE_OBJECT_TASK_TASKOBJECT_H__
