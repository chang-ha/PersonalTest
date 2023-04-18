// 018_Const


#include <iostream>
int main()
{
    {
        // 함수의 스택에서의 메모리 크기는 컴파일시 고정되어야 하기 때문.
        // 배열의 크기는 선언해줘야함
        // c++의 함수의 실행흐름을 만들기 위한 스택크기는 .exe파일에 이미 다 정의되어 있어야 한다.
        int Value[10] = {};

        // 아래는 불가능
        // int ArrSize = 20;
        // int Value[ArrSize] = {};

        // 특정 자료형앞에 Const 키워드를 붙이면 <= Const는 어느 자료형이든 붙일 수 있다.
        // 그 메모리의 비트적 상수화를 시킨다. <= 비트 하나도 바꿀수 없음
        const int Arrsize = 20;

        // Arrsize = 30; << 불가능 = 비트적 상수화를 시켰기 때문
        int Value2[Arrsize] = {};


        // 아래 내용은 쓸모없는 코드 << 컴파일러가 무시함(F9걸어도 무시함) << 컴파일러 최적화라고함
        "Testchar"; // << consst char[9] = 바꿀수 없는 상수라는 뜻
    }
}