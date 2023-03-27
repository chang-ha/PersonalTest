// 금일 강의 내용 : Break and Continue

#include <iostream>
void BreakandContinue()
{
    // Break and Continue
    {
        while (true)
        {
            for (int i = 0; i < 100; i++)
            {
                if (i >= 50)
                {
                    // switch문의 break와는 다름
                    // 반복문에서의 break는 가장 가까운 반복문을 탈출한다.
                    // for문을 탈출
                    break;
                }
                printf_s("%d\n", i);
            }
            // while문을 탈출
            break;
        }
    }

    {
        for (int i = 0; i < 100; i++)
        {
            if (i % 2 == 0)
            {
                // 짝수면 continue << 홀수만 출력하는 함수
                continue; // 가장 가까운 반복문의 조건문으로 바로 이동한다.
            }
            printf_s("%d\n", i);
        }
    }
}
int main()
{
}
