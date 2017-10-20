#include "stdafx.h"
#include "GameVariable.h"

DWORD CValueVariable::GetEmptyValue() CONST throw()
{
	return 0;
}

std::wstring CTextVariable::GetEmptyValue() CONST throw()
{
	return std::wstring();
}
