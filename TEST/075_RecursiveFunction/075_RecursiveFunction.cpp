// 075_RecursiveFunction


#include <iostream>

int Count = 0;
void Test()
{
    // 왜 터질까?
    // 스택메모리를 그려보기
    // 스택메모리에 Test함수가 계속 쌓여간다
    // 스택메모리에 쌓여가다가 힙영역을 침범하는 순간 튕김
    // 그게 "Stack Overflow"라고 함
    // Test를 실행하기 위한 메모리 크기가 커질수록 빨리 터짐(오버플로우가 빨리 발생함)
    printf_s("%d\n", Count);
    ++Count;

    if (20 <= Count)
    {
        return;
    }
    Test();
}

int Test2()
{
    // 마지막에 리턴에다가 재귀를 거는 경우에는
    // 꼬리재귀라는 것이 될 가능성이 생김 << 컴파일러의 재량에 의해 for문이나 while문이 되어버릴 수 있음 (최적화를 위해)
    //     == inline과 유사함
    // 한번 찾아보기(그냥 대충 어떤 내용인지만)
    if (true)
    {
        return 20;
    }
return Test2();
}
int main()
{
    Test();
}
