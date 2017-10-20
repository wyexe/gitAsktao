#ifndef __GITASKTAO_GAMEDLL_CORE_TEXT_RES_GAMEVARIABLE_H__
#define __GITASKTAO_GAMEDLL_CORE_TEXT_RES_GAMEVARIABLE_H__

#include "GameStruct.h"
#include <MyTools/ClassInstance.h>

class CValueVariable : public MyTools::CVariable<em_VariableName, DWORD>, public MyTools::CClassInstance<CValueVariable>
{
public:
	CValueVariable() = default;
	~CValueVariable() = default;

private:
	virtual DWORD GetEmptyValue() CONST throw() override;
};


class CTextVariable : public MyTools::CVariable<em_VariableName, std::wstring>, public MyTools::CClassInstance<CTextVariable>
{
public:
	CTextVariable() = default;
	~CTextVariable() = default;

private:
	virtual std::wstring GetEmptyValue() CONST throw() override;
};


#endif // !__GITASKTAO_GAMEDLL_CORE_TEXT_RES_VALUEVARIABLE_H__
