// 081_FunctionCallType


#include <iostream>
// 함수 호출 규약
// 4가지가 있는데
// 주로 쓰는건 2가지
// 1. __stdcall << 윈도우 함수에서 많이 사용함
// 2. __cdecl << 일반적인 전역함수 선언 시 
// 이를 명시해줄 일은 거의 없음

// 멤버함수는 thiscall이라는 규약을 사용합니다.

// 중요!!!
// 한 가지만 기억하면 된다
// "함수포인터 쓸 때" 
// 특정 호출규약이 함수앞에 명시되어 있으면
// 그걸 맞춰줘야함


// 전역함수를 만들면 기본적으로 __cdecl이 기본임
void /*__cdecl*/ Test0()
{

}

void __stdcall Test1()
{

}

void __cdecl Test2()
{

}

int main()
{

}