#include <string.h>
#include <stdlib.h>
#include "InfixToPostfix.h" // for Calling 'ConvToRPNExp()' func
#include "PostCalculator.h" // for Calling 'EvalRPNexp()' func

int EvalInfixExp(char exp[])
{
    int len = strlen(exp);
    int ret;
    char * expcpy = (char*)malloc(len+1);   // 문자열 저장공간 마련
    strcpy(expcpy, exp);                    // exp를 expcpy에 복사

    ConvToRPNExp(expcpy);           // 후위 표기법의 수식으로 변환
    ret = EvalInfixExp(expcpy);     // 변환된 수식의 계산

    free(expcpy);       // 문자열 저장공간 해제
    return ret;         // 계산결과 반환
}