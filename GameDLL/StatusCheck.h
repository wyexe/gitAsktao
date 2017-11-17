#ifndef __GITASKTAO_GAMEDLL_CORE_FEATURE_CHECK_STATUSCHECK_H__
#define __GITASKTAO_GAMEDLL_CORE_FEATURE_CHECK_STATUSCHECK_H__

#include "PersonAttribute.h"

class CStatusCheck
{
public:
	CStatusCheck() = default;
	~CStatusCheck() = default;

	// 检查血量是否健康
	VOID CheckHealth() CONST;

	// 检查驱魔香
	VOID CheckExorcism() CONST;

	// 检查道道道
	VOID CheckDaoDaoDao() CONST;
private:
	CPersonAttribute _PersonAttribute;
	
};



#endif // !__GITASKTAO_GAMEDLL_CORE_FEATURE_CHECK_STATUSCHECK_H__
