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

	virtual VOID Test(CONST std::vector<std::wstring>& VecParm);
};


#endif // !__GITASKTAO_GAMEDLL_CORE_TEXT_EXPR_EXPR_H__
