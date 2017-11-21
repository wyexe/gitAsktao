#include "stdafx.h"
#include "AskScanBase.h"
#include <MyTools/Log.h>


#define Ask_Client				L"asktao.mod"
#define _SELF L"ScanBase.cpp"

VOID CAskScanBase::Start() CONST
{
	DWORD dwBase = 0x0;
	DWORD dwCALL = 0x0;
	DWORD dwAddr = 0x0;
	DWORD dwClient = (DWORD)::GetModuleHandleW(L"asktao.mod");

	// UI遍历基址
	dwBase = MyTools::CLSearchBase::FindBase("B90800000033C0F3??7509A1", 0x64EF2E - 0x64EF39, 1, 0, Ask_Client);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	UI遍历基址	0x%X", dwBase);

	// 怪物遍历基址
	dwBase = MyTools::CLSearchBase::FindBase("8B????????????0100000033??E8", 0x4E1FE2 - 0x4E1FE2, 2, 0, Ask_Client);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	怪物遍历基址	0x%X", dwBase);

	// 怪物遍历偏移
	dwBase = MyTools::CLSearchBase::FindBase_ByCALL("8B????????????0100000033??E8", 0x4E1FE2 - 0x4E1FEF, dwClient, 1, 0, Ask_Client, 0x5 + 0x2);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	怪物遍历偏移	0x%X", dwBase);

	// 当前地图基址
	dwBase = MyTools::CLSearchBase::FindBase("680001000068????????8B", 0x5FB4B6 - 0x5FB4BB, 1, 0, Ask_Client);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	当前地图基址	0x%X", dwBase);

	// 是否战斗中基址
	dwBase = MyTools::CLSearchBase::FindBase("680001000068????????8B", 0x5FB4B6 - 0x5FB4D7, 2, 0, Ask_Client);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	是否战斗中基址	0x%X", dwBase);

	// 队友HP偏移
	dwBase = MyTools::CLSearchBase::FindBase("03??39??????????75??39", 0x4E49E9 - 0x4E49EB, 2, 0, Ask_Client);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	队友HP偏移	0x%X", dwBase);

	// 队友MAXHP偏移
	dwBase = MyTools::CLSearchBase::FindBase("03??39??????????75??39", 0x4E49E9 - 0x4E49F3, 2, 0, Ask_Client);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	队友MAXHP偏移	0x%X", dwBase);

	// 人物属性基址
	dwBase = MyTools::CLSearchBase::FindBase("8B??E8????????8B??????????8B??A1????????8B", 0x5D6E44 - 0x5D6E4B, 2, 0, Ask_Client);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	人物属性基址	0x%X", dwBase);

	// 人物属性偏移
	dwBase = MyTools::CLSearchBase::FindBase("8B??8B??????????FF??8B????????????E8????????33", 0x91316B - 0x91316D, 2, 0, Ask_Client);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	人物属性偏移	0x%X", dwBase);

	// 线路基址
	dwBase = MyTools::CLSearchBase::FindBase("A3????????E8??????????B9????????E8", 0x4F83D7 - 0x4F83E2, 1, 0, Ask_Client);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	线路基址	0x%X", dwBase);

	// 背包基址
	dwBase = MyTools::CLSearchBase::FindBase("85??89??24??????85??????8b", 0x45BEFD - 0x45BED3, 2, 0, Ask_Client);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	背包基址	0x%X", dwBase);

	// 发包CALL
	dwAddr = MyTools::CLSearchBase::FindAddr("81??2444000074??E8????????F6", 0x7138C5 - 0x713890, 0, Ask_Client);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	发包CALL	0x%X", dwAddr);

	// 怪物攻击ID虚函数偏移
	dwBase = MyTools::CLSearchBase::FindBase("8B??8B??????000068????????6A0068????????68", 0x4E75B6 - 0x4E75B8, 2, 0, Ask_Client);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	怪物攻击ID虚函数偏移	0x%X", dwBase);

	// 战斗CALL
	dwCALL = MyTools::CLSearchBase::FindCALL("8B??8B??????000068????????6A0068????????68", 0x4E75B6 - 0x4E75DE, dwClient, 1, 0, Ask_Client);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	战斗CALL	0x%X", dwCALL);

	// UI_Name虚函数偏移
	dwBase = MyTools::CLSearchBase::FindBase("8B??8B????8B??FF??EB03", 0x46E252 - 0x46E254, 2, 0, Ask_Client, 0xFF);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	UI_Name虚函数偏移	0x%X", dwBase);

	// UI遍历偏移1
	dwBase = MyTools::CLSearchBase::FindBase("E9????????8B??????00008B??????00008B??24", 0x46EB49 - 0x46EB4E, 2, 0, Ask_Client);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	UI遍历偏移1	0x%X", dwBase);

	// 人物MAXHP偏移
	dwBase = MyTools::CLSearchBase::FindBase("8B??24??39??????0000750839", 0x4B8F32 - 0x4B8F36, 2, 0, Ask_Client);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	人物MAXHP偏移	0x%X", dwBase);

	// 人物战斗UI偏移
	dwBase = MyTools::CLSearchBase::FindBase("F7??????00000001000074088D", 0x45D25E - 0x45D26A, 2, 0, Ask_Client, 0xFF);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	人物战斗UI偏移	0x%X", dwBase);

	// 怪物名字偏移
	dwBase = MyTools::CLSearchBase::FindBase("E8????????6A0068????????8B??E8????????83??01F7", 0x70B5AC - 0x70B5A5, 2, 0, Ask_Client);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	怪物名字偏移	0x%X", dwBase);

	// 走路CALL基址
	dwBase = MyTools::CLSearchBase::FindBase("740DF6??08750CF7", 0x516886 - 0x516872, 1, 0, Ask_Client);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	走路CALL基址	0x%X", dwBase);

	// 走路基址
	dwBase = MyTools::CLSearchBase::FindBase("740DF6??08750CF7", 0x516886 - 0x5168AD, 2, 0, Ask_Client);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	走路基址	0x%X", dwBase);

	// 走路偏移
	dwBase = MyTools::CLSearchBase::FindBase("740DF6??08750CF7", 0x516886 - 0x5168B4, 2, 0, Ask_Client);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	走路偏移	0x%X", dwBase);

	// UI是否显示偏移
	dwBase = MyTools::CLSearchBase::FindBase("6A0068????????8B??E8????????6A0068????????8B??89??????0000E8????????6A00??68", 0x7D55D8 - 0x7D55EF, 2, 0, Ask_Client);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	UI是否显示偏移 0x%X", dwBase);

	// 鼠标点击CALL
	dwBase = MyTools::CLSearchBase::FindCALL("6A0068????????8BCEE8????????5E59C2", 0x44D199 - 0x44D1A2, dwClient, 1, 0, Ask_Client);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	鼠标点击CALL	0x%X", dwBase);

	// 游戏检测基址
	dwBase = MyTools::CLSearchBase::FindBase_ByCALL("81??2444000074??E8????????F6", 0x7138C5 - 0x7138CD, dwClient, 0x1, 0, Ask_Client, 1);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	游戏检测基址	0x%X", dwBase);

	// 寻路CALL
	dwBase = MyTools::CLSearchBase::FindCALL("E8????????E9????????68000200008D??24????????8B", 0x464FE5 - 0x464FE5, dwClient, 1, 0, Ask_Client);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	寻路CALL	0x%X", dwBase);

	// 寻路Buffer偏移
	dwBase = MyTools::CLSearchBase::FindBase("C7????010000008B??????00008D", 0x461771 - 0x461778, 2, 0, Ask_Client);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	寻路Buffer偏移	0x%X", dwBase);

	// 宠物基址
	dwBase = MyTools::CLSearchBase::FindBase("85??74??8B??24??85??74??8B??????????6A00", 0x90EC14 - 0x90EC07, 2, 0, Ask_Client);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	宠物基址	0x%X", dwBase);

	// 宠物出战ID偏移
	dwBase = MyTools::CLSearchBase::FindBase_ByCALL("85??74??8B??24??85??74??8B??????????6A00", 0x90FEB4 - 0x90FEAD, dwClient, 2, 0, Ask_Client, 0x2, 0xFF);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	宠物出战ID偏移	0x%X", dwBase);

	// 宠物补血基址
	dwBase = MyTools::CLSearchBase::FindBase("85??74??8B??24??85??74??8B??????????6A00", 0x90EC14 - 0x90EC20, 2, 0, Ask_Client);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	宠物补血基址	0x%X", dwBase);

	// 宠物补血CALL
	dwBase = MyTools::CLSearchBase::FindCALL("85??74??8B??24??85??74??8B??????????6A00", 0x90EC14 - 0x90EC2B, dwClient, 1, 0, Ask_Client);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	宠物补血CALL	0x%X", dwBase);

	// 任务遍历基址
	dwBase = MyTools::CLSearchBase::FindBase("68????????8B??E8????????8B????????????E8????????8D??24??C6", 0x6D237A - 0x6D2386, 2, 0, Ask_Client);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	任务遍历基址	0x%X", dwBase);

	// 任务遍历偏移
	dwBase = MyTools::CLSearchBase::FindBase("8B??8D??????????C7??????0000000000008B??043B", 0x6D0187 - 0x6D0189, 2, 0, Ask_Client);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	任务遍历偏移	0x%X", dwBase);

	// 队友名字UI偏移
	dwBase = MyTools::CLSearchBase::FindBase_ByCALL("C2??????????????8B????0C00000033??F3??75??6868020000", 0x00962235 - 0x96221E, dwClient, 1, 0, Ask_Client, 0x4B6A5F - 0x4B6A20 + 0x2);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	队友名字UI偏移	0x%X", dwBase);

	// 战斗状态基址
	dwBase = MyTools::CLSearchBase::FindBase("83C4??C3833D????????0175", 0x4434D2 - 0x4434D6, 2, 0, Ask_Client);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	战斗状态基址	0x%X", dwBase);

	// 队伍数量基址
	dwBase = MyTools::CLSearchBase::FindBase("A1????????83????00??8B??????A1", 0x9E3B40 - 0x9E3B40, 1, 0, Ask_Client);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	队伍数量基址	0x%X", dwBase);

	// 队伍数量偏移
	dwBase = MyTools::CLSearchBase::FindBase("A1????????83????00??8B??????A1", 0x9E3B40 - 0x9E3B45, 2, 0, Ask_Client, 0xFF);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	队伍数量偏移	0x%X", dwBase);

	// 遍历NPC基址
	dwBase = MyTools::CLSearchBase::FindBase("B801000000??C2????8B??????????8B??8B??????8B", 0x6B3257 - 0x6B3260, 2, 0, Ask_Client);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	遍历NPC基址	0x%X", dwBase);

	// NPC遍历偏移
	dwBase = MyTools::CLSearchBase::FindBase("83C4??C2????8B??????????8B????8D??????0000", 0x641011 - 0x641017, 2, 0, Ask_Client);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	NPC遍历偏移	0x%X", dwBase);

	// Npc选项菜单点击偏移
	dwBase = MyTools::CLSearchBase::FindBase("8A003C216A000F", 0x4A82D1 - 0x4A82E3, 2, 0, Ask_Client);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	Npc选项菜单点击偏移	0x%X", dwBase);

	// 人物补血基址
	dwBase = MyTools::CLSearchBase::FindBase("8B0D????????E8????????85C07407??01000000", 0x90DD66 - 0x90DD66, 2, 0, Ask_Client);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	人物补血基址	0x%X", dwBase);

	// 人物补血CALL
	dwBase = MyTools::CLSearchBase::FindCALL("8B0D????????E8????????85C07407??01000000", 0x90DD66 - 0x90DD6C, dwClient, 1, 0, Ask_Client);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	人物补血CALL	0x%X", dwBase);

	// 跳过对话CALL
	dwBase = MyTools::CLSearchBase::FindCALL("33??68FF0000008B??8D??????????????89", 0x7E968F - 0x7E96DC, dwClient, 1, 0, Ask_Client);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	跳过对话CALL	0x%X", dwBase);

	// ...
	dwBase = MyTools::CLSearchBase::FindBase("", 0x4E49E9 - 0x4E49F3, 2, 0, Ask_Client);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	...	0x%X", dwBase);

	// ...
	dwBase = MyTools::CLSearchBase::FindBase("", 0x4E49E9 - 0x4E49F3, 2, 0, Ask_Client);
	MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	...	0x%X", dwBase);


	//人物瞬移钩挂地址
	//dwAddr = MyTools::CLSearchBase::FindAddr("7d0983c0018985????????6a00", 0x005F9EDC - 0x005F9EED, 0, Ask_Client);
	//MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	人物瞬移钩挂地址	0x%X", dwAddr);
	
	//隐藏玩家CALL
	//dwCALL = MyTools::CLSearchBase::FindCALL("75078ad3e8????????83??0183??04", 0xB25 - 0xB29, dwClient, 1, 0, Ask_Client);
	//MyTools::CLog::GetInstance().Print(__FUNCTIONW__, _SELF, 0, LOG_TYPE_CONSOLE, MyTools::CLog::em_Log_Type_Debug, FALSE, L"#define	隐藏玩家CALL	0x%X", dwCALL);
}
