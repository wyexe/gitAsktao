#ifndef __GITASKTAO_GAMEDLL_CORE_SCRIPT_KILLMOBSTER_KILLMOBSTER_H__
#define __GITASKTAO_GAMEDLL_CORE_SCRIPT_KILLMOBSTER_KILLMOBSTER_H__

#include "TeamAttribute.h"
#include "PersonAttribute.h"
#include "BattleAction.h"
#include "TaskExtend.h"
#include "StatusCheck.h"

class CKillMobsterTask
{
private:
	struct MyStruct
	{

	};
public:
	CKillMobsterTask() = default;
	~CKillMobsterTask() = default;

	BOOL Run();

private:
	BOOL ExistTask() CONST;
private:
	CTeamAttribute		_TeamAttribute;
	CPersonAttribute	_PersonAttribute;
	CBattleAction		_BattleAction;
	CTaskExtend			_TaskExtend;
	CStatusCheck		_StatusCheck;
};



#endif // !__GITASKTAO_GAMEDLL_CORE_SCRIPT_KILLMOBSTER_KILLMOBSTER_H__
