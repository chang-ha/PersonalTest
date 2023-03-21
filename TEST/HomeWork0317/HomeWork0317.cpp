#include <iostream>

// 영어만 씁니다.
// 문자열을 넣어주면 글자 개수를 알아냅니다.
// 0을 포함할지 아닐지는 스스로 정하세요
int StringCount(const char* _String)
{
    int String_Length = 0;
    char Value = _String[0];
    while (Value != 0)
    {
        String_Length += 1;
        Value = _String[String_Length];
    }
    return String_Length;
}

char TrimDelete(char* _String)
{
    char* String = _String;
    char Value = *String;
    while (Value != 0)
    {
        Value = *String;
        if (Value == ' ')
        {
            int Location = 0;
            while (String[Location] != 0)
            {
                String[Location] = String[Location +1];
                ++Location;
            }
        }
        else
        {
            String += 1;
        }
    }
    return *_String;
}

int StringToInt(const char* _String)
{
    const char* String = _String;
    int Value = 0;
    while (*String != 0)
    {
        Value = Value * 10 + (*String - '0');
        ++String;
    }
    return Value;
}

int main()
{
    // StringCount Test
    //printf_s("StringCount Test");
    //printf_s("\n");

    //int Count1 = StringCount("abcde");
    //printf_s("%d", Count1);
    //printf_s("\n");
    //int Count2 = StringCount("aaaa ggg sss        asjas001293---123-1--123-");
    //printf_s("%d", Count2);
    //printf_s("\n");
    //int Count3 = StringCount("ckask aksdoc askdkcklll");
    //printf_s("%d", Count3);
    //printf_s("\n");
    //int Count4 = StringCount("abcdefg hijklmn opqrstu vwxyz");
    //printf_s("%d", Count4);
    //printf_s("\n");
    //printf_s("\n");


    // TrimDelete Test
    printf_s("TrimDelete Test");
    printf_s("\n");

    char Arr0[1024] = "  a  b  c";
    TrimDelete(Arr0);
    printf_s(Arr0);
    printf_s("\n");
    char Arr1[1024] = "dkaskc    askdaskdk";
    TrimDelete(Arr1);
    printf_s(Arr1);
    printf_s("\n");
    char Arr2[1024] = " a b c d e f g";
    TrimDelete(Arr2);
    printf_s(Arr2);
    printf_s("\n");
    char Arr3[1024] = "a b c d e f g";
    TrimDelete(Arr3);
    printf_s(Arr3);
    printf_s("\n");
    char Arr4[1024] = "                           ";
    TrimDelete(Arr4);
    printf_s(Arr4);
    printf_s("\n");
    printf_s("\n");


    // StringToInt Test
 /*   printf_s("StringToInt Test");
    printf_s("\n");

    int RValue0 = StringToInt("1234");
    printf_s("%d", RValue0);
    printf_s("\n");
    int RValue1 = StringToInt("0043200");
    printf_s("%d", RValue1);
    printf_s("\n");
    int RValue2 = StringToInt("4523312");
    printf_s("%d", RValue2);
    printf_s("\n");
    int RValue3 = StringToInt("432231");
    printf_s("%d", RValue3);
    printf_s("\n");
    int RValue4 = StringToInt("002147483647");
    printf_s("%d", RValue4);
    printf_s("\n");*/

}

