#include "stdafx.h"
#include "KillMobsterTask.h"
#include <MyTools/Log.h>
#include <MyTools/TimeTick.h>
#include "ObjectFunction.h"

#define _SELF L"KillMobsterTask.cpp"
BOOL CKillMobsterTask::Run()
{
	g_IsRuning = TRUE;
	int nExixstTalkMenuDlgCount = 0;


	auto wsPersonName = _PersonAttribute.GetName();
	while (g_IsRuning)
	{
		auto emPersonStatus = _PersonAttribute.GetPersonStatus();
		if (emPersonStatus == CPersonAttribute::em_PersonStatus::War)
		{
			_BattleAction.Fight();

			// 续自动战斗
			CObjectFunction::GetInstance().RefreshStaticMapGameUi();
			_BattleAction.ContinueAutoFight();
			continue;
		}
		else if (emPersonStatus == CPersonAttribute::em_PersonStatus::VerCode)
		{
			LOG_C_D(L"出现验证码答题……");
			::Sleep(1000);
			continue;
		}

		/*if (wsPersonName != L"大漠似雪") // 队友操作
		{
			::Sleep(1000);
			continue;
		}*/


		CObjectFunction::GetInstance().RefreshStaticMapGameUi();

		_StatusCheck.CheckDaoDaoDao();
		if (ExistTask())
		{
			::Sleep(1000);
			continue;
		}

		auto pTalkMenuDlg = CObjectFunction::GetInstance().FindGameUi_For_StaticMap_By_MapKey(L"TalkMenuDlg");
		if (pTalkMenuDlg == nullptr || !pTalkMenuDlg->IsShow())
		{
			::Sleep(1000);
			continue;
		}

		LOG_C_D(L"发现Npc对话框! Name=%s, IsShow=%X, Obj=%X", pTalkMenuDlg->GetName().c_str(), pTalkMenuDlg->IsShow(), pTalkMenuDlg->GetObj());
		// 10s 之内还存在的话...
		if (nExixstTalkMenuDlgCount++ <= 5)
		{
			::Sleep(2000);
			continue;
		}

		nExixstTalkMenuDlgCount = 0;
		LOG_C_D(L"10次任务应该是用完了~");
		auto pTalkContinueDlg = CObjectFunction::GetInstance().FindGameUi_For_StaticMap_By_MapKey(L"TalkMenuDlg.[我愿助将军除暴安良]");
		if (pTalkContinueDlg == nullptr)
		{
			LOG_C_E(L"除暴任务选项不见了……");
			continue;
		}

		LOG_C_D(L"继续除暴!");
		pTalkContinueDlg->ClickOption();
		::Sleep(1000);
	}

	LOG_C_D(L"停止除暴任务……");
	return TRUE;
}

BOOL CKillMobsterTask::ExistTask() CONST
{
	return _TaskExtend.ExistTask(L"为民除暴");
}
