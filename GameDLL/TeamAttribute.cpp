#include "stdafx.h"
#include "TeamAttribute.h"
#include <MyTools/Character.h>
#include "GameUi.h"
#include "ObjectFunction.h"

UINT CTeamAttribute::GetTeamMemberCount() CONST
{
	return ReadDWORD(ReadDWORD(队伍数量基址) + 队伍数量偏移);
}

BOOL CTeamAttribute::IsCaptain() CONST
{
	return FALSE;
}
