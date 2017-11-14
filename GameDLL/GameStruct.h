#ifndef __GITASKTAO_GAMEDLL_CORE_COMMON_GAMESTRUCT_H__
#define __GITASKTAO_GAMEDLL_CORE_COMMON_GAMESTRUCT_H__


#define UI遍历基址			0xD97120
#define 怪物遍历基址			0xD96C28
#define 怪物遍历偏移			0x2A0
#define 当前地图基址			0xD97158
#define 是否战斗中基址		0xD9DA0C
#define 队友HP偏移			0x3FC
#define 队友MAXHP偏移		0x400
#define 人物属性基址			0xD9ABB4
#define 人物属性偏移			0xE4
#define 线路基址				0xD94CCC
#define 背包基址				0xD9733C
#define 发包CALL				0x713890
#define 怪物攻击ID虚函数偏移 0xE4
#define 战斗CALL				0x4E1D60
#define UI_Name虚函数偏移	0x38
#define UI遍历偏移1			0x1E4
#define 人物MAXHP偏移		0x1E8
#define 人物战斗菜单UI偏移	0x40
#define 怪物名字偏移			0x168
#define 走路CALL基址			0xD9ABB4
#define 走路基址				0xD9ABB4
#define 走路偏移				0x198
#define 鼠标点击CALL			0x45CE60
#define UI是否显示偏移		0x194
#define 游戏检测基址			0xD9DE44
#define 寻路CALL				0x461680
#define 寻路Buffer偏移		0x1E0
#define 宠物基址				0xD99E40
#define 宠物出战ID偏移		0x48
#define 宠物补血基址			0xD963F0
#define 宠物补血CALL			0x53E950
#define 任务遍历基址			0xD9A0D0
#define 任务遍历偏移			0x94


///----基本不变的偏移-------------------------
#define 战斗中是否队友偏移	0x54
#define 人物HP偏移			人物MAXHP偏移 + 0x8
#define UI文本偏移			0xC
#define UIEDIT偏移			0x1E0
#define 怪物ID偏移			0x8
#define 恢复VirtualProtect  0x77A40028
#define NTDLL地址			0x77A20000

#define ReadDWORD(Addr) MyTools::CCharacter::ReadDWORD(Addr)
#define ReadBYTE(Addr)  MyTools::CCharacter::ReadBYTE(Addr)

enum class em_VariableName
{
	NewPeekMessageAddr,
};

enum em_SkillId
{
	em_SkillId_金_金光乍现 = 0xB,
	em_SkillId_金_刀光剑影 = 0xC,
	em_SkillId_金_金虹贯日 = 0xD,
	em_SkillId_金_流光异彩 = 0xE,
	em_SkillId_金_流连忘返 = 0x15,
	em_SkillId_金_得意忘形 = 0x16,
	em_SkillId_金_如痴如醉 = 0x17,
	em_SkillId_金_如梦初醒 = 0x18,
	em_SkillId_金_天生神力 = 0x1F,
	em_SkillId_金_气冲斗牛 = 0x20,
	em_SkillId_金_九牛二虎 = 0x21,
	em_SkillId_金_如虎添翼 = 0x22,
	em_SkillId_力破千军	  = 0x1F5,
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
