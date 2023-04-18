// 019_Inline


#include <iostream>

inline void Test()
{
    printf_s("Function");
}


int main()
{
    // inline
    // inline은 함수에 붙일 수 있다.
    // inline은 최적화 할 수 있으면 해달라는뜻 = 내부 내용을 복사해서 메인에 붙여넣는 느낌
    // 컴파일러 판단에 따라 inline 불가능 할 수도 있음.
    // 함수를 만들면 스택을 더 만들고 메모리를 차지 하기 때문에 일을 더 하는 것을 방지 (그냥 조금이라도 빠르게 하려고, 가능하면 해줘 ^^)
    // 항상 빨라지지는 않지만 대부분 빨라짐, 대부분 붙이는게 좋음
}
