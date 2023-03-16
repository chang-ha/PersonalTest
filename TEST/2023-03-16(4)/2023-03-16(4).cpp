// 금일 강의 내용 : 포인터 랜덤 인덱스

#include <iostream>

void MyPrintf(char* _ptr)
{
    *_ptr = 'a';
}

void MyPrintf2(char* const _ptr)
{

}

int main()
{
    char Arr[10] = {};

    MyPrintf(Arr);

    // MyPrintf2("abcdefg"); << "abcdfeg" 는 상수여서 MyPrintf2의 인자와 안맞음 (Myprintf는 char*인자를 원하지만 "abcdefg"는 const char)

    const char* Ptr = "test print";
    // 포인터도 random index access 가능

    char Ch1 = Ptr[1];
    char Ch2 = Ptr[2];
    char Ch3 = Ptr[3];
    char Ch4 = Ptr[4];
    char Ch5 = Ptr[5];
    char Ch6 = Ptr[6];
    char Ch7 = Ptr[7];
    char Ch8 = Ptr[8];
    char Ch9 = Ptr[9];
    char Ch10 = Ptr[10];
    char Ch11 = Ptr[11];
    char Ch12 = Ptr[12];
    char Ch13 = Ptr[13];
    // "test print"를 벗어난 영역까지 접근이 가능해서 오류가 발생할 수 있음
}

