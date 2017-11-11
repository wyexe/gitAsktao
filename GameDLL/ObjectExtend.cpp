#include "stdafx.h"
#include "ObjectExtend.h"
#include <MyTools/Character.h>
#include <MyTools/Log.h>
#include <MyTools/CLEchoException.h>
#include "GameStruct.h"

#define _SELF L"ObjectExtend.cpp"
UINT CObjectExtend::GetGameUiList(_Out_ std::map<std::wstring, CGameUi>& GameUiList) CONST
{
	return MyTools::CLEchoException::GetInstance().InvokeFunc<UINT>(__FUNCTIONW__, [&] 
	{
		std::vector<DWORD> VecGameUiNode;
		TraverseGameUi(ReadDWORD(UI遍历基址), VecGameUiNode);

		for (auto& dwUiNodeBase : VecGameUiNode)
		{
			CGameUi GameUi(dwUiNodeBase);
			GameUiList.insert(std::make_pair(GameUi.GetName(), GameUi));

			// Child Ui
			std::vector<DWORD> VecChildGameUiNode;
			TraverseGameUi(GameUi.GetObj(), VecChildGameUiNode);
			for (auto& dwChildUiNodeBase : VecChildGameUiNode)
			{
				CGameUi ChildGameUi(dwChildUiNodeBase);

				auto wsMapKeyText = MyTools::CCharacter::MakeFormatText(L"%s.%s", GameUi.GetName().c_str(), ChildGameUi.GetName().c_str());
				GameUiList.insert(std::make_pair(wsMapKeyText, ChildGameUi));
			}
		}

		return GameUiList.size();
	});
}

BOOL CObjectExtend::FindPersonAttribute_By_Key(_In_ CONST std::wstring& wsKey, _Out_ std::wstring& wsValue) CONST
{
	return FindValue_By_Key_In_GameTree(ReadDWORD(ReadDWORD(ReadDWORD(人物属性基址) + 人物属性偏移 + 0x4 + 0x4) + 0x4), wsKey, wsValue);
}

BOOL CObjectExtend::FindItemAttribute_By_Key(_In_ CONST CBagItem& Item, _In_ CONST std::wstring& wsKey, _Out_ std::wstring& wsValue) CONST
{
	return FindValue_By_Key_In_GameTree(ReadDWORD(ReadDWORD(Item.GetObjAddr() + 0x4 + 0x4 + 0x4) + 0x4), wsKey, wsValue);
}

BOOL CObjectExtend::FindValue_By_Key_In_GameTree(_In_ DWORD dwHead, _In_ CONST std::wstring& wsKey, _Out_ std::wstring& wsValue) CONST
{
	std::string szKey = MyTools::CCharacter::UnicodeToASCII(wsKey);
	return MyTools::CLEchoException::GetInstance().InvokeFunc<BOOL>(__FUNCTIONW__, [szKey, &wsValue, dwHead]
	{
		std::queue<DWORD> QueNode;
		QueNode.push(dwHead);

		int nCount = 0;
		while (!QueNode.empty() && ++nCount < 1000)
		{
			auto dwAddr = QueNode.front();
			QueNode.pop();

			// 广度优先   深度优先怕递归……
			if (ReadBYTE(dwAddr + 0x45) == 0)
			{
				QueNode.push(ReadDWORD(dwAddr + 0x0));
				QueNode.push(ReadDWORD(dwAddr + 0x8));
				if (ReadBYTE(dwAddr + 0x10) != 0 && ReadBYTE(dwAddr + 0x10 + 0x10) != 0 && ReadBYTE(dwAddr + 0x10 + 0x10) < 32 && ReadBYTE(dwAddr + 0x2C) != 0)
				{
					CONST CHAR* pszKey = ReadBYTE(dwAddr + 0x10 + 0x14) == 0xF ? reinterpret_cast<CONST CHAR*>(dwAddr + 0x10) : reinterpret_cast<CONST CHAR*>(ReadDWORD(dwAddr + 0x10));

					if (szKey == "*")
					{
						CONST CHAR* pszValue = ReadBYTE(dwAddr + 0x2C + 0x14) == 0xF ? reinterpret_cast<CONST CHAR*>(dwAddr + 0x2C) : reinterpret_cast<CONST CHAR*>(ReadDWORD(dwAddr + 0x2C));
						LOG_C_D(L"pszKey=%s,pszValue=%s", MyTools::CCharacter::ASCIIToUnicode(pszKey).c_str(), MyTools::CCharacter::ASCIIToUnicode(pszValue).c_str());
					}
					else if (strcmp(szKey.c_str(), pszKey) == 0)
					{
						CONST CHAR* pszValue = ReadBYTE(dwAddr + 0x2C + 0x14) == 0xF ? reinterpret_cast<CONST CHAR*>(dwAddr + 0x2C) : reinterpret_cast<CONST CHAR*>(ReadDWORD(dwAddr + 0x2C));

						wsValue = MyTools::CCharacter::ASCIIToUnicode(std::string(pszValue));
						return TRUE;
					}
					
				}
			}
		}

		return FALSE;
	});
}

UINT CObjectExtend::GetVecBagItem(_Out_ std::vector<CBagItem>& VecBagItem, _In_ std::function<BOOL(CONST CBagItem&)> FilterPtr) CONST
{
	DWORD dwHead = ReadDWORD(ReadDWORD(ReadDWORD(背包基址) + 0x14 + 0x4) + 0x4);

	std::queue<DWORD> QueNode;
	QueNode.push(dwHead);

	int nCount = 0;
	while (!QueNode.empty() && ++nCount < 1000)
	{
		auto dwAddr = QueNode.front();
		QueNode.pop();

		if (ReadDWORD(dwAddr + 0xC) != 0)
		{
			CBagItem BagItem(dwAddr);
			if (FilterPtr == nullptr)
			{
				VecBagItem.push_back(BagItem);
			}
			else if (FilterPtr(BagItem))
			{
				VecBagItem.push_back(BagItem);
				return 1;
			}
		}
		

		// 广度优先   深度优先怕递归……
		if (ReadBYTE(dwAddr + 0x15) == 0)
		{
			QueNode.push(ReadDWORD(dwAddr + 0x0));
			QueNode.push(ReadDWORD(dwAddr + 0x8));
		}
	}
	return VecBagItem.size();
}

UINT CObjectExtend::GetVecMonster(_Out_ std::vector<CMonster>& VecMonster) CONST
{
	VecMonster.clear();

	DWORD dwRoot = ReadDWORD(ReadDWORD(怪物遍历基址) + 怪物遍历偏移);
	for (UINT i = 0;i < 20; ++i)
	{
		DWORD dwNodeBase = ReadDWORD(dwRoot + i * 4);
		if (ReadBYTE(dwNodeBase + 0x4) == 0)
			continue;

		VecMonster.emplace_back(static_cast<DWORD>(i), dwNodeBase);
	}
	return VecMonster.size();
}

VOID CObjectExtend::TraverseGameUi(_In_ DWORD dwNode, _Out_ std::vector<DWORD>& VecGameUiNode) CONST
{
	DWORD dwLinkTableHead = ReadDWORD(dwNode + UI遍历偏移1);
	for (DWORD dwObjectAddr = ReadDWORD(dwLinkTableHead);; dwObjectAddr = ReadDWORD(dwObjectAddr))
	{
		if (dwObjectAddr == dwLinkTableHead)
			break;

		if (ReadDWORD(dwObjectAddr + 0x8) == 0)
			break;

		VecGameUiNode.push_back(dwObjectAddr);
	}
}
