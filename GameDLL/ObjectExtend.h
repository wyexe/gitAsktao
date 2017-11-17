#ifndef __GITASKTAO_GAMEDLL_CORE_OBJECT_OBJECTEXTEND_H__
#define __GITASKTAO_GAMEDLL_CORE_OBJECT_OBJECTEXTEND_H__

#include <map>
#include <mutex>
#include <MyTools/ClassInstance.h>
#include "GameUi.h"
#include "Monster.h"
#include "BagItem.h"
#include "PetObject.h"
#include "TaskObject.h"
#include "NpcObject.h"

class CObjectExtend
{
public:
	CObjectExtend() = default;
	~CObjectExtend() = default;

	// 怪物遍历
	UINT GetVecMonster(_Out_ std::vector<CMonster>& VecMonster) CONST;

	// UI遍历
	UINT GetGameUiList(_Out_ std::map<std::wstring, CGameUi>& GameUiList) CONST;

	//
	BOOL FindValue_By_Key_In_GameTree(_In_ DWORD dwHead, _In_ CONST std::wstring& wsKey, _Out_ std::wstring& wsValue) CONST;

	//
	UINT GetVecBagItem(_Out_ std::vector<CBagItem>& VecBagItem, _In_ std::function<BOOL(CONST CBagItem&)> FilterPtr) CONST;

	//
	UINT GetVecPet(_Out_ std::vector<CPetObject>& VecPet, _In_ std::function<BOOL(CONST CPetObject&)> FilterPtr) CONST;

	//
	UINT GetVecTask(_Out_ std::vector<CTaskObject>& VecTask, _In_ std::function<BOOL(CONST CTaskObject&)> FilterPtr) CONST;

	//
	UINT GetVecNpc(_Out_ std::vector<CNpcObject>& VecNpc, _In_ std::function<BOOL(CONST CNpcObject&)> FilterPtr) CONST;
private:
	//
	VOID TraverseGameUi(_In_ DWORD dwNode, _Out_ std::vector<DWORD>& VecGameUiNode) CONST;

	//
	template<typename T>
	UINT TraverseObject(_In_ DWORD dwNode, _In_ DWORD dwOffset, _Out_ std::vector<T>& VecNode, _In_ std::function<BOOL(CONST T&)> FilterPtr) CONST
	{
		DWORD dwHead = ReadDWORD(ReadDWORD(ReadDWORD(dwNode) + 0x14 + 0x4) + 0x4);

		std::queue<DWORD> QueNode;
		QueNode.push(dwHead);

		int nCount = 0;
		while (!QueNode.empty() && ++nCount < 1000)
		{
			auto dwAddr = QueNode.front();
			QueNode.pop();

			
			// 广度优先   深度优先怕递归……
			if (ReadBYTE(dwAddr + 0x15) == 0)
			{
				if (ReadDWORD(dwAddr + dwOffset) != 0)
				{
					T itm(dwAddr);
					if (FilterPtr == nullptr)
					{
						VecNode.push_back(itm);
					}
					else if (FilterPtr(itm))
					{
						VecNode.push_back(itm);
						return 1;
					}
				}

				QueNode.push(ReadDWORD(dwAddr + 0x0));
				QueNode.push(ReadDWORD(dwAddr + 0x8));
			}
		}
		return VecNode.size();
	}
private:
	virtual VOID AbstractMethod() = NULL;

	CObjectExtend(CONST CObjectExtend&) = delete;
	CObjectExtend& operator =(CONST CObjectExtend&) = delete;
};



#endif // !__GITASKTAO_GAMEDLL_CORE_OBJECT_OBJECTEXTEND_H__
