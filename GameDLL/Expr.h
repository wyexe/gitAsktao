#ifndef __GITASKTAO_GAMEDLL_CORE_TEXT_EXPR_EXPR_H__
#define __GITASKTAO_GAMEDLL_CORE_TEXT_EXPR_EXPR_H__

#include "GameStruct.h"
#include <MyTools/CLExpression.h>
#include <MyTools/ClassInstance.h>

class CExpr : MyTools::CExprFunBase, public MyTools::CClassInstance<CExpr>
{
public:
	CExpr();
	virtual ~CExpr();

	virtual VOID Release();

	virtual std::vector<MyTools::ExpressionFunPtr>& GetVec();

private:
	virtual VOID Help(CONST std::vector<std::wstring>& VecParm);

	virtual VOID PrintUi(CONST std::vector<std::wstring>&);

	virtual VOID WatchNewUi(CONST std::vector<std::wstring>& VecParam);

	virtual VOID Test(CONST std::vector<std::wstring>&);

	virtual VOID PrintMonster(CONST std::vector<std::wstring>&);

	virtual VOID PrintBag(CONST std::vector<std::wstring>&);

	virtual VOID ScanBase(CONST std::vector<std::wstring>&);

	virtual VOID PrintNpc(CONST std::vector<std::wstring>&);

	virtual VOID PrintTask(CONST std::vector<std::wstring>&);

	virtual VOID Start(CONST std::vector<std::wstring>&);

	virtual VOID Stop(CONST std::vector<std::wstring>&);
};


#endif // !__GITASKTAO_GAMEDLL_CORE_TEXT_EXPR_EXPR_H__
