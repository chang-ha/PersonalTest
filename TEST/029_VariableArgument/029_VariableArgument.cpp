﻿// 029_VariableArgument


void VarFunction(int _1, ...)
{
    int* Ptr = &_1;

    int Value0 = Ptr[0];
    int Value1 = Ptr[2];
    int Value2 = Ptr[4];

    int a = 0;
}

void VarFunction64(__int64 _1, ...)
{
    __int64* Ptr = &_1;

    __int64 Value0 = Ptr[0];
    __int64 Value1 = Ptr[1];
    __int64 Value2 = Ptr[2];

    int a = 0;
}

void VarFunctionchr(char _1, ...)
{
    char* Ptr = &_1;

    char Value0 = Ptr[0];
    char Value1 = Ptr[8];
    char Value2 = Ptr[16];

    int a = 0;
}
int main()
{
    // printf_s 인자 마지막에 ... <<<< 가변인자 (Variableargument)
    // 인자의 갯수가 제한이 없고, 자료형도 상관없고, 섞어서 쓸 수 있음
    // 어떤 특성을 이용한 것인가??
    // 함수의 인자의 주소값은 붙어있음
    // 인자의 주소값은 8바이트 씩 떨어져 있음 (포인터, 주소값은 8바이트로 되어있음)
    // 그래서 인자가 몇 개 인지 알면 주소값을 알 수 있어서 각각의 인자에 접근할 수 있음
    // VarFunction(1, 2, 3, 4, 5, 6);
    // VarFunction("1", "2", "3");
    // VarFunction(1, 2, "3", 4, 5, "6");

    VarFunction(1, 2, 3);
    VarFunction64(4, 5, 6);
    VarFunctionchr('a', 'b', 'c');
}
