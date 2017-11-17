#ifndef __GITASKTAO_GAMEDLL_CORE_OBJECT_TEAM_TEAMATTRIBUTE_H__
#define __GITASKTAO_GAMEDLL_CORE_OBJECT_TEAM_TEAMATTRIBUTE_H__

#include <MyTools/ToolsPublic.h>

class CTeamAttribute
{
public:
	CTeamAttribute() = default;
	~CTeamAttribute() = default;

	UINT GetTeamMemberCount() CONST;

	BOOL IsCaptain() CONST;
private:

};



#endif // !__GITASKTAO_GAMEDLL_CORE_OBJECT_TEAM_TEAMATTRIBUTE_H__
