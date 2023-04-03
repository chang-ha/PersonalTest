// 028_While


#include <iostream>
int main()
{
// 반복문중 While

//while (메모리영억, 조건문)
//{
//     실행코드
//}

// while (내부에는 ,를 통해서 여러가지 조건을 넣을 수 있습니다.)
// 무조건 가장 오른쪽에 있는 ,의 메모리영역의 값만을 조건으로 칩니다.

{
    // while (특정 메모리영역이 참인가 거짓인가?)
    // true, false도 아닌 참인가 거짓인가(0인가 0이아닌가)
    //while (printf_s("조건문\n"), true)
    //{
    //    printf_s("실행코드\n");
    //}
}

{
    // while문은 조건문 > 실행코드 > 조건문 > 실행코드 ...
    int Value = 5;
    printf_s("while\n");
    while (printf_s("조건문\n"), Value)
    {
        --Value;
        printf_s("실행코드\n");
    }
}

{
    // do while문은 실행코드 > 조건문 > 실행코드 > 조건문 ...
    int Value = 5;
    printf_s("do while\n");
    do
    {
        --Value;
        printf_s("실행코드\n");
    } while (printf_s("조건문\n"), Value);
}
}
