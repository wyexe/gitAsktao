#ifndef __GITASKTAO_GAMEDLL_CORE_COMMON_GAMESTRUCT_H__
#define __GITASKTAO_GAMEDLL_CORE_COMMON_GAMESTRUCT_H__


#define UI遍历基址			0xD91460
#define UIName偏移			0x94
#define UI遍历偏移1			0x1E4
#define 人物HP偏移			0x1F0
#define 人物MAXHP偏移		0x1E8
#define UI文本偏移			0xC
#define UIEDIT偏移			0x1E0
#define UI换线TEXT偏移		0x29C
#define 怪物名字偏移			0x16C
#define 怪物ID偏移			0x8
#define 怪物遍历基址			0xD90F68
#define 怪物遍历偏移			0x2A0
#define 当前地图基址			0xD91498
#define 是否战斗中基址		0xD97D44
#define 人物战斗菜单UI偏移	0x40
#define 队友HP偏移			0x3F8
#define 队友MAXHP偏移		0x3FC
#define 人物属性基址			0xD97F74
#define 人物属性偏移			0xE4

#define ReadDWORD(Addr) MyTools::CCharacter::ReadDWORD(Addr)
#define ReadBYTE(Addr)  MyTools::CCharacter::ReadBYTE(Addr)

enum class em_VariableName
{

};

struct Point
{
	DWORD X, Y;

	Point()
	{
		X = Y = NULL;
	}

	Point(_In_ DWORD dwX, _In_ DWORD dwY) : X(dwX), Y(dwY)
	{

	}

	bool operator == (CONST Point& Point_) CONST
	{
		return this->X == Point_.X && this->Y == Point_.Y;
	}

	bool operator != (CONST Point& Point_) CONST
	{
		return this->X != Point_.X || this->Y != Point_.Y;
	}
};

#endif // !__GITASKTAO_GAMEDLL_CORE_COMMON_GAMESTRUCT_H__
